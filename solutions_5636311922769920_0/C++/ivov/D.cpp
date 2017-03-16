#include "../libs/DebugOutput.h"
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cassert>
#include <map>
#include <memory>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#if ( _WIN32 || __WIN32__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define pb push_back
#define INF 1000000000
#define L(s) (int)(s.size())
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, n) FOR(i, 1, (n))
#define rept(i, n) FOR(i, 0, int(n) - 1)
#define C(a) memset((a), 0, sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int, int>
#define pdd pair<double, double>
#define sqr(a) (a)*(a)
#define pi 3.1415926535897932384626433
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define rnd() ((rand() << 16) ^ rand())

void solve() {
	ll k, c, s;
	cin >> k >> c >> s;
	ll optimum = (k + c - 1) / c;
	if (s < optimum) {
		cout << "IMPOSSIBLE";
		return;
	}

	ll maxnumber = 1;
	for (int i = 1; i <= c; i++) { 
		maxnumber *= k;
	}

	vector<ll> results;
	for (int i = 0; i < k; i += c) {
		ll cur = i;
		for (int j = 1; j < c; j++) {
			cur *= k;
			cur += min((ll) i + j, k - 1);
		}
		assert(cur >= 0);
		assert(cur < maxnumber);
		results.push_back(cur + 1);
	}

	for (int i = 0; i < L(results); i++) {
		if (i) {
			cout << " ";
		}
		cout << results[i];
	}
	assert(results.size() == optimum);
}

int main() {
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout); 
    int TC;
    scanf("%d", &TC);
    rep(tc, TC) {
		cout << "Case #" << tc << ": ";
    	solve();
    	cout << endl;
    }
    return 0;
}