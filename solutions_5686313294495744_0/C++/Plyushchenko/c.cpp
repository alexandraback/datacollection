#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <cassert>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#define mp make_pair
#define pb push_back
#define problem "test"
typedef __int128 ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
const int z = 11111;
const double eps = 1e-9;
const int inf = int(1e9);
const ll llinf = ll(1e18);
using namespace std;


int n, a[z], ans;
string s[z], t[z];
inline void check()
{
    set <string> have[2];
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (a[i])
		{
			cnt++;
			have[0].insert(s[i]);
			have[1].insert(t[i]);
		}
//	for (int i = 0; i < n; i++)
//		cout << a[i];
//	cout << "\n";
//	for (int i = 0; i < 2; i++, cout << "\n\n")
//	for (string tmp : have[i])
//		cout <<tmp << " ";
	for (int i = 0; i < n; i++)
	{
		if (!a[i])
		{
			if (have[0].find(s[i]) == have[0].end())
			{
//			    cout << s[i] << "???\n";
				return;
			}
			if (have[1].find(t[i]) == have[1].end())
			{
//				cout << t[i] << "???\n";
				return;
			}
		}
	}
	ans = max(ans, n - cnt);
//	cout << "ans = " << ans << "\n";
}
void gen(int k)
{
	if (k == n)
	{
		check();
		return;
	}	
	a[k] = 0;
	gen(k + 1);
	a[k] = 1;
	gen(k + 1);
	a[k] = 0;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen(problem".in", "r", stdin);
	freopen(problem".out", "w", stdout);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> s[i] >> t[i];
		ans = -inf;
		gen(0);
		cout << "Case #" << test << ": " << ans << "\n";
	}	
	
	return 0;
}