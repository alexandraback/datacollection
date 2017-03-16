#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define drp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
int t[10008], n, s, p;
int xx1[10008], xx2[10008];
int main()
{
	//freopen("B-large.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	int cases;
	scanf("%d", &cases);
	int ans;
	rep(ca, cases)
	{
		ans = 0;
		scanf("%d%d%d", &n, &s, &p);
		rep(i, n) scanf("%d", t + i);
		rep(i, n)
		{
			if (t[i] % 3 == 2)
			{
				xx1[i] = (t[i] + 1) / 3;
				xx2[i] = xx1[i] + 1;
				if (xx2[i] - 2 < 0) xx2[i] = xx1[i];				
			}	
			else if (t[i] % 3 == 1)
			{
				xx1[i] = (t[i] + 2) / 3;
				xx2[i] = xx1[i];	
			}
			else
			{
				xx1[i] = t[i] / 3;
				xx2[i] = xx1[i] + 1;	
				if (xx2[i] - 2 < 0) xx2[i] = xx1[i];
			}
			if (xx1[i] < p && xx2[i] >= p && s > 0)
				s--, ans++;
			
			if (xx1[i] >= p) ans++;
		}
		printf("Case #%d: %d\n", ca, ans);
	}
	return 0;
}
