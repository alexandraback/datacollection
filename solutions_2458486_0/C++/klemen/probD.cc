#include <stdio.h>
#include <string.h>

#define MAXN 22
#define MAXK 220
#define MAXCHEST 50

int T = 0, N = 0, S = 0;

int chest[MAXN];
int key_nr[MAXN];
int keys[MAXN][MAXCHEST];
int start[MAXK];

char mem[1 << MAXN];
char next[1 << MAXN];

char solve(int mask) {
  if (mem[mask] >= 0)
    return mem[mask];
  char rv = 0;
  if (mask == ((1 << N) - 1)) {
    rv = 1;
  }
  else {
    int held[MAXK];
    memset(held, 0x00, sizeof(held));
    for (int i = 0; i < S; i++)
      held[start[i]]++;
    for (int i = 0, mm = mask; i < N; i++, mm >>= 1) {
      if ((mm & 0x1) == 0x1) {
        held[chest[i]]--;
        for (int j = 0; j < key_nr[i]; j++)
          held[keys[i][j]]++;
      }
    }

    for (int i = 0, mm = mask; i < N; i++, mm >>= 1) {
      if ((mm & 0x1) == 0x0 && held[chest[i]]) {
        int nm = mask | (1 << i);
        if (solve(nm)) {
          next[mask] = i;
          rv = 1;
          break;
        }
      }
    }
  }
  return mem[mask] = rv;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    memset(mem, 0xFF, sizeof(mem));
    scanf("%d %d", &S, &N);
    for (int i = 0; i < S; i++)
      scanf("%d", &start[i]);
    for (int i = 0; i < N; i++) {
      scanf("%d", &chest[i]);
      scanf("%d", &key_nr[i]);
      for (int j = 0; j < key_nr[i]; j++) {
        scanf("%d", &keys[i][j]);
      }
    }

    char rv = solve(0);
    printf("Case #%d:", t + 1);
    if (rv == 1) {
      int mask = 0;
      while (mask != ((1 << N) - 1)) {
        int c = next[mask];
        printf(" %d", c + 1);
        mask |= 1 << c;
      }
    }
    else {
      printf(" IMPOSSIBLE");
    }
    printf("\n");
  }
}
