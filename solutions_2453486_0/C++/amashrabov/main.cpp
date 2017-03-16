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

void solve();

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	return 0;
}

int a[10][10];

bool check(int c)
{
	for (int i = 0; i < 4; i++)
	{
		bool ok = true;
		for (int j = 0; j < 4; j++)
			if (a[i][j] != c)
				ok = false;
		if (ok)
			 return true;
	}

	for (int i = 0; i < 4; i++)
	{
		bool ok = true;
		for (int j = 0; j < 4; j++)
			if (a[j][i] != c)
				ok = false;
		if (ok)
			 return true;
	}

	bool ok = true;
	for (int i = 0; i < 4; i++)
		if (a[i][i] != c)
			ok = false;
	if (ok) return true;
	
	ok = true;
	for (int i = 0; i < 4; i++)
		if (a[i][3 - i] != c)
			ok = false;
	return ok;
}

void solve()
{
	int n = 4;
	int x = -1, y;
	int qEmpty = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			char ch;
			cin >> ch;
			if (ch == '.')
				a[i][j] = 0, qEmpty++;
			if (ch == 'X')
				a[i][j] = 1;
			if (ch == 'O')
				a[i][j] = 2;
			if (ch == 'T')
			{
				a[i][j] = 3;
				x = i, y = j;
			}
		}
	if (x != -1)
		a[x][y] = 1;
	bool res = check(1);
	if (res)
	{
		cout << "X won" << endl;
		return;
	}
	
	if (x != -1)
		a[x][y] = 2;
	res = check(2);
	if (res)
	{
		cout << "O won" << endl;
		return;
	}

	if (qEmpty != 0)
		cout << "Game has not completed" << endl;
	else
		cout << "Draw" << endl;
}