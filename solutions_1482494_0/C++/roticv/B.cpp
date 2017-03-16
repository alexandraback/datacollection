#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <queue>
#include <map>
#include <algorithm>

#define pii pair<int,int>
#define FOR(i,a,b) for (int i = a; i <= (int) b; i++)
#define FOD(i,a,b) for (int i = a; i >= (int) b; i--)

using namespace std;

int N, tc;
int a[1005], b[1005], D[10005];
int dp[59050];
int pow[15];

int main(){
  scanf("%d",&tc);
  pow[0] = 1;
  for (int i = 1; i < 15; i++) pow[i] = 3 * pow[i-1];
  for (int TC = 1; TC <= tc; TC++){
    scanf("%d ",&N);
    for (int i = 0; i < N; i++) scanf("%d %d ",a+i, b+i);
    memset(dp, 0x7f, sizeof dp);
    dp[0] = 0;
    for (int bit = 0; bit < pow[N]; bit++) if (dp[bit] != 0x7f7f7f7f) {
      int stars = 0, tmp = bit;
      for (int i = 0; i < N; i++) {
        D[i] = tmp % 3;
        stars += D[i];
        tmp /= 3;
      }
      for (int i = 0; i < N; i++) {
        if (D[i] < 2 && stars >= b[i]) {
          int c = D[i] * pow[i];
          int d = bit-c+2*pow[i];
          dp[d] = min(dp[bit]+1, dp[d]);
        }
        if (D[i] < 1 && stars >= a[i]) {
          int c = D[i] * pow[i];
          int d = bit-c+pow[i];
          dp[d] = min(dp[bit]+1, dp[d]);
        }
      }
      //printf("bits: %d stars: %d\n", bit, stars);
    }
    if (dp[pow[N]-1] == 0x7f7f7f7f) printf("Case #%d: Too Bad\n", TC);
    else printf("Case #%d: %d\n", TC, dp[pow[N]-1]);
  }
  return 0;
}

