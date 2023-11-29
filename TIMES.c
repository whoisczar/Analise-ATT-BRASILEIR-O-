#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Gabriel Reis Pereira

void setar_nomes(FILE *aux, int c, char nomes[][20], int pontos[]) {
  if (c < 20 && !feof(aux)) {
    fscanf(aux, "\n%s %d", nomes[c], &pontos[c]);
    setar_nomes(aux, c + 1, nomes, pontos);
  }
}

void todos(char n[][20], int p[], int c) {
  if (c < 20) {
    printf("\n\t%s %d Pontos", n[c], p[c]);
    todos(n, p, c + 1);
  }
}

void maior(char n[][20], int p[], int c) {
  if (c < 5) {
    printf("\n\t%s %d Pontos", n[c], p[c]);
    maior(n, p, c + 1);
  }
}

void menor(char n[][20], int p[], int c) {
  if (c > 14) {
    printf("\n\t%s %d Pontos", n[c], p[c]);
    menor(n, p, c - 1);
  }
}

void diferenca(char n[][20], int p[], int c, int key, int pant) {

  if (c < 14) {
    if (c < 6) {
      if (key == 0) {
        key = 1;
        pant = p[c];
        printf("\n\n\t\tO time %s tem\n", n[c]);
        diferenca(n, p, c + 1, key, pant);
      } else {
        int diff = pant - p[c];
        printf("\n\t%d pontos a mais que o %s", diff, n[c]);
        diferenca(n, p, c + 1, key, pant);
      }
    }
  }

  else if (c >= 14 && c < 20) {
    if (c != 20) {
      if (c < 20 && key == 0) {
        key = 1;
        pant = p[c];

        if (c != 19) {
          printf("\n\n\t\tO time %s tem\n", n[c]);
          diferenca(n, p, c + 1, key, pant);
        }

      } else {
        int diff = pant - p[c];
        printf("\n\t%d pontos a mais que o %s", diff, n[c]);
        diferenca(n, p, c + 1, key, pant);
      }
    }
  }
}

void os10(char n[][20], int p[], int c) {
  if (c < 20) {
    if (c == 5) {
      c = 14;
    }
    printf("\n\n\t%d - %s %d", c + 1, n[c], p[c]);
    os10(n, p, c + 1);
  }
}

void printar(char n[][20], int p[], int c, int key) {

  if (key == -1) {
    printf("\n\t\t----------------TODOS OS TIMES----------------\n");
    todos(n, p, c);
    printf("\n\n\t\t----------------5 MAIORES----------------\n");
    maior(n, p, c);
    printf("\n\n\t\t----------------5 MENORES----------------\n");
    c = 19;
    menor(n, p, c);
    printf("\n\n\t\t-------------DIFERENÇA ENTRE OS 5 MAIORES "
           "TIMES-------------\n");
    c = 0;
    printar(n, p, c, key + 1);
  }

  else if (key < 5) {
    diferenca(n, p, key, 0, 0);
    printar(n, p, c + 1, key + 1);
  }

  else if (key == 5) {
    printf("\n\n\n\t\t----------------DIFERENÇA ENTRE OS 5 MENORES "
           "TIMES----------------\n");
    printar(n, p, 14, 14);
  }

  else if (key >= 14 && c != 20) {
    diferenca(n, p, c, 0, 0);
    printar(n, p, c + 1, key + 1);
  }

  if (key > 24) {
  }
}

int main() {
  FILE *aux = fopen("file.txt", "r");
  int c = 0;

  char nomes[20][20];
  int pontos[20];

  if (!aux) {
    printf("Erro! Arquivo não encontrado");
    exit(1);
  }

  setar_nomes(aux, 0, nomes, pontos);
  printar(nomes, pontos, c, -1);
  printf("\n\n\n\t\t----------------Lista dividida pela metade----------------"); 
os10(nomes, pontos, 0);
}
