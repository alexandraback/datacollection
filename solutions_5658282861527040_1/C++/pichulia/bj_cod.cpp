#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int a,b,c;
int d[99];
int e[99];
int f[99];

int p[99][99];
int q[99][99];
int r[99][99];
int pl,ql,rl;
void input()
{
	int i, j;
	scanf("%d %d %d",&a,&b,&c);
	if(a<b)a^=b^=a^=b;
	for(i=0;i<30;i++)
	{
		d[i] = a%2;
		a/=2;
	}
	for(i=0;i<30;i++)
	{
		e[i] = b%2;
		b/=2;
	}
	for(i=0;i<30;i++)
	{
		f[i] = c%2;
		c/=2;
	}
	pl=ql=rl=0;

	for(i=30;i>=0;i--)
	{
		if(d[i] == 1)
		{
			for(j=i;j<30;j++)
				p[pl][j] = d[j];
			p[pl][i] = 0;
			for(j=i-1;j>=0;j--)
				p[pl][j] = 2;
			pl++;
		}
	}
	for(i=30;i>=0;i--)
	{
		if(e[i] == 1)
		{
			for(j=i;j<30;j++)
				q[ql][j] = e[j];
			q[ql][i] = 0;
			for(j=i-1;j>=0;j--)
				q[ql][j] = 2;
			ql++;
		}
	}
	for(i=30;i>=0;i--)
	{
		if(f[i] == 1)
		{
			for(j=i;j<30;j++)
				r[rl][j] = f[j];
			r[rl][i] = 0;
			for(j=i-1;j>=0;j--)
				r[rl][j] = 2;
			rl++;
		}
	}
}
long long int cal(int si, int sj, int sk)
{
	int i, j, k, l;
	long long int res=1;
	for(l=29;l>=0;l--)
	{
		i=p[si][l];
		j=q[sj][l];
		k=r[sk][l];
		if(i==2)
		{
			if(j==2)
			{
				if(k==2)
				{
					res *= 4;
				}
				else if(k==1)
					res *= 1;
				else
					res *= 3;
			}
			else if(j==1)
			{
				if(k==2)
				{
					res *= 2;
				}
				else if(k==1)
					res *= 1;
				else
					res *= 1;
			}
			else
			{
				if(k==2)
				{
					res *= 2;
				}
				else if(k==1)
					res *= 0;
				else
					res *= 2;
			}
		}
		else if(i==1)
		{
			if(j==2)
			{
				if(k==2)
				{
					res *= 2;
				}
				else if(k==1)
					res *= 1;
				else
					res *= 1;
			}
			else if(j==1)
			{
				if(k==2)
				{
					res *= 1;
				}
				else if(k==1)
					res *= 1;
				else
					res *= 0;
			}
			else
			{
				if(k==2)
				{
					res *= 1;
				}
				else if(k==1)
					res *= 0;
				else
					res *= 1;
			}
		}
		else
		{
			if(j==2)
			{
				if(k==2)
				{
					res *= 2;
				}
				else if(k==1)
					res *= 0;
				else
					res *= 2;
			}
			else if(j==1)
			{
				if(k==2)
				{
					res *= 1;
				}
				else if(k==1)
					res *= 0;
				else
					res *= 1;
			}
			else
			{
				if(k==2)
				{
					res *= 1;
				}
				else if(k==1)
					res *= 0;
				else
					res *= 1;
			}
		}
	}
	return res;
}
void process()
{
	long long int res=0;
	int i, j, k;
	for(i=0;i<pl;i++)
		for(j=0;j<ql;j++)
			for(k=0;k<rl;k++)
			{
				res += cal(i,j,k);
			}
			printf("%lld",res);
}
int main()
{
	int t, tv;
	freopen("B-large.in","rt",stdin);
	freopen("B-large.out","wt",stdout);
	scanf("%d",&t);
	tv = 0;
	while(t--)
	{
		tv++;
		input();
		printf("Case #%d: ",tv);
		process();
		printf("\n");
	}
}