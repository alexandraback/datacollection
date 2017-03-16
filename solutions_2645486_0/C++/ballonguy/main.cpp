#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdio>
#include<string.h>
#include<set>
#include<map>
using namespace std;

typedef long long Int;
#define FOR(i,a,b)  for(int i=(a);i<=(b);++i)
#define sz(s) (int)(s).size()
#define mp make_pair
#define pb push_back
#define sqr(x) (x)*(x)
void assert(bool x){if(!x)throw -1;}
const int inf = 1000000000;
const int MOD = 1000000007;
const double PI = acos(-1.0);


int dp[11][11];
int v[111];

int main()
{
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int tests;scanf("%d\n",&tests);
	FOR(test,1,tests){
		int n,r,e;
		cin>>e>>r>>n;
		FOR(i,1,n)cin>>v[i];

		memset(dp,0,sizeof(dp));
		dp[0][e]=0;
		int ans=0;
		FOR(i,0,n-1)FOR(j,0,e){
			FOR(nx,0,j)dp[i+1][min(e,j-nx+r)] = max(dp[i+1][min(e,j-nx+r)],dp[i][j]+v[i+1]*nx);
		}

		cout<<"Case #"<<test<<": ";
		FOR(i,0,e)ans=max(ans,dp[n][i]);
		cout<<ans<<endl;
	}
}