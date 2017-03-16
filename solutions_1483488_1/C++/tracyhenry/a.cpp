#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;

int a[2000001][10];
int tot[2000001], Bit[2000001];
int u[2000001], TT = 0;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
	memset(tot, 0, sizeof(tot));
	memset(u, 0, sizeof(u));
	for (int i = 1; i <= 2000000; i ++)
	{
		Bit[i] = 0;
		for (int x = i; x; )
			Bit[i] ++, x /= 10;
	}
	for (int i = 1; i <= 2000000; i ++)
	{
		string s = "";
		for (int x = i; x; )
			s += char(48 + x % 10), x /= 10;
		reverse(s.begin(), s.end());
		for (int j = 0; j < Bit[i] - 1; j ++)
			s += s[j];
		TT ++;
		for (int j = 0; j < Bit[i]; j ++)
		{
			string cur = s.substr(j, Bit[i]);
			int v = atoi(cur.c_str());
			if (v > 2000000) continue;
			if (v > i && Bit[v] == Bit[i] && u[v] < TT)
				a[i][++ tot[i]] = v, u[v] = TT;
		}
	}
	//
	int T;
	cin >> T;
	for (int t = 1; t <= T; t ++)
	{
		int L, R;
		cin >> L >> R;
		cout << "Case #" << t << ": ";
		vector<pair<int, int> > F;
		F.clear();
		LL ans = 0LL;
		for (int i = L; i <= R; i ++)
			for (int j = 1; j <= tot[i]; j ++)
				if (a[i][j] >= L && a[i][j] <= R)
					ans ++;
		cout << ans << endl;
	}
	return 0;
}
