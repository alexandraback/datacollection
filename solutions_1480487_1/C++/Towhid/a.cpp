#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define EPS 1e-12

#define SZ 205

using namespace std;

int scr[SZ];
double res[SZ];
vector<int> vv;

bool isok(double mid, int ii, int n, int tot)
{
	int i, j;
	vv.clear();
	for(j = 0; j < n; j++)
	{
		if(j == ii)
		{
			continue;
		}
		vv.push_back(scr[j]);
	}
	sort(vv.begin(), vv.end());
	double rem = (1.0 - mid) * tot;
	double mn = vv[0];
	double xx = mid * tot + scr[ii];
	for(i = 0; i < vv.size() - 1; i++)
	{
		if(vv[i] > xx)
			return false;
		double ext = vv[i + 1] - vv[i];
		if(ext * (i + 1) > rem)
		{
			mn = vv[i] + rem / (i + 1);
			rem = 0.0;
			break;
		}
		else
		{
			vv[i] = vv[i + 1];
			mn = vv[i];
			rem -= (ext * (i + 1));
		}
	}
	if(rem > 0)
	{
		mn = mn + rem / (n - 1);
	}
	if(xx >= mn)
		return true;
	return false;
}

double getval(int i, int n, int tot)
{
	double lo, hi, mid;
	lo = 0.0;
	hi = 1.0;
	int x = scr[i];
	int y = tot - x;
	while(hi - lo > EPS)
	{
		mid = (hi + lo) / 2.0;
		if(isok(mid, i, n, tot))//mid * tot + x >= ((1.0 - mid) * tot + y) / (n - 1))
		{
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}
	return (hi * 100.0);
}

int main()
{
	int i, j, k, n, a, b, tot;
	freopen("a-large.in", "rt", stdin);
	freopen("a-large.out", "wt", stdout);

	int inp, kase;
	scanf("%d", &inp);
	//long double pp = 0.1;

	for(kase = 1; kase <= inp; kase++)
	{
		scanf("%d", &n);
		tot = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &scr[i]);
			tot += scr[i];
		}
		
		for(i = 0; i < n; i++)
		{
			res[i] = getval(i, n, tot);
		}
		
		printf("Case #%d:", kase);
		for(i = 0; i < n; i++)
		{
			printf(" %.6lf", res[i]);
		}
		printf("\n");
	}
	return 0;
}
