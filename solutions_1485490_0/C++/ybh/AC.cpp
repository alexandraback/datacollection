#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#define PB push_back

#define MAXN 5
#define MAXM 110

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;

int p1[MAXN],p2[MAXM];
LL v1[MAXN],v2[MAXM],c[MAXN][MAXM];

LL min(LL x,LL y)
{
	if (x>y) return y; else return x;
}

int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	int TT;
	cin>>TT;
	for (int T=1;T<=TT;T++)
	{
		cout<<"Case #"<<T<<": ";
		int n,m;
		cin>>n>>m;
		for (int i=1;i<=n;i++)
			cin>>v1[i]>>p1[i];
		
		if (n==3)
		{
			if (p1[1]==p1[2] && p1[2]==p1[3])
			{
				v1[1]+=v1[2]+v1[3];
				n=1;
			}
			else
			{
				if (p1[2]==p1[3])
				{
					v1[2]+=v1[3];
					n=2;
				}
				if (p1[1]==p1[2])
				{
					v1[1]+=v1[2];
					n=2;
					v1[2]=v1[3];
					p1[2]=p1[3];
				}
			}
		}
		else
		{
			if (n==2 && p1[1]==p1[2])
			{
				v1[1]+=v1[2];
				n=1;
			}
		}
		
		c[1][0]=c[2][0]=c[3][0]=0;
		for (int i=1;i<=m;i++)
		{
			cin>>v2[i]>>p2[i];
			for (int j=1;j<=n;j++)
				if (p2[i]==p1[j]) c[j][i]=c[j][i-1]+v2[i]; else c[j][i]=c[j][i-1];
		}
		/*for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
				cout<<c[i][j]<<' ';
			cout<<endl;
		}*/
		
		LL ans=-1;
		if (n==3)
		{
			for (int i=0;i<=m;i++)
				for (int j=i;j<=m;j++)
				{
					LL x=min(v1[1],c[1][i])+min(v1[2],c[2][j]-c[2][i])+min(v1[3],c[3][m]-c[3][j]);
					if (x>ans) ans=x;
				}
			if (p1[1]==p1[3])
			{
				LL x=min(v1[1]+v1[3],c[1][m]);
				if (x>ans) ans=x;
			}
		}
		if (n==2)
		{
			for (int i=0;i<=m;i++)
			{
				LL x=min(v1[1],c[1][i])+min(v1[2],c[2][m]-c[2][i]);
				if (x>ans) ans=x;
			}
		}
		if (n==1)
		{
			ans=min(v1[1],c[1][m]);
		}
		cout<<ans<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
