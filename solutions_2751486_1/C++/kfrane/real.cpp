#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long llint;

const int mxn = 1000000+5;
char niz[mxn];

inline bool kons(char zn) {
  if(zn == 'a' || zn == 'e' || zn == 'i' || zn == 'o' || zn == 'u') return 0;
  return 1;
}

int dp[mxn];
void solve() {
  int n;
  scanf("%s", niz);
  scanf("%d", &n);

  int k = strlen(niz), curr = 0;
  int prev_large = -1;
  llint sol = 0;
//  printf("DP ");
  for(int i = 0; i < k; i++) {
    if (kons(niz[i])) {
      curr++;

      if (curr >= n) {
        dp[i] = i - (n-1) + 1;
        prev_large = i;
      } else {
        if (prev_large >= 0) {
          dp[i] = dp[prev_large];
        } else {
          dp[i] = 0;
        }
      }
    } else {
      curr = 0;
      if (prev_large >= 0) {
        dp[i] = dp[prev_large];
      } else {
        dp[i] = 0;
      }
    }
    sol += dp[i];
//    printf("%d", dp[i]);
  }
//  printf("\n");

  printf ("%lld\n", sol);
}

int main() {
  int t;
  scanf("%d", &t);
  for(int i = 0; i < t; i++) {
    printf("Case #%d: ", i+1);
    solve();
  }

  return 0;
}
