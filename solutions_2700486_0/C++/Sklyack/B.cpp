#include <cstdio>

const int MAXN=20;
long long C[MAXN+1][MAXN+1]={0};

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	for(n=0; n<=MAXN; ++n)
	{
		C[n][0]=C[n][n]=1;
		for(k=1; k<n; ++k)
			C[n][k]=C[n-1][k-1]+C[n-1][k];
	}

	int T, t;
	int x, y, s, x1, y1, y2;
	scanf("%d", &T);
	for(t=1; t<=T; ++t)
	{
		scanf("%d%d%d", &n, &x, &y);
		if(x==0 && y==0)
		{
			printf("Case #%d: 1.0\n", t);
			continue;
		}
		x1=x;
		y1=y;
		while(x1!=0)
		{
			x1=x1<0 ? x1+1 : x1-1;
			++y1;
		}
		y1-=2;
		for(s=1, y2=0; y2<y1; y2+=2)
			s+=2*y2+3;
		if(s>n)
		{
			printf("Case #%d: 0.0\n", t);
			continue;
		}
		if(x==0)
		{
			s+=2*y2+3;
			printf("Case #%d: %.15lf\n", s<=n ? 1.0 : 0.0);
			continue;
		}
		if(y+y1+3<=n-s)
		{
			printf("Case #%d: 1.0\n", t);
			continue;
		}
		long long num, denom;
		num=0;
		for(k=0; k<=y && k<=n-s; ++k)
			num+=C[n-s][k];
		denom=(1<<(n-s));
		double p=1.0-num/(double)denom;
		printf("Case #%d: %.15lf\n", t, p);
	}
	return 0;
}
