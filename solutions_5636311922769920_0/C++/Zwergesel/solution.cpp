#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORVEC(it,v) for (auto it=(v).begin(); it != (v).end(); ++it)
#define NUL(arr) memset(arr, 0, sizeof(arr));
#define SORT(x) sort((x).begin(), (x).end());

template<typename T>
T ceil_div(T a, T b) {
	return (a + b - 1) / b;
}

ull mypow(ull base, ull expo)
{
	ull result = 1;
	while (expo > 0) {
		result *= base;
		--expo;
	}
	return result;
}

bool solve()
{
	ull k, c, s;
	cin >> k >> c >> s;
	if (k == 1) {
		cout << " 1";
		return true;
	}
	if (s < ceil_div(k, c)) return false;
	ull bsize = mypow(k, c) / k;
	ull pos = 0;
	ull bit = 0;
	while (bit < k) {
		ull siz = bsize;
		while (siz > 0 && bit < k) {
			pos += bit * siz;
			siz /= k;
			++bit;
		}
		cout << " " << (pos + 1);
		pos = 0;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i=1; i<=t; ++i) {
		cout << "Case #" << i << ":";
		if (!solve()) cout << " IMPOSSIBLE";
		cout << "\n";
	}
	
	return 0;
}



/*
3 = 6, 8, 12, 16, 20, 22
LLG -> LLGLLGGGG -> LLGLLGGGGLLGLLGGGGGGGGGGGGG
LGL -> LGLGGGLGL -> LGLGGGLGLGGGGGGGGGLGLGGGLGL
GLL -> GGGGLLGLL -> GGGGGGGGGGGGGLLGLLGGGGLLGLL
LGG -> LGGGGGGGG -> LGGGGGGGGGGGGGGGGGGGGGGGGGG
GLG -> GGGGLGGGG -> GGGGGGGGGGGGGLGGGGGGGGGGGGG
GGL -> GGGGGGGGL -> GGGGGGGGGGGGGGGGGGGGGGGGGGL
*/