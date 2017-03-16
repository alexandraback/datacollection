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

const int N = 100 * 1000 + 13;

ld p[N];
ld pref[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int tests;

	cout.precision (10);
	cout.setf (ios::fixed);	
	
	cin >> tests;
	forn (test, tests)
	{
		int A, B;
		
		cin >> A >> B;
		forn (i, A)
			cin >> p[i];

		forn (i, A)
		{
			pref[i] = p[i];
			
			if (i)
				pref[i] *= pref[i - 1];
		}

		ld ans = ld (B + 2.0);

		for (int i = 0; i <= A; i++)
		{
			ld prob = 1.0;
			if (i)
				prob = pref[i - 1];

			ans = min (ans, 2 * (A - i) + B - A + 1 + (1 - prob) * (B + 1));
		}

		cout << "Case #" << test + 1 << ": " << ans << endl;
	}

	return 0;
}