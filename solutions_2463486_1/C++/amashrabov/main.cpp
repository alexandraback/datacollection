#pragma comment(linker, "/STACK:10000000")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> T inline sqr(T x) {
    return x * x;
}
#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(v) (int)((v).size())
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

i64 solve();

vector<i64> a;
const i64 maxn = 1e14 + 100;

vi t;

bool isPal(i64 x)
{
	t.clear();
	while (x)
	{
		t.push_back(x % 10);
		x /= 10;
	}
	for (int i = 0; i < t.size() / 2; i++)
		if (t[i] != t[t.size() - i - 1])
			return false;
	return true;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	for (i64 i = 1; i * i <= maxn; i++)
	{
		if (isPal(i) && isPal(i * i))
			a.pb (i * i);
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		cout << "Case #" << i + 1 << ": ";
		i64 res = solve();
		cout << res << endl;
	}
	return 0;
}

i64 solve()
{
	i64 l, r;
	cin >> l >> r;
	i64 n1 = lower_bound(a.begin(), a.end(), l) - a.begin(), n2 = upper_bound(a.begin(), a.end(), r) - a.begin();
	return n2 - n1;
}