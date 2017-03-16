#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void checkMin(T &a, T b) { if(b<a) a=b; }
template<typename T> inline void checkMax(T &a, T b) { if(a<b) a=b; }
#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for (int i=0;i<int(n);++i)
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

lint A, B, K;
lint dp[32][2][2][2];

lint dfs(int i, int a, int b, int k) {
  if (i == 31) {
    return a == 0 && b == 0 && k == 0;
  }
  lint &ans = dp[i][a][b][k];
  if (ans != -1LL) return ans;
  ans = 0;
  REP (ap, 2) {
    REP (bp, 2) {
      REP (kp, 2) {
        lint temp = dfs(i + 1, ap, bp, kp);
        REP (x, 2) {
          if (a == 0 && ap == 0 && x == ((A >> i) & 1)) {
          } else if (a == 1 && (ap == 1 || x < ((A >> i) & 1))) {
          } else {
            continue;
          }
          REP (y, 2) {
            if (b == 0 && bp == 0 && y == ((B >> i) & 1)) {
            } else if (b == 1 && (bp == 1 || y < ((B >> i) & 1))) {
            } else {
              continue;
            }
            int bit = x & y;
            if (k == 0 && kp == 0 && bit == ((K >> i) & 1)) {
              ans += temp;
            }
            if (k == 1 && (kp == 1 || bit < ((K >> i) & 1))) {
              ans += temp;
            }
          }
        }
      }
    }
  }
  return ans;
}

lint work() {
  scanf("%lld%lld%lld", &A, &B, &K);
  fill(dp[0][0][0], dp[32][0][0], -1LL);
  return dfs(0, 1, 1, 1);
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: %lld\n", index, work());
  }
  return 0;
}
