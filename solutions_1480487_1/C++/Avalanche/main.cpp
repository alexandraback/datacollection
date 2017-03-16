#pragma comment(linker, "/stack:64000000")
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

const int N = 2 * 100 + 13;

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
		int a[N];

		cin >> n;
		int sum = 0;

		forn (i, n)
		{
			cin >> a[i];
			sum += a[i];
		}

		printf ("Case #%d: ", test + 1);

		ld B = 0.0;
		vector <ld> b (n), ans (n);

		for (int i = 1; i < n; i++)
		{
			b[i] = ld (a[0] - a[i]) / ld (sum);

			B += b[i];
		}

		int cnt = 0;
		ans[0] = (1.0 - B) / ld (n);

		for (int i = 1; i < n; i++)
			ans[i] = ans[0] + b[i];

		forn (i, n)
		{
			if (ans[i] < -EPS)
				cnt++;
		}

		assert (cnt < n - 1);

		B = 0.0;
		int idx = -1;
		forn (i, n)
			if (ans[i] + EPS >= 0)
			{
				idx = i;
				break;
			}

		for (int i = idx + 1; i < n; i++)
		{
			if (ans[i] + EPS >= 0)
			{
				b[i] = ld (a[idx] - a[i]) / ld (sum);

				B += b[i];
			}
		}
		
		ans[idx] = (1.0 - B) / ld (n - cnt);

		for (int i = n - 1; i > idx; i--)
		{
			if (ans[i] + EPS >= 0)
			{
				ans[i] = ans[idx] + b[i];
			}
		}

		forn (i, n)
			printf ("%.10lf ", max (ans[i], (ld) 0) * 100.0);

		cout << endl;
	}

	return 0;
}