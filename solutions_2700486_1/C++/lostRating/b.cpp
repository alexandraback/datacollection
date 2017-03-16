#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>

using namespace std;

int f[1000005];
double g[10005][10005];

int main()
{
	#ifdef LOCAL_TEST
		freopen("b.in","r",stdin);
		freopen("b.out","w",stdout);
	#endif
	int task;
	cin>>task;
	f[0]=1;
	for (int i=1;i<=1000000;++i) f[i]=f[i-1]+4;
	for (int tt=1;tt<=task;++tt)
	{
		cout<<"Case #"<<tt<<": ";
		int n,x,y;
		cin>>n>>x>>y;
		int z;
		if (x>=0) z=y+x;
		else z=y-x;
		z/=2;
		for (int i=0;i<z;++i) n-=f[i];
		double ans=0;
		if (n>0)
		{
			if (n>=f[z]) ans=1;
			else if (x!=0)
			{
				for (int i=0;i<=f[z]/2;++i)
					for (int j=0;j<=f[z]/2;++j)
					{
						g[i][j]=0;
						if (i==0 && j==0) g[i][j]=1;
						if (i+j>n) break;
						if (i!=0)
						{
							g[i][j]+=g[i-1][j]*0.5;
							if (j==(f[z]/2)) g[i][j]+=g[i-1][j]*0.5;
						}
						if (j!=0)
						{
							g[i][j]+=g[i][j-1]*0.5;
							if (i==(f[z]/2)) g[i][j]+=g[i][j-1]*0.5;
						}
						if (i+j==n && j>abs(y))
						{
			//				cerr<<i<<' '<<j<<endl;
							ans+=g[i][j];
						}
					}
			}
		}
		printf("%.10f\n",ans);
	}
	return 0;
}
