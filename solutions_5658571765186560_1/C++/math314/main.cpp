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

bool solve(){
	int x, r, c; cin >> x >> r >> c;
	if (r > c) swap(r, c);
	if (r * c % x != 0) return false;

	if (x == 1) return true;
	else if (x == 2) return true;
	else if (x == 3) {
		if (c < x) return false;
		if (r == 1) return false;
		return true;
	} if (x == 4) {
		if (c < x) return false;
		if (r <= 2) return false;
		return true;
	} else if (x == 5) {
		if (c < x) return false;
		if (r <= 2) return false;
		if (r == 3) {
			if (c >= 10) return true;
			else return false;
		}
		return true;
	} else if (x == 6) {
		if (c < x) return false;
		if (r <= 3) return false;
		else if (r == 4) {
			if (c == 3) return false;
			else return true;
		} else {
			return true;
		}
	} else {
		return false;
	}

	return false;
}

int main() {

	// test();

	int t; cin >> t;
	FOR($, t) {
		bool b = solve();
		string ans = b ? "GABRIEL" : "RICHARD";
		printf("Case #%d: %s\n", $ + 1, ans.c_str());
	}

	return 0;
}