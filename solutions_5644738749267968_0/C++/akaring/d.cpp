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

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    int n;
    scanf("%d", &n);

    vector<double> a(n), b(n);
    REP (i, n) {
      scanf("%lf", &a[i]);
    }
    sort(ALL(a));
    REP (i, n) {
      scanf("%lf", &b[i]);
    }
    sort(ALL(b));

    int l = 0, r = n - 1;
    REP (i, n) {
      if (a[i] < b[l]) {
        --r;
      } else {
        ++l;
      }
    }
    int x = l;

    l = 0, r = n - 1;
    for (int i = n - 1; i >= 0; --i) {
      if (a[i] > b[r]) {
        ++l;
      } else {
        --r;
      }
    }
    printf("Case #%d: %d %d\n", index, x, l);
  }
  return 0;
}
