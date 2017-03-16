#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <iterator>
#include <bitset>
#include <random>
#include <assert.h>

#ifdef _MSC_VER
#include <agents.h>
#endif

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> P;

ll gcd(ll m, ll n){
	return n ? gcd(n, m%n) : m;
}

bool check(ll x){
	while (x % 2 == 0) x /= 2;
	return x == 1;
}

ll _log2(ll x){
	ll cnt = 0;
	while (x > 1){
		x /= 2;
		++cnt;
	}
	return cnt;
}

int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t){
		printf("Case #%d: ", t);

		char c;
		ll p, q;
		cin >> p >> c >> q;
		ll g = gcd(p, q);
		p /= g;
		q /= g;

		if (!check(q)){
			cout << "impossible" << endl;
		}
		else{
			while (p % 2 == 0 && q % 2 == 0){
				p /= 2, q /= 2;
			}
			cout << _log2(q)-_log2(p) << endl;
		}
	}



	return 0;
}