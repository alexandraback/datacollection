#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef vector<bool> Vb;
typedef vector<Vb> Mb;
typedef vector<char> Vc;
typedef vector<Vc> Mc;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<ll> Vll;
typedef vector<Vll> Mll;
typedef vector<P> Vp;
typedef vector<Vp> Mp;
typedef vector<string> Vs;
typedef vector<Vs> Ms;

typedef set<int> SET;
typedef SET::iterator Sit;
typedef map<int, int> MAP;
typedef MAP::iterator Mit;
typedef stringstream SS;

template <class Ta, class Tb> inline Tb cast(Ta a) { SS ss; ss << a; Tb b; ss >> b; return b; };

const double EPS = 1e-9;
const int INF = 1000000000;
const int diri[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dirj[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int A, B, N;
ld dp[8100][8100];

int T;
int tdp[8100][8100];

ld fun(int a, int b) {
  if (tdp[a][b] == T) return dp[a][b];
  tdp[a][b] = T;
  if (a == A) return dp[a][b] = 1;
  if (a + b >= N) return dp[a][b] = 0;
  if (b == B) return dp[a][b] = fun(a + 1, b);
  return dp[a][b] = 0.5*fun(a + 1, b) + 0.5*fun(a, b + 1);
}

ll prev_layers(ll layer) {
  ll n = 2*layer - 1;
  return n*(n + 1)/2;
}

int main() {
  cout.setf(ios::fixed);
  cout.precision(9);
  
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    cout << "Case #" << cas << ": ";
    ll n, x, y;
    cin >> n >> x >> y;
    ll layer = (abs(x) + y)/2;
    if (n <= prev_layers(layer)) {
      cout << 0.0 << endl;
      continue;
    }
    n -= prev_layers(layer);
    ll m = 4*layer + 1;
    if (m <= n) {
      cout << 1.0 << endl;
      continue;
    }
    if (x == 0) {
      cout << 0.0 << endl;
      continue;
    }
    
    A = y + 1;
    B = 2*layer;
    N = n;
    ++T;
    cout << fun(0, 0) << endl;
  }
}
