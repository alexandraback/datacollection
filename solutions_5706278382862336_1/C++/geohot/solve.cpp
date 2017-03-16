#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <queue>
#include <cassert>
#include <bitset>
#include <climits>
#include <cfloat>
#define typeof __typeof__
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define FF first
#define SS second

#define FOR(v, s, e) for (int v = s; v < e; v++)
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define FI(c) for (ll i = 0; i < c; ++i)
#define FJ(s,c) for (ll j = s; j < c; ++j)
#define FK(s,c) for (ll k = s; k < c; ++k)
#define MP(X,Y) make_pair(X,Y)
// end boilerplate code...

/* Standard C Function: Greatest Common Divisor */
ll gcd ( ll a, ll b ) {
  ll c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}


bool is_power_of_two(ll x) {
  return (x & (x - 1)) == 0;
}

void runcase() {
  ll p,q;
  char junk;
  cin >> p >> junk >> q;

  ll g = gcd(p, q);
  p = p/g;
  q = q/g;

  //cout << p << " " << q << endl;

  if (!is_power_of_two(q)) cout << "impossible" << endl;
  else {
    int gg = 0;
    while (!(p&q)) { gg++; p <<= 1; }
    cout << gg << endl;
  }
}

int main() {
  cout << setprecision(9);
/* *** codejam style *** */
  int case_count;
  cin >> case_count;
  for (int i = 0; i < case_count; i++) {
    cout << "Case #" << i+1 << ": ";
    runcase();
  }
/* *** because I'm awesome *** */
  return 0;
}

