#include <bits/stdc++.h>
using namespace std;

#define DEBUG_ON 1 // 0 = off, 1 = on

namespace {
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define LEN(x) (int)((x).size())
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define OP minmax

#define FOR(i, begin, end)						\
  for (__typeof(end) i = (begin) - ((begin) > (end));			\
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif // ONLINE_JUDGE

typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<ll> vll;
template <typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

ll expmod(ll a, ll b) {
  ll res = 1;
  for (; b; b >>= 1) {
    if (b & 1)
      res = res * a;
    a = a * a;
  }
  return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
}

const int MAX_N = 200000;
const ll MODD = 1000000009LL;
const ld EPS = 1e-9;

vvi matrix;

void connect(int u, int v) {
	matrix[u][v] = 1;
}

vi to_binary(ll x) {
	vi ans;
	while (x > 0) {
		ans.push_back(x % 2);
		x /= 2;
	}
	return ans;
}

void solve() {
	ll B, M;
	cin >> B >> M;
	
	ll possible = expmod(2, B-2);
	
	if (possible < M) {
		cout << " IMPOSSIBLE" << endl;
		return;
	}
	
	matrix.assign(B, vi(B, 0));
	
	if (M == possible) {
		for (int i=0; i<B-1; i++) {
			for (int j=i+1; j<B; j++) {
				connect(i, j);
			}
		}
	}
	else {
		for (int i=1; i<B-1; i++) {
			for (int j=i+1; j<B; j++) {
				connect(i, j);
			}
		}
		
		vi bin = to_binary(M);
		for (int i=0; i<LEN(bin); i++) {
			if (bin[i]) {
				connect(0, B-2-i);
			}
		}
	}
	
	cout << " POSSIBLE" << endl;
	for (int i=0; i<B; i++) {
		for (int j=0; j<B; j++) {
			cout << matrix[i][j];
		}
		cout << endl;
	}
	
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int T = 0;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ":";
    solve();
  }
}
