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

typedef vector<i64> vi64;

int solve()
{
	int cur, n;
	cin >> cur >> n;
	vi64 a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (cur == 1)
	{
		return n;
	}
	sort(a.begin(), a.end());
	int ans = 1e9;
	int act = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < cur)
			cur += a[i];
		else
		{
			ans = min(ans, act + n - i);
			i--;
			act++;
			cur += cur - 1;
		}
	}
	ans = min(ans, act);
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int ans = solve();
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}
