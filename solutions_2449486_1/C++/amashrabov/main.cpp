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


bool solve();

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		cout << "Case #" << i + 1 << ": ";
		bool res = solve();
		if (res)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

const int maxn = 110;
int a[maxn][maxn];
int fin[maxn][maxn];

bool solve()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, pii> > r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> fin[i][j];
			r.pb (mp(-fin[i][j], mp(i, j)));
		}
	sort(r.begin(), r.end());
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = 100;
	for (int i = 0; i < r.size(); i++)
	{
		int x = r[i].second.first;
		int y = r[i].second.second;
		bool ok = true;
		for (int i = 0; i < n; i++)
			if (fin[i][y] > fin[x][y])
			{
				ok = false;
			}
		if (ok) continue;
		ok = true;
		for (int i = 0; i < m; i++)
			if (fin[x][i] > fin[x][y])
			{
				ok = false;
			}
		if (!ok) return false;
	}

	return true;
}