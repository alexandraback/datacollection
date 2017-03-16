#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);


ll s10[18];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int iter = 1; iter <= t; iter++)
	{	
		cout << "Case #" << iter << ": ";
		ll pv = 0;
		ll aa = 0, ab = (1ll << 60);
		string s1;
		string s2;
		cin >> s1 >> s2;
		int n = s1.length();
		s10[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--)
		{
			s10[i] = s10[i + 1] * 10ll;
		}
		for (int i = 0; i <= n; i++)
		{
			if (i == n)
			{
				aa = ab = pv;
				break;
			}
			int mv = 10;
			for (int j = 0; j < 10; j++)
			{
				for (int l = 0; l < 10; l++)
				{
					if ((s1[i] != '0' + j) && (s1[i] != '?')) continue;
					if ((s2[i] != '0' + l) && (s2[i] != '?')) continue;
					if (((s1[i] == '?') || (s2[i] == '?')) && (abs(j - l) > 1)) continue;
					if ((s1[i] == '?') && (s2[i] == '?') && (j > 0) && (l > 0)) continue;
					if (j == l)
					{
						mv = min(j, mv);
						continue;
					}
					ll da = pv + s10[i] * (ll)j;
					ll db = pv + s10[i] * (ll)l;
					for (int ii = i + 1; ii < n; ii++)
					{
						if (s1[ii] != '?') da += (ll)(s1[ii] - '0') * s10[ii];
						else if (j < l) da += 9ll * s10[ii];
						else {};
						if (s2[ii] != '?') db += (ll)(s2[ii] - '0') * s10[ii];
						else if (j > l) db += 9ll * s10[ii];
						else {};
					}
					if (make_pair(abs(da - db), make_pair(da, db)) < make_pair(abs(aa - ab), make_pair(aa, ab))) aa = da, ab = db;
				}
			}
			if (mv == 10) break;	
			pv += (ll)mv * s10[i];
		}
		for (int i = 0; i < n - 1; i++)
			if (aa < s10[i]) cout << 0;
		cout << aa << " ";
		for (int i = 0; i < n - 1; i++)
			if (ab < s10[i]) cout << 0;
		cout << ab << endl;
	}
	return 0;
}