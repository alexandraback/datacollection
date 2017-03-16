#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <cassert>
#include <ctime>
#include <cstdlib>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define uint unsigned int
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 alfdjasldfjeao
#define y1 safiodjafis


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++)
	{
		ll c, d, V;
		cin >> c >> d >> V;
		vector < ll > t;
		for (int i = 0; i < d; i++)
		{
			ll x;
			cin >> x;
			t.pb(x);
		}
		sort(t.begin(), t.end());
		ll cur = 1;
		int ans = 0;
		for (int i = 0; i < t.size(); i++)
		{
			ll x = t[i];
			while (cur < x)
			{
				ans++;
				cur *= c + 1;
			}
			cur += x * c;
		}
		while (cur <= V)
		{
			ans++;
			cur *= c + 1;
		}
		cout << "Case #" << test << ": " << ans << "\n";
	}
}
