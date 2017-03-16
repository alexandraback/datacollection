#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#define PB push_back

#define MAXN 110
#define MAXM 110

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;

int p1[MAXN],p2[MAXM];
LL v1[MAXN],v2[MAXM],c1[105][MAXM],c2[105][MAXM],f[MAXN][MAXM];

LL min(LL x,LL y)
{
	if (x>y) return y; else return x;
}

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	int TT;
	cin>>TT;
	for (int T=1;T<=TT;T++)
	{
		cout<<"Case #"<<T<<": ";
		int n,m;
		cin>>n>>m;
		
		for (int i=1;i<=100;i++)
		{
			c1[i][0]=c2[i][0]=0;
		}
		
		for (int i=1;i<=n;i++)
		{
			cin>>v1[i]>>p1[i];
			for (int j=1;j<=100;j++)
				if (p1[i]==j) c1[j][i]=c1[j][i-1]+v1[i]; else c1[j][i]=c1[j][i-1];			
		}
		
		for (int i=1;i<=m;i++)
		{
			cin>>v2[i]>>p2[i];
			for (int j=1;j<=100;j++)
				if (p2[i]==j) c2[j][i]=c2[j][i-1]+v2[i]; else c2[j][i]=c2[j][i-1];
		}
		
		f[0][0]=0;
		LL ans=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				LL temp=0;
				for (int i1=1;i1<=i;i1++)
					for (int j1=1;j1<=j;j1++)
					{
						LL x=min(c2[p2[j]][j] - c2[p2[j]][j1-1] , c1[p2[j]][i] - c1[p2[j]][i1-1]) + f[i1-1][j1-1];
						if (x>temp) temp=x;
					}
				f[i][j]=temp;
				if (temp>ans) ans=temp;
			}
		
		cout<<ans<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
