#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 100005

using namespace std;

int main ()
{
	int T, iT;
	scanf("%d",&T);
	int M, N;
	static double prob[MAXN];
	static double a[MAXN];
	double res;
	for (iT = 0; iT < T; iT++)
	{
		scanf("%d %d",&M,&N);
		int i;
		for (i = 0; i < M; i++)
		{
			scanf("%lf",&(prob[i]));
		}
		double now = 1.0;
		double p;
		res = 1E9;
		for (i = 0; i <= M; i++)
		{
			if (i < M) p = now * (1.0 - prob[i]);
			else p = now;
			a[i] = p;
			if (i < M) now *= prob[i];
			//printf("a[%d] = %.6lf\n",i,a[i]);
		}
		for (i = 1; i <= M; i++) a[i] += a[i-1];
		//Keep typing
		p = (a[M-1]) * (double)(N - M + N + 2) + (a[M] - a[M-1]) * (double)(N - M + 1);
		//printf("%.6lf\n",p);
		if ((p-1E-9) < res) res = p;
		//Give up
		p = (double)(N + 2);
		//printf("%.6lf\n",p);
		if ((p-1E-9) < res) res = p;
		//Try to leave i symbols
		for (i = 1; i < M; i++)
		{
			p = (a[i-1]) * (double)(M - i + N - i + N + 2) + (a[M] - a[i-1]) * (double)(M - i + N - i + 1);
			//printf("%.6lf\n",p);
			if ((p-1E-9) < res) res = p;
		}
		printf("Case #%d: %.6lf\n",iT+1,res);
	}
	return 0;
}
