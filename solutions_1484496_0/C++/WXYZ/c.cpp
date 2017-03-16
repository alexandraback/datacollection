#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
int a[500],b[20],p[500];
struct node
{
	long long s;
	int z;
};
bool operator <(const node &a,const node &b)
{
	return a.s<b.s;
}
node c[1100000];
void outp(int z)
{
	int t=0,i;
	for (i=0;i<20;i++)
	{
		if ((z&(1<<i))!=0)
		{
			if (t!=0)
				printf(" ");
			else
				t=1;
			printf("%d",b[i]);
		}
	}
	printf("\n");
	return;
}
bool check()
{
	int i;
	long long s;
	for (int z=(1<<20)-1;z>0;z--)
	{
		s=0;
		for (i=0;i<20;i++)
		{
			if ((z&(1<<i))!=0)
				s+=b[i];
		}
		c[z-1].s=s;
		c[z-1].z=z;
	}
	sort(c,c+((1<<20)-1));
	for (i=1;i<=(1<<20)-2;i++)
	{
		if (c[i].s==c[i-1].s)
		{
			outp(c[i].z);
			outp(c[i-1].z);
			return 1;
		}
	}
	return 0;
}
int main()
{
	int t,tt,n,i,j;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d",a+i);
			p[i]=i;
		}
		printf("Case #%d:\n",tt);
		for (j=0;j<20;j++)
		{
			random_shuffle(p,p+n);
			for (i=0;i<20;i++)
				b[i]=a[p[i]];
			if (check())
				break;
		}
		if (j==20)
			printf("Impossible\n");
	}
	return 0;
}