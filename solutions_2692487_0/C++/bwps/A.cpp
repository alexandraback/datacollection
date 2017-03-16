#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int TC, A, N, sizes[110];

int calc(int n) {
  int cur = A, res = 0;
  FOR(i, 0, n) {
    while (cur <= sizes[i]) {
      res++;
      cur += (cur-1);
    }
    cur += sizes[i];
  }
  return res;
}

int main() {
  cin >> TC;
  FOR(cs, 1, TC+1) {
    cin >> A >> N;
    FOR(i, 0, N) cin >> sizes[i];
    sort(sizes, sizes + N);
    int res = N;
    if (A >= 2) FOR(i, 1, N+1) res = min(res, N - i + calc(i));
    cout << "Case #" << cs << ": " << res << endl;
  }
	return 0;
}
