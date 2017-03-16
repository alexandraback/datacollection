#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int t;
double f[5000][5000];
int x,y,n,now,l,h,ans,p,k;
double tot;
int main()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&t);
	for(int o=1;o<=t;++o)
	{
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		scanf("%d%d",&x,&y);
		if (x<0) x=-x;
		printf("Case #%d: ",o);
		now=0;
		for(int i=1;now<=n;i+=2)
		{
			ans=now;
			l=i-2;
			now=(i+1)*i/2;
		}
		k=n-ans;
		p=l-1;
		if (x+y<=p) puts("1.000000");
		else
		if (x+y>p+2) puts("0.000000");
		else
		{
			tot=0;
			h=1;
			f[0][0]=1;
			for(int i=1;i<=p/2+1;++i)
				h=h*2;
			for(int i=1;i<=k;++i)
			for(int j=0;j<=i;++j)
			{
				if (j>0 && j<=h) 
				{
					if (i-j<h)
						f[j][i-j]+=f[j-1][i-j]/2;
					else
						f[j][i-j]+=f[j-1][i-j];
				}
				if (i-j>0 && i-j<=h)
				{
					if (j<h)
						f[j][i-j]+=f[j][i-j-1]/2;
					else
						f[j][i-j]+=f[j][i-j-1];
				}
			}
			for(int i=y+1;i<=k;++i)
				tot+=f[i][k-i];
			printf("%.6lf\n",tot);
		}
	}
}