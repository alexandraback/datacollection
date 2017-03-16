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
  int n;
  scanf("%d", &n);
  VI iv(n);
  REP (i, n) {
    scanf("%d", &iv[i]);
  }

  int ans = ~0U >> 2;
  sort(ALL(iv));
  for (int i = 1; i <= iv.back(); ++i) {
    int x = 0;
    for (int o: iv) {
      x += o / i + !!(o % i) - 1;
    }
    checkMin(ans, x + i);
  }
  return ans;
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: %d\n", index, work());
  }
  return 0;
}
