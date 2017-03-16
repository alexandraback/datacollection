#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int maxn=2000;
long long n,m,num;
long long a[maxn][2],b[maxn][2];
long long f[maxn][maxn];
void solve()
{
	memset(f,0,sizeof(f));

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if (a[i][1]==b[j][1])
			{
				long long sum1=0;
				for (int l=i; l>=1; l--)
				{
					if (a[l][1]==a[i][1]) sum1+=a[l][0];
					long long sum2=0;
					for (int k=j; k>=1; k--){
						if (b[k][1]==b[j][1]) sum2+=b[k][0];
						f[i][j]=max(f[i][j],f[l-1][k-1]+min(sum1,sum2));
					}
				}
			}
		}
	
	cout<<f[n][m]<<endl;
}
void init()
{
	cin>>num;
	for (int i=1; i<=num; i++)
	{
		cin>>n>>m;
		for (int j=1; j<=n; j++) cin>>a[j][0]>>a[j][1];
		for (int j=1; j<=m; j++) cin>>b[j][0]>>b[j][1];
		cout<<"Case #"<<i<<": ";
		solve();
	}
}
int main()
{
	freopen("CCC.in","r",stdin);
	freopen("CCC.out","w",stdout);
	init();
	return 0;
}
