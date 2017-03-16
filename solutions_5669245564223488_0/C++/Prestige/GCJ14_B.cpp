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

ll n, m, t;
int test;
ll gcd (ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}
void convert (string &s, ll& a, ll& b) {
  int f = 0;
  ll d = 1;
  RREP (j, SZ(s)) {
    if (s[j] == '/') {
      f = 1;
      d = 1;
      continue;
    }
    if (f == 0) {
      b += ((s[j] - '0')) * d;
      d *= 10;
    } else {
      a += ((s[j] - '0')) * d;
      d *= 10;
    }
  }
}
int main () {
  freopen ("a.in", "r", stdin);
  freopen ("a.out", "w", stdout);
  scanf("%d", &test);
  REP (kk, test) {
    bool stop = 1;
    cin >> n;
    vector<string> tr(n);
    REP (i, n) {
      string temp;
      cin >> tr[i];
      temp += tr[i][0];
      FOR (j, 1, SZ(tr[i]) - 1) {
        if(tr[i][j] != tr[i][j - 1])
          temp += tr[i][j];
      }
      tr[i] = temp;

    }
    int mas[10];
    REP (i, n) mas[i] = i;
    ll ans = 0;
    do {
      bool f = 1;
      VVI cc(26);
      int len = 0;
      FOR (i, 0, n - 1) {
        REP (j, SZ(tr[mas[i]])) {
          cc[tr[mas[i]][j] - 'a'].pb(len);
          len++;
        }
      }
      REP (i, 26) {
        FOR (j, 1, SZ(cc[i]) - 1) {
          if (cc[i][j] != cc[i][j - 1] + 1) f = 0;
        }
      }
      if (f) ans++;
    } while (next_permutation (mas, mas + n));
    cerr << kk + 1 << " ";
    if (stop)
      cout << "Case #"<< kk + 1 << ": "<< ans << endl;
    else if (!stop) cout << "Case #"<< kk + 1 << ": "<< 0 << endl;
  }
}
/*
*/