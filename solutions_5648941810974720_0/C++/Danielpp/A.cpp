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

void subtract(string str, int num, map<char, int>& counter) {
	for (const char c : str) counter[c] -= num;
}

void solve() {
	string S;
	cin >> S;
	
	map<char, int> counter;
	FOR(c,'A','Z'+1) counter[c] = count(S.begin(), S.end(), c);
	
	vi digits(10);
	//Zero
	digits[0] = counter['Z'];
	subtract("ZERO", digits[0], counter);
	//Six
	digits[6] = counter['X'];
	subtract("SIX", digits[6], counter);
	//Two
	digits[2] = counter['W'];
	subtract("TWO", digits[2], counter);
	//Four
	digits[4] = counter['U'];
	subtract("FOUR", digits[4], counter);
	//Five
	digits[5] = counter['F'];
	subtract("FIVE", digits[5], counter);
	//One
	digits[1] = counter['O'];
	subtract("ONE", digits[1], counter);
	//Three
	digits[3] = counter['R'];
	subtract("THREE", digits[3], counter);
	//Eight
	digits[8] = counter['T'];
	subtract("EIGHT", digits[8], counter);
	//Nine
	digits[9] = counter['I'];
	subtract("NINE", digits[9], counter);
	//Seven
	digits[7] = counter['V'];
	subtract("SEVEN", digits[7], counter);
	
	vi result;
	
	FOR(i,0,10)	FOR(j,0,digits[i]) result.push_back(i);
	
	cout << ' ';
	for (auto i : result) cout << i;
	cout << endl;
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
