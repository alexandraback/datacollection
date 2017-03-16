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

int work() {
  int s_m;
  string s;
  cin >> s_m >> s;
  int cnt = 0, ans = 0;
  REP (i, SZ(s)) {
    int n = s[i] - '0';
    if (n > 0) {
      if (cnt < i) {
        int d = i - cnt;
        ans += d;
        cnt += d;
      }
      cnt += n;
    }
  }
  return ans;
}

int main() {
  int n_case;
  cin >> n_case;
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: %d\n", index, work());
  }
  return 0;
}
