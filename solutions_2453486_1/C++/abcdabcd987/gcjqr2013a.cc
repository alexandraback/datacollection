#include <cstdio>

const int n = 4;
char map[n][n+1];
int T;
int solve()
{
  for (int i = 0; i < n; ++i)
  {
    int o = 0, x = 0;
    for (int j = 0; j < n; ++j)
      if (map[i][j] == 'T') ++o, ++x;
      else if (map[i][j] == 'O') ++o;
      else if (map[i][j] == 'X') ++x;
    if (x == 4) return 0;
    if (o == 4) return 1;
  }

  for (int j = 0; j < n; ++j)
  {
    int o = 0, x = 0;
    for (int i = 0; i < n; ++i)
      if (map[i][j] == 'T') ++o, ++x;
      else if (map[i][j] == 'O') ++o;
      else if (map[i][j] == 'X') ++x;
    if (x == 4) return 0;
    if (o == 4) return 1;
  }

  int o = 0, x = 0;
  for (int i = 0; i < n; ++i)
    if (map[i][i] == 'T') ++o, ++x;
    else if (map[i][i] == 'O') ++o;
    else if (map[i][i] == 'X') ++x;
  if (x == 4) return 0; else x = 0;
  if (o == 4) return 1; else o = 0;

  for (int i = 0; i < n; ++i)
    if (map[i][n-i-1] == 'T') ++o, ++x;
    else if (map[i][n-i-1] == 'O') ++o;
    else if (map[i][n-i-1] == 'X') ++x;
  if (x == 4) return 0;
  if (o == 4) return 1;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (map[i][j] == '.')
        return 3;
  return 2;
}
int main()
{
  scanf("%d", &T);
  for (int testcase = 1; testcase <= T; ++testcase)
  {
    for (int i = 0; i < n; ++i) scanf("\n%s", map[i]);
    const int res = solve();
    printf("Case #%d: ", testcase);
    if (res == 0) printf("X won\n");
    else if (res == 1) printf("O won\n");
    else if (res == 2) printf("Draw\n");
    else if (res == 3) printf("Game has not completed\n");
  }
}
