#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int k, n;
vector<int> A[50];
int t[1<<20];
int mask[300];
int tp[50];

void update(int v, int t) {
	forn(i, A[v].size())
		if (t == 1)
			mask[A[v][i]] ++;
		else
			mask[A[v][i]] = 0;
}

void solve() {
	cin >> k >> n;
	A[n].resize(k);
	forn(i, k)
		cin >> A[n][i];
	forn(i, n) {
		cin >> tp[i];
		int w;
		cin >> w;
		A[i].resize(w);
		forn(j, w)
			cin >> A[i][j];
	}
	seta(t, 255);                   
	t[(1<<n)-1] = -2;
	seta(mask, 0);
	ford(i, 1 << n)
		if (t[i] == -1) {
			forn(j, n)
				if (i & (1 << j)) {
					update(j, 1);
					mask[tp[j]]--;
				}
			update(n, 1);
			forn(j, n)
				if (!(i & (1 << j)) && mask[tp[j]] > 0)
					if (t[i|(1<<j)] != -1) {
						t[i] = j;
						break;
					}
			forn(j, n)
				if (i & (1 << j))
					update(j, 0);
			forn(j, n)
				if (i & (1 << j))
					mask[tp[j]] = 0;
			update(n, 0);
		}
	if (t[0] == -1) {
		cout << " IMPOSSIBLE" << endl;
		return;
	}
	int mask = 0;
	forn(i, n) {
		printf(" %d", t[mask] + 1);
		mask = mask | (1 << t[mask]);
	}
	cout << endl;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	forn(ii, tt) {
		printf("Case #%d:", ii + 1);
		solve();
	}
	return 0;
}
