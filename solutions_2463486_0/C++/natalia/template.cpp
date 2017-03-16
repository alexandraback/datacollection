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

vector<ll> f;

void solve(int test)
{
	printf("Case #%d: ", test);

	ll a, b;
	cin >> a >> b;

	int cnt = 0;
	forv(i, f)
	{
		if (f[i] >= a && f[i] <= b) cnt++;
	}
	cout << cnt << endl;
}

bool fair(ll x)
{
	stringstream sin;
	sin << x;
	string s;
	sin >> s;

	string t = s;
	reverse(all(t));

	return s == t;
}

int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    for1(i, 10000000)
    {
    	if (!fair(i)) continue;
    	if (fair(ll(i) * i)) 
    	{
    		cerr << i << endl;
    		f.pb(ll(i) * i);
    	}
    }

    int tc; scanf("%d\n", &tc);

    forn(it, tc) solve(it + 1);

    return 0;
}
