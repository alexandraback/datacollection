#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define pb push_back
#define sz(a) ((int)(a).size())
#define mp make_pair
#define fi first
#define se second

typedef pair<int,int> pint;
typedef long long ll;
typedef vector<int> vi;

#define INF 1234567

int n,dp[1000005];

int rev(int x)
{
	int r=0;
	while (x!=0)
	{
		r=r*10+(x%10);
		x/=10;
	}
	return r;
}

int f(int i)
{
	if (i==n)
		return 1;
	if (dp[i]!=-1)
		return dp[i];
	int ans=f(i+1)+1;
	int x=rev(i);
	if (x>i&&x<=n)
		ans=min(ans,1+f(x));
	return dp[i]=ans;
}

int main()
{
	int tc,cse=1;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%d",&n);
		dp[n]=1;
		for (int i=n-1; i>0; i--)
		{
			dp[i]=1+dp[i+1];
			int x=rev(i);
			if (x>i&&x<=n)
				dp[i]=min(dp[i],1+dp[x]);
		}
		printf("Case #%d: %d\n",cse,dp[1]);
		cse++;
	}
	return 0;
}
