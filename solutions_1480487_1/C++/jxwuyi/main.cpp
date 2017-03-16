#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
using namespace std;

int S[300], X, N;

int id;

bool check(double t)
{
	double need = 0;
	int k = id;
	for(int i=0;i<N;++i)
	{
		if(i == k) continue;
		double R = S[k]+X*t-S[i];
		if(R < 0) continue;
		double a = R / X;
		need += a;
	}
	if(need + t > 1) return true;
	return false;
}

void run()
{
	scanf("%d", &N);
	X=0;
	for(int i=0;i<N;++i){
		scanf("%d", S+i);
		X=X+S[i];
	}
	for(int i=0;i<N;++i)
	{
		id = i;
		if(check(0))
		{
			printf(" 0.00000"); continue;
		}
		double lo = 0, hi = 1, mid;
		for(int loop = 1; loop <= 100; ++ loop)
		{
			mid = (lo + hi) * 0.5;
			if(!check(mid))
				lo = mid;
			else hi = mid;
		}
		printf(" %.6lf", (double)hi * 100);
	}
	printf("\n");
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int test;scanf("%d", &test);
	for(int no=1;no<=test;++no)
	{
		printf("Case #%d:",no);
		run();
	}
	return 0;
}