#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iterator>
#define FOR(i,a,n) for(int i = (a); i < (int)(n); ++i)
#define foreach(itr,c) for(decltype((c).begin()) itr=(c).begin(); itr != (c).end(); itr++)
#define MP(a,b) make_pair(a,b)

using namespace std;

int in[100][100], out[100], mk[3000];

int n;

void solve() {
}

int main() {
  getchar();
  //freopen("A-large.in", "r", stdin);
  //freopen("A-large.out", "w", stdout);
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);
  int t, x;
  cin >> t;
  FOR(tt, 1, t + 1) {
    cin >> n;
    memset(mk, 0, sizeof(mk));
    FOR(i, 0, 2 * n - 1) {
      FOR(j, 0, n) {
        cin >> x;
        mk[x]++;
      }
    }
    int m = 0;
    FOR(i, 0, 2600) {
      if(mk[i] & 1) out[m++] = i;
    }
    sort(out, out + m);
    printf("Case #%d: ", tt);
    FOR(i, 0, m) printf("%d%c", out[i], i == m - 1 ? '\n' : ' ');
  }
  return 0;
}
