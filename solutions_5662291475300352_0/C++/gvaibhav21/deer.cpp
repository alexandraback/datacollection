#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<map>
using namespace std;
 
#define sd(a) scanf("%d",&a)
#define pd(a) prlong longf("%d\n",(a))
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	int n,d,h,m,i,j,d1,h1,m1;
	double minn,maxx,mind,maxd;
	sd(t);
	for(j=1;j<=t;++j)
	{
		sd(n);
		if(n==1)
		{
			sd(d);
			sd(h);
			sd(m);
			printf("Case #%d: %d\n",j,0);
		}
		else if(n==2)
		{
			sd(d);
			sd(h);
			sd(m);
			sd(d1);
			sd(h1);
			sd(m1);
			if(m1>m)
			{
				minn=m;
				maxx=m1;
				mind=d;
				maxd=d1;
			}
			else
			{
				minn=m1;
				maxx=m;
				mind=d1;
				maxd=d;
			}
			if((360-mind)/360*minn+minn<=(360-maxd)/360*maxx)
			{
				printf("Case #%d: %d\n",j,1);
			}
			else
				printf("Case #%d: %d\n",j,0);
		}
	}
}