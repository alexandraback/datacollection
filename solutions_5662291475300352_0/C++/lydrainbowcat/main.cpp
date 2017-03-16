#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<cmath>
using namespace std;
int T, n, ans;
int d1, h1, m1, d2, h2, m2;
double eps = 1e-10;

int main()
{
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("C-small-1-attempt0.out", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n;
		if (n == 1)
		{
			ans = 0;
			cin >> d1 >> h1 >> m1;
			if (h1 == 1)
			{
				ans = 0;
				printf("Case #%d: %d\n", t, ans);
				continue;
			}
			h1 = 1;
			d2 = d1, h2 = 1, m2 = m1 + 1;
		}
		else{
			cin >> d1 >> h1 >> m1;
			cin >> d2 >> h2 >> m2;	
		}
		if (d1 > d2) swap(d1, d2), swap(h1, h2), swap(m1, m2);
		int f1, f2;
		double t1, t2;
		if (m1 == m2) ans = 0;
		else if (m1 < m2)
		{
			f2 = 360 - d2;
			f1 = d2 - d1;
			t2 = f2 / 360.0 * m2;
			t1 = f1 / (360.0 / m1 - 360.0 / m2);
			if (t1 + eps > t2) ans = 0;
			else{
				t2 -= t1;
				t1 = 360 / (360.0 / m1 - 360.0 / m2);
				ans = t1 < t2 + eps;
			}
		}
		else{
			f1 = 360 - d1;
			f2 = d1 + 360 - d2;
			t1 = f1 / 360.0 * m1;
			t2 = f2 / (360.0 / m2 - 360.0 / m1);
			ans = t2 < t1 + eps;
		}
		printf("Case #%d: %d\n", t, ans);
	}
}