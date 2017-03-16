#pragma comment(linker, "/STACK:256000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back                      
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define pi 3.1415926535897932

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

void solve(int test)
{
	printf("Case #%d: ", test);

	int n, a;
	cin >> a >> n;
	vector<int> v(n);

	forn(i, n) cin >> v[i];

	sort(all(v));

	int ans = n;
	ll A = a;
	int c = 0;

	forn(i, n)
	{
		while (A <= v[i] && c < n) 
		{
			A += A - 1;
			c++;
		}
		A += v[i];

		ans = min(ans, c + n - i - 1);
	}

	cout << ans << endl;
}

int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc; scanf("%d\n", &tc);

    forn(it, tc) solve(it + 1);

    return 0;
}
