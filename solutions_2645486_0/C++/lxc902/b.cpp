#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int,int> PII;
const double eps = 1e-7;
const double PI = acos(-1.0);
const int oo = 1<<29;

const int N = 101111;

void chk(int &a,int b) {
	if(a<0) a=b;
	else if(a<b) a=b;
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.ou","w",stdout);

	int T; scanf("%d",&T);
	for(int ka=1;ka<=T;ka++) {
		int E,R,n;
		int v[12];
		cin>>E>>R>>n;
		for(int i=1;i<=n;i++) cin>>v[i];
		int dp[12][6];
		mem(dp,-1);
		dp[0][E]=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<=E;j++) if(dp[i][j]>=0) {
				for(int k=0;k<=j;k++) {
					int e=j-k+R;
					e=min(e,E);
					chk(dp[i+1][e],dp[i][j]+k*v[i+1]);
				}
			}
		}
		int ans=0;
		for(int i=0;i<=E;i++) if(dp[n][i]>=0) ans=max(ans,dp[n][i]);
		cout<<"Case #"<<ka<<": "<<ans<<endl;
	}

	return 0;
}
