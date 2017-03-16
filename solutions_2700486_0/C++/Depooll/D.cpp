#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#pragma comment(linker, "/STACK:10000000") 
#define md 1000000007

using namespace std;

int j,n,lev,x,y,all,t,test,i,p[1005],cur;
long long ok,wh;
long long dp[3000][3000],ans;


int main()
{
	ifstream f("input.txt");
	ofstream g("output.txt");
	
	p[0]=1;
	cur = 1;
	i = 0;
	while (p[i]<=1000000)
	{
		i++;
		p[i] = p[i-1] + 2*cur + 3;
		cur+=2;	
	}
	
	dp[1][0] = 1;
	for (i=1;i<3000;i++)
	{
		dp[1][i] = dp[1][i-1]; 	
	}
	
	for (i=2;i<3000;i++)
	{
		dp[i][0]=1;
		dp[i][1] = i;
	}
	
	for (i=2;i<3000;i++)
	 for (j=2;j<3000;j++) dp[i][j] = (dp[i-1][j]+dp[i][j-1]);
	
	all=i;
	g<<setprecision(10);
	
	f>>t;
	for (test = 1; test<=t;test++)
	{
		f>>n>>x>>y;
		lev = (abs(x) + abs(y))/2;
	//	g<<lev<<endl;
		g<<"Case #"<<test<<": ";
		g<<setprecision(10);
		if (n>=p[lev]) g<<"1.0000000"<<endl;
		else
		{
			if (x==0 && n==p[lev]) g<<"1.0000000"<<endl;
			else if (x==0 && n!=p[lev]) g<<"0.0000000"<<endl;
			else
			{
				if (n<=p[lev-1]) g<<"0.0000000"<<endl;
				else
				{
					n = n - p[lev-1];
					ans = 0;
					ok = 0;
					wh = 0;
					for (i=0;i<=n;i++) if (i<=2*lev && n-i<=2*lev)
					{
						wh+=dp[i+1][n-i];
						if ((x<0 && 2*lev+1-abs(x)<=i) || (x>0 && 2*lev+1-x<=n-i))
							 ok+= + dp[i+1][n-i];	
					}
					g<<1.0*ok/wh<<endl;
				}
			}	
		}
	
	}
}
