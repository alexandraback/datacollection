#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int ntest;
int N, X;
int s[200];
double ans[200];

int main()
{
	scanf("%d", &ntest);
	for(int test = 1;test <= ntest;++test)
	{
		scanf("%d", &N);
		for(int i = 0;i < N;++i)
			scanf("%d", &s[i]);
		X = 0;
		for(int i = 0;i < N;++i)
		{
			X += s[i];
		}
		double l = 0, r = X;
		double sum;
		for(int i = 0;i < 100;++i)
		{
			double m = (l + r) / 2;
			sum = 0;
			for(int i = 0;i < N;++i)
				sum += (m - s[i]) / X;
			if(sum < 1)
				l = m;
			else
				r = m;
		}
		printf("Case #%d:", test);
		bool has0 = 0;
		for(int i = 0;i < N;++i)
			if(s[i] > r)
			{
				ans[i] = 0;
				has0 = 1;
			}
			else
				ans[i] = (r - s[i]) / X;
		l = 0, r = X;
		for(int i = 0;i < 100;++i)
		{
			double m = (l + r) / 2;
			sum = 0;
			for(int i = 0;i < N;++i)
				if(ans[i] > 0)
					sum += (m - s[i]) / X;
			if(sum < 1)
				l = m;
			else
				r = m;
		}
		for(int i = 0;i < N;++i)
		{
			if(ans[i] > 0)
				ans[i] = (r - s[i]) / X;
			printf(" %.6lf", ans[i] * 100);
		}
		printf("\n");
	}
}
