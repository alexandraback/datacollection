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

bool solve() {
  int x, r, c;
  scanf("%d%d%d", &x, &r, &c);
  if (r > c) {
    swap(r, c);
  }

  if (x == 1) {
    return true;
  }

  if (x == 2) {
    return r % 2 == 0 || c % 2 == 0;
  }

  if (x == 3) {
    return (r == 2 && c == 3) || (r == 3 && c == 4) || (r == 3 && c == 3);
  }

  return (r == 3 || r == 4) && c == 4;
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: %s\n", index, solve() ? "GABRIEL" : "RICHARD");
  }
  return 0;
}
