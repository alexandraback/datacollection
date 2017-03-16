#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

double sumfact(int l, int r, int n)
{
	int ll = min(l, n-l);
	double ans = 0;
	double ml = 1;
	for(int i = 1; i <= ll; ++i)
		ml *= (.0+n-ll+i) / ll;
	for(int i = l; i <= r; ++i)
	{
		ans += ml;
		ml *= (.0 + n-i)/(i+1);
	}
	return ans;
}

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, n, x, y;
	double p;
	cin >> t;
	for(int tt = 0; tt < t; ++tt)
	{
		cin >> n >> x >> y;


		int diag = (y + abs(x)) / 2;
		int ob = (2*diag-1)*diag;

		if(!x)
		{
			ob += 4*diag;
			if(n < ob) printf("Case #%d: %.7lf\n", tt+1, 0.0);
			else printf("Case #%d: %.7lf\n", tt+1, 1.0);
			continue;
		}

		n -= ob;
		int b = y+1;
		if(n < b)
			printf("Case #%d: %.7lf\n", tt+1, 0.0);
		else 
		{
			int r = 2*diag;
			if(b+r <= n)
				printf("Case #%d: %.7lf\n", tt+1, 1.0);
			else
			{
				double ans = sumfact(b, min(r, n), n) / sumfact(max(0, n-r), min(r, n), n);
				printf("Case #%d: %.7lf\n", tt+1, ans);
			}
		}
	}


	return 0;
}