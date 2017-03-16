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

#define FOR(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
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

ll expmod(ll a, ll b, ll mod) {
  ll res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1)
      res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
}

const int MAX_N = 200000;
const ll MODD = 1000000009LL;
const ld EPS = 1e-9;

int N;
vector<pair<string, string>> topics;

bool is_valid(int subset) {
	set<string> real_first, real_second;
	FOR(i,0,N) {
		if (subset & (1 << i)) {
			real_first.insert(topics[i].first);
			real_second.insert(topics[i].second);
		}
	}
	FOR(i,0,N) {
		if (!(subset & (1 << i))) {
			if (real_first.count(topics[i].first) == 0 || real_second.count(topics[i].second) == 0) return false;
		}
	}
	return true;
}


void solve() {
	cin >> N;
	topics.clear();
	string a, b;
	FOR(i,0,N) {
		cin >> a >> b;
		topics.emplace_back(a, b);
	}
	int answer = 0;
	for (int subset = 1; subset < (1 << N); subset++) {
		int reals = __builtin_popcount(subset);
		if (is_valid(subset)) answer = max(answer, N - reals);
	}
	cout << ' ' << answer << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ":";
    solve();
  }
}
