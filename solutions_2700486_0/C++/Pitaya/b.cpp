#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

long double c[4000][4000];

int main()
{
	//cout.precision(6);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	for (int i = 0; i < 4000; ++i)
	{
		c[i][0]=1;
		c[i][i]=1;
		for (int j = 1; j <= i-1; ++j)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ++ii)
	{
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		printf("Case #%d: ", ii);
		int cs;
		for (cs = 1; 2*cs*cs-cs <= n; ++cs){}
		cs--;
		int left=n-(2*cs*cs-cs);
		cs++;
		if(abs(x)+abs(y)<cs*2-2)printf("1.0\n");
		if(abs(x)+abs(y)>=cs*2)printf("0.0\n");
		if(abs(x)+abs(y)==cs*2-2)
		{
			if(x==0)printf("0.0\n");
			else
			{
				if (y+1+2*cs-2<=left)printf("1.0\n");
				else
				{
					long double ans=0;
					for (int i = y+1; i <=2*cs-2; ++i)
					{
						ans=ans+c[left][i];
					}
					ans=ans*exp(-log(2)*left);
					if(ans==0)printf("0.0\n");
					else cout<<ans<<endl;
				}
			}
		}
	}
	return 0;
}