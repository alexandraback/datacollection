#include <cmath>
#include <algorithm>
#include <iomanip>
#include <algorithm>
#include <cstdio>

using namespace std;

char A[6][6];

inline bool check(char c)
{
  bool p = false;
  for (int i = 0; i < 4; i++) {
    p = false;
    for (int j = 0; j < 4; j++) {
      if (A[i][j] == c || A[i][j] == '.') p = true;
    }
    if (!p) return true;
  }
  for (int i = 0; i < 4; i++) {
    p = false;
    for (int j = 0; j < 4; j++) {
      if (A[j][i] == c || A[j][i] == '.') p = true;
    }
    if (!p) return true;
  }
  p = false;
  for (int i = 0; i < 4; i++) {
    if (A[i][i] == c || A[i][i] == '.') p = true;
  }
  if (!p) return true;
  p = false;
  for (int i = 0; i < 4; i++) {
    if (A[4-i-1][i] == c || A[4-i-1][i] == '.') p = true;
  }
  if (!p) return true;
  return false;
}

inline bool checkend()
{
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (A[i][j] == '.') return false;
    }
  }
  return true;
}

int main(void)
{
  int n;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  scanf("%d",&n);
  getchar();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        A[j][k] = getchar();
      }
      getchar();
    }
    printf("Case #%d: ", i+1);
    if (check('X')) puts("O won");
    else if (check('O')) puts("X won");
    else if (checkend()) puts("Draw");
    else puts("Game has not completed");
    getchar();
  }
  return 0;
}
