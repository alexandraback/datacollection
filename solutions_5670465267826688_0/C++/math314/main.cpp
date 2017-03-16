#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

#pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int multi(int a, int b){
	int sign = (a^b) & 4;
	a &= 3, b &= 3;
	int tbl[4][4] = {
		{ 0, 1, 2, 3 },
		{ 1, 4, 3, 6 },
		{ 2, 7, 4, 1 },
		{ 3, 2, 5, 4 }
	};
	int ret = tbl[a][b];
	return ret ^ sign;
}

bool solve(){
	int l;
	ll x;
	cin >> l >> x;
	string s; cin >> s;

	vector<int> v;
	v.push_back(0);
	FOR(i, l){
		v.push_back(multi(v.back(), s[i] - 'i' + 1));
	}
	int all = 0;
	FOR(i, x % 4) all = multi(all, v.back());
	if (all != 4) return false;

	vector<int> v2;
	v2.push_back(0);
	FOR(_, min<ll>(8, x)){
		FOR(i, l){
			v2.push_back(multi(v2.back(), s[i] - 'i' + 1));
		}
	}

	int id = 1;
	for (; id < sz(v2); id++) if (v2[id] == 1)break;
	for (; id < sz(v2); id++) if (v2[id] == 3)break;

	return id < sz(v2);
}

int main() {

	// test();

	int t; cin >> t;
	FOR($, t) {
		bool b = solve();
		string ans = b ? "YES" : "NO";
		printf("Case #%d: %s\n", $ + 1, ans.c_str());
	}

	return 0;
}