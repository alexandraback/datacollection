#include <iostream> 
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <cassert>

using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

const int INF = 2000000000;
const ll LLINF = 9000000000000000000;

ll SIZE;
vector<ll> primes;
vector<ll> mf;				// mf[i]==i when prime

void sieve2(ll size=1e8) {	// call at start in main!
	SIZE = size; mf.assign(SIZE+1,-1);
	mf[0] = mf[1] = 1;
	for (ll i = 2; i <= SIZE; i++) if (mf[i] < 0) {
		mf[i] = i;
		for (ll j = i * i; j <= SIZE; j += i)
			if(mf[j] < 0) mf[j] = i;
		primes.push_back(i);
	}
}

bool find_fact(ll V, ll &fact) {
	if (V < SIZE) {
		fact = mf[V];
		return V != fact;
	}
	for (size_t i = 0; i < primes.size(); ++i)
		if (V % primes[i] == 0LL) {
			fact = primes[i];
			return true;
		}
	
	for (ll v = primes.back(); v * v <= V; v += 2LL) {
		if (V % v == 0LL) {
			fact = v;
			return true;
		}
	}
	return false;
}

void solve(int N, int J) {
	
	vi ans;
	vi div[11];
	for (ll s = (1LL << (N-1)) + 1LL; ans.size() < J; s += 2) {
		
		bool success = true;
		for (ll b = 2; b <= 10 && success; ++b) {
			
			ll v = 0LL;
			if (b == 2LL) v = s;
			else {
				for (ll c = 1LL, ss = s; ss > 0LL; c *= b, ss >>= 1) {
					if (ss&1LL)
						v += c;
				}
			}
			
			ll fact = -1LL;
			if (find_fact(v, fact) && fact != v)
				div[b].push_back(fact);
			else	success = false;
		}
		
		if (success) ans.push_back(s);
		else {
			for (int b = 2; b <= 10; ++b)
				if (div[b].size() > ans.size())
					div[b].pop_back();
		}
	}
	
	for (int i = 0; i < J; ++i) {
		for (int j = N - 1; j >= 0; --j)
			cout << ((((ans[i]>>j)&1)==1) ? '1' : '0');
		for (int b = 2; b <= 10; ++b)
			cout << ' ' << div[b][i];
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	sieve2(1e8);
	
	int T;
	cin >> T;
	while (T--) {
		int N, J;
		cin >> N >> J;
		cout << "Case #1: ";
		cout << endl;
		solve(N, J);
	}
	
	return 0;
}
