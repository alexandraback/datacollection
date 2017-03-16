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
  ll mas[41];
  REP (i, 41) mas[i] = (1ll<<i);
  REP (i, test) {
    string s;
    ll p = 0, q = 0;
    cin >> s;
    convert (s, p, q);
    ll g = gcd (p, q);
    p /= g, q /= g;
    ll mul = -1;
    REP (j, 41) {
      if (mas[j] % q == 0) {
        mul = mas[j] / q;
        break;
      }
    }
    if (mul == -1) {
      cout << "Case #"<< i + 1 << ": impossible"<< endl;
      continue;
    }
    q *= mul, p *= mul;
    int ans = 0;
    while (1) {
      if (p == q && p) break;
      p = min (p, q / 2);
      q /= 2;
      ans++;
    }
    cout << "Case #"<< i + 1 << ": "<< ans << endl;
  }
}
/*
*/