#include<bits/stdc++.h>
#define rep(i,x,y) for(i=x;i<y;i++)
#define rrep(i,x,y) for(i=x;i>=y;i--)
#define trv(y,x) for(typeof(x.rbegin())y=x.rbegin();y!=x.rend();y++)
#define pb(f) push_back(f)
#define sc(a) scanf("%d",&a)
#define scs(a) scanf("%s",a)
using namespace std;
//#include<windows.h>
FILE *fin = freopen("1.in","r",stdin);
FILE *fout = freopen("1.txt","w",stdout);

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pii > vpii;
int dp[1000002];
int reverse(int tar)
{
	int i,j,k;
	int num=0;
	while(tar!=0)
	{
		num=num*10+tar%10;
		tar/=10;
	}
	return num;
}
int main()
{
	int t,casse=1,i,j,n,k;
	sc(t);
	dp[1]=1;
	rep(i,2,1000001)
	{
		dp[i]=10000000;
	}
	rep(i,2,1000001)
	{
		j=reverse(i);
		dp[i]=min(1+dp[i-1],dp[i]);
		if(j>i)
		{
			dp[j]=min(1+dp[i],dp[j]);
		}
		
	//	cout<<i<<" "<<j<<" "<<dp[i]<<endl;
	}
	while(t--)
	{
		sc(n);
		printf("Case #%d: %d\n",casse,dp[n]);
		casse++;
	}
}
