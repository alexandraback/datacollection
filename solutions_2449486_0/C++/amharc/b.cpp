#include <cstdio>

int tab[100][100];

bool colok[100][105];
bool rowok[100][105];

int main() {
  int T;
  scanf("%d", &T);
  for(int tc = 1; tc <= T; ++tc) {
    int N, M;
    scanf("%d%d", &N, &M);
    bool isok = true;

    for(int i = 0; i < 100; ++i)
      for(int j = 0; j < 105; ++j)
        colok[i][j] = rowok[i][j] = 1;

    for(int i = 0; i < N; ++i)
      for(int j = 0; j < M; ++j) {
        scanf("%d", &tab[i][j]);
        rowok[i][tab[i][j] - 1] = 0;
        colok[j][tab[i][j] - 1] = 0;
      }

    for(int i = 0; i < 100; ++i)
      for(int j = 103; j >= 0; --j) {
        colok[i][j] &= colok[i][j + 1];
        rowok[i][j] &= rowok[i][j + 1];
      }

    for(int i = 0; i < N; ++i)
      for(int j = 0; j < M; ++j) {
        isok &= rowok[i][tab[i][j]] || colok[j][tab[i][j]];
      }

    printf("Case #%d: %s\n", tc, isok ? "YES" : "NO");
  }
}
