#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <complex>
#include <ctime>
#include <stack>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
  
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define RREP(i, n) for(int i = (n) - 1; i >= 0; --i)
#define FOR(i, x, y) for(int i = (x); i <= (y); ++i)
#define RFOR(i, x, y) for(int i = (x); i >= (y); --i)
#define SZ(a) (ll)(a).size()
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a)) 
#define CLEAR(x) memset(x, 0, sizeof x);
#define COPY(FROM, TO) memcpy(TO, FROM, sizeof TO);
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define pb push_back
#define mk make_pair
#define sqr(x) ((x)*(x))
#define X first
#define Y second
const long double pi=acos(-1.0);
const double EPS = 1E-9;
const int INF = 2 * (1e+9) + 1;
const int NMAX = 1000000;
const int MOD = (1e+9) + 7;

int n, m, t;
int main () {
  freopen ("B.in", "r", stdin);
  freopen ("B.out", "w", stdout);
  cin >> t;
  REP (test, t) {
    int cnt = 0;
    int a, b, k;
    cin >> a >> b >> k;
    FOR (i, 0, a - 1) 
      FOR (j, 0, b - 1)
        if ((i & j) < k) 
          cnt++;
    printf("Case #%d: %d\n", test + 1, cnt);
  }
}
/*
1
3
aaabbb
ab
aabb
*/