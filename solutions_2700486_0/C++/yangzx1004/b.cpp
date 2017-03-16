#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

#pragma comment(linker, "/STACK:1024000000,1024000000")
#define PB push_back
#define MP make_pair

const double pi=2.0*asin(1.0),eps=1e-12;
const int maxn=3300,maxm=1100000,inf=0x3f3f3f3f;

long double bin[maxn],c[maxn][maxn];

int main()
{
	bin[0]=1.0;
	int i;
	for(i=1;i<maxn;i++)bin[i]=bin[i-1]*2.0;
	int t,x,y,z,n,j,ca=1;
	for(i=0;i<maxn;i++)
	{
		c[i][i]=1;
		c[i][1]=i;
		c[i][0]=1;
	}
	for(i=2;i<maxn;i++)
	{
		for(j=2;j<i;j++)
		{
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	double ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&y);
		if(x<0)x=-x;
		if(y<0)y=-y;
		z=x+y;
		for(i=0;i<z;i+=2)
		{
			n-=2*i+1;
		}
		if(n<=0)
		{
			ans=0.0;
		}
		else if(n>=z+z+1)
		{
			ans=1.0;
		}
		else
		{
			ans=0.0;
			if(y!=z)
			{
				if(n>z)
				{
					int temp=n-z;
					n-=2*temp;
					y-=temp;
					z-=temp;
				}
				double dx=0.0;
				for(i=0;i<=z&&i<=n;i++)
				{
					if(i>y)ans+=c[n][i];
					dx+=c[n][i];
				}
				ans/=dx;
			}
		}
		printf("Case #%d: %.10lf\n",ca++,ans);
	}
	return 0;
}

