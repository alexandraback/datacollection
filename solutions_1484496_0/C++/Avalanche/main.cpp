#pragma comment(linker, "/stack:256000000")
#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <vector>
#include <bitset>
#include <string>
#include <deque>
#include <queue>
#include <ctime>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb push_back
#define pii pair <int, int>
#define vi vector <int>
#define mp make_pair

template <typename X> inline X abs (const X &a) {return a < 0? -a: a;}
template <typename X> inline X sqr (const X &a) {return a * a;}

const int INF = INT_MAX / 2;
const ll INF64 = LLONG_MAX / 2LL;
const ld EPS = 1E-9, PI = 3.1415926535897932384626433832795;

const int N = 20;

int a[N];
int sum[1 << 20];
map <int, vector <int> > s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int tests;
	
	cin >> tests;
	forn (test, tests)
	{
		int n;
		
		cin >> n;
		forn (i, n)
			cin >> a[i];

		s.clear();
		
		for (int mask = 0; mask < (1 << n); mask++)
		{
			sum[mask] = 0;
			forn (i, n)
				if (mask & (1 << i))
					sum[mask] += a[i];

			s[sum[mask]].pb (mask);
		}

		int all = sum[(1 << n) - 1];

		bool ok = false;
		printf ("Case #%d:\n", test + 1);

		for (int mask = 1; mask < (1 << n); mask++)
		{
			int add = all - 2 * sum[mask];

			if (add < 0)
				continue;

			forn (i, sz (s[add]))
				if ((s[add][i] & mask) == 0)
				{
					forn (j, n)
						if (mask & (1 << j))
						{
							cout << a[j] << ' ';
						}

					cout << endl;

					forn (j, n)
					{
						if (mask & (1 << j))
							continue;

						if (s[add][i] & (1 << j))
							continue;

						cout << a[j] << ' ';
					}

					cout << endl;

					ok = true;
					break;
				}

			if (ok)
				break;
		}

		if (!ok)
			puts ("Impossible");
	}

	return 0;
}