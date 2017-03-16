#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int INF = 2147483647;
const int MAXN = 20005;
int T, N, M, S;
const double eps = 1e-10;
int X[1000];
double ans[1000];
bool ok(double x, int idx)
{
	double y = 1 - x;
	double score = X[idx] + S*x;
	
	for(int i = 0;i < N;++i)
	{
		if(i == idx)	continue;
		if(X[i] >= score)	continue;
		y -= (score - X[i]) / S;
	}
	if(y >= eps)	return false;
	return true;
}
double getans(int idx)
{
	double res;
	double l = 0, r = 1;
	while(l + eps <= r)
	{
		double mid = (l + r) / 2;
		if(ok(mid, idx))	
		{
			r = mid - eps;
			res = mid;
		}
		else l = mid + eps;
	}
	ans[idx] = res;
}
int main()
{
	int cas = 0;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		S = 0;
		for(int i = 0;i < N;++i)
		{
			scanf("%d",&X[i]);
			S += X[i];
		}
		for(int i = 0;i < N;++i)
		{
			getans(i);
		}
		printf("Case #%d:", ++cas);

		for(int i = 0;i < N;++i)
		{
			printf(" %.6lf", ans[i]*100);
		}
		printf("\n");
	}
	return 0;
}

