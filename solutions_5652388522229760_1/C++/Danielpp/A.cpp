#include <bits/stdc++.h>
using namespace std;

#define DEBUG_ON 1  // 0 = off, 1 = on

namespace {
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define LEN(x) (int)((x).size())
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define OP minmax

#define FOR(i, begin, end)  \
  for (__typeof(end) i = (begin) - ((begin) > (end));  \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif  // ONLINE_JUDGE
  
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<ll> vll;
template<typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;

ll expmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
}

const int MAX_N = 200000;
const ll MODD = 1000000009LL;
const ld EPS = 1e-9;

void check(set<ll>& unseen, ll N) {
	do {
		unseen.erase(N%10);
		N /= 10;
	} while (N > 0);
}

string answer(int N) {
	if (N == 0) return "INSOMNIA";
	set<ll> unseen = {0,1,2,3,4,5,6,7,8,9};
	ll count = N;
	check(unseen, count);
	while (!unseen.empty()) {
		count += N;
		check(unseen, count);
	}
	return to_string(count);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int T, N;
	cin >> T;
	FOR(c,1,T+1) {
		cin >> N;
		cout << "Case #" << c << ": " << answer(N) << endl;
	}
}
