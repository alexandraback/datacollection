#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>

using namespace std;

int T,n,x,y,s,ts,i,l,r,j;
double d[4000][4000],ans;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&x,&y);
		s=(abs(x)+abs(y))/2;
		if(2*s*s+3*s+1<=n)
		{
			printf("Case #%d: 1.0\n",++ts);
			continue;
		}
		if(2*s*s-s>=n)
		{
			printf("Case #%d: 0.0\n",++ts);
			continue;
		}
		n-=2*s*s-s;
		s*=2;
		if(x<0)
		{
			l=y+1;
			r=s;
		}
		else
		{
			l=n-s;
			r=n-y-1;
		}
		ans=0;
		d[0][0]=1;
		for(i=1;i<=n;i++)
			for(j=max(0,i-s);j<=s && j<=i;j++)
			{
				d[i][j]=0;
				if(j)
					d[i][j]+=d[i-1][j-1]*(i-j==s?1:0.5);
				if(i-j)
					d[i][j]+=d[i-1][j]*(j==s?1:0.5);
			}
		for(i=max(0,n-s);i<=s && i<=n;i++)
			if(i>=l && i<=r)
				ans+=d[n][i];
		printf("Case #%d: %.12lf\n",++ts,ans);
	}
	return 0;
}