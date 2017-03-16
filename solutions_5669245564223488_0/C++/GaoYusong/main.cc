#include <stdio.h>
#include <string.h>

using namespace std;

char cars[110][110];
int lens[110];
int masks[110];
int ans = 0;
const int MOD = 1000000007;
int L[110], R[110];

void dfs(int cur, int n, char last, int mask)
{
  if (cur == n) {
    ans++;
    return;
  }

  //printf("%d %c %d\n", cur, last, mask);

  for (int i = R[0]; i != 0; i = R[i]) {
    R[L[i]] = R[i];
    L[R[i]] = L[i];

    if (last == 0) {
      dfs(cur + 1, n, cars[i][lens[i] - 1], mask | (masks[i]));
    } else {
      int xx;
      if (last == cars[i][0]) {
        xx = (masks[i] ^ (1 << (cars[i][0] - 'a')));

      } else {
        xx = masks[i];
      }
      if (mask & xx) {
          
      } else {
        dfs(cur + 1, n, cars[i][lens[i] - 1], mask | xx);
      }

    }
    
    R[L[i]] = i;
    L[R[i]] = i;
  }

}

int generate(char *ss)
{
  int mask = 0;
  int len = strlen(ss);

  for (int i = 1; i <= len; i++) {
    if (i == len || ss[i] != ss[i - 1]) {
      int mm = (1 << (ss[i - 1] - 'a'));
      if (mask & mm) {
        return -1;
      }
      mask |= mm;
    }
  }
  return mask;
}
  

int main()
{
  int T;

  //freopen("input.txt", "r", stdin);
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);

  scanf("%d", &T);

  for (int cn = 1; cn <= T; cn++) {
    int n;
    scanf("%d", &n);
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      scanf("%s", cars[i]);
      masks[i] = generate(cars[i]);
      lens[i] = strlen(cars[i]);
      if (masks[i] == -1) {
        ok = false;
      }
    }


    for (int i = 0; i <= n; i++) {
      L[i] = i - 1;
      R[i] = i + 1;
    }
    ans = 0;
    L[0] = n;
    R[n] = 0;
    if (ok) {
      dfs(0, n, 0, 0);
    }
    printf("Case #%d: %d\n", cn, ans % MOD);
  }
  
  return 0;
}
