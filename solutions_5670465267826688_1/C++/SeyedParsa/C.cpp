//be naame khodaa

#include <bits/stdc++.h>

typedef long long ll;

#define I  2
#define J  3
#define K  4

using namespace std;

int tMin[20], *Min = tMin + 10;
int tMax[20], *Max = tMax + 10;

int g[4][4] = { {1, 2, 3, 4}, {2, -1, 4, -3}, {3, -4, -1, 2}, {4, 3, -2, -1} };

void mult(int &p, int r)
{
	int sign = 1;
	if (p < 0) sign *= -1;
	if (r < 0) sign *= -1;
	p = abs(p), r = abs(r);
	p = sign*g[p-1][r-1];
}

int main()
{
	int t;
	cin >> t;
	for (int it = 1; it <= t; it++)
	{
		ll l, x;
		string s;
		cin >> l >> x >> s;
		for (int i = -K; i <= K; i++)
			Min[i] = l+1, Max[i] = -1;
		int p = 1;
		for (int i = 0; i < l; i++)
		{
			int r = (s[i] == 'i' ? 2 : (s[i] == 'j' ? 3 : 4));
			mult(p, r);
			Min[p] = min(Min[p], i);
		}
		int seg = p;
		if (p == 1 || ((p != -1 || x%2 == 0) && (p == -1 || x%2 == 1 || x/2%2 == 0)))
		{
			cout << "Case #" << it << ": NO" << endl;
			continue;
		}
		p = 1;
		for (int i = l-1; i >= 0; i--)
		{
			int r = (s[i] == 'i' ? 2 : (s[i] == 'j' ? 3 : 4));
			mult(r, p);
			p = r;
			Max[p] = max(Max[p], i);
		}
		bool can = false;
		for (int ii = -K; ii <= K; ii++)
			for (int jj = -K; jj <= K; jj++)
			{
				if (ii == 0 || jj == 0) continue;
				if (Min[ii] > l || Max[jj] < 0) continue;
				ll need = 1, L = 4, R = 4;
				if (Min[ii] >= Max[jj])
					need++;
				int pl = ii, pr = jj;
				for (int j = 0; j < 4; j++)
				{
					if (pl == I && L == 4) L = j;
					if (pr == K && R == 4) R = j;
					int tmp = seg;
					mult(tmp, pl); pl = tmp;
					mult(pr, seg);
				}
				if (L == 4 || R == 4) continue;
				need += L + R;
				if (x >= need)
					can = true;
			}
		cout << "Case #" << it << ": ";
		if (can) cout << "YES" << endl;
		else	 cout << "NO" << endl;
	}
    return 0;
}
