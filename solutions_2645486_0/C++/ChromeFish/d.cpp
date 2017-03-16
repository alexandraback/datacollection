#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
ifstream in("b.in");
ofstream out("b.out");
#define fo(i,j,k) for (i=j; i<=k; i++)
int dp[12][6];
int v[10000];
long long max(long long a, long long b)
{
	return (a>b)?a:b;
}
int main()
{
	int T, i;
	long long j, n, r, e, k ,p,ans;
	in>>T;
	fo(i, 1 ,T)
	{
		in>>e>>r>>n;
		fo(j, 0, n-1)
			in>>v[j];
		fo(j, 0, n)
			fo(k, 0, e)
			dp[j][k]=0;
		fo(j, 0, n-1)
			fo(k, 0, e)
			fo(p, 0, k)
		{
			long long rest=k-p+r;
			long long tmp=dp[j][k]+p*v[j];
			dp[j+1][min(rest,e)]=max(dp[j+1][min(rest,e)],tmp);
		}
		ans=0;
		fo(j,0,e)
			ans=max(ans,dp[n][j]);
		out<<"Case #"<<i<<": "<<ans<<endl;
	}
}