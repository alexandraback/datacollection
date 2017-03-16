#include <cstdio>

int u[10000000], o[1000000];

typedef long long LL;

int rev(int x)
{
	int y=0;
	while (x>0)
	{
		y=y*10+x%10;
		x/=10;
	}
	return y;
}

int bfs(int tt, int n)
{
	int q1=1, q2=1, q3, step=1, x;
	o[1]=1;
	if (n==1) return 1;
	while (q1<=q2)
	{
		q3=q2+1;
		++step;
		for (int i=q1; i<q3; ++i)
		{
			x=o[i]+1;
			if (x==n) return step;
			if (u[x]<tt)
			{
				u[x]=tt;
				o[++q2]=x;
			}
			x=rev(o[i]);
			if (x==n) return step;
			if (u[x]<tt)
			{
				u[x]=tt;
				o[++q2]=x;
			}
		}
		q1=q3;
	}
}

int main()
{
	int T;
	int n;
	scanf("%d", &T);
	for (int tt=1; tt<=T; ++tt)
	{
		scanf("%d", &n);
		printf("Case #%d: %d\n", tt, bfs(tt, n));
	}
	return 0;
}

