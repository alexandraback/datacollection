//#include<cstdio>
//#include<cstdlib>
//#include<cstring>
//#include<cmath>
//#include<iostream>
//#include<vector>
//#include<set>
//#include<queue>
//#include<map>
//#include<algorithm>
//#include<stack>
//#include<string>
//#define MAX 200000
//#define INF 0x3f3f3f3f
//using namespace std;
//typedef long long LL;
//const LL mx=1000000000000000000LL;
//int dp[MAX+10];
//int num[55];
//int main(void)
//{
////	freopen("A-large.in","r",stdin);
////	freopen("a_large.out","w",stdout);
//	int t,cas=0;
//	scanf("%d",&t);
//	while(t--)
//	{
//		LL b,m;
//		scanf("%lld%lld",&b,&m);
//		int flag=0;
//		LL mt=0LL;
//		for(int i=1;i<=b-2;i++){
//			if(mx/(LL)i<mt){flag=1;break;}
//			mt*=(LL)i;
//			mt+=(LL)i;
//		}
//		mt++;
//		if(mt>=m)flag=1;
//		printf("Case #%d: ",++cas);
//		if(!flag)puts("IMPOSSIBLE");
//		else {
//			puts("POSSIBLE");
//
//		}
//	}
//	return 0;
//}
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
#include<stack>
#include<string>
#define MAX 200000
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int dp[MAX+10];
int num[55];
int mp[30][30];
int vis[10];
int ans=0;
int dfs(int u,int n,int m){
	if(ans==m)return 0;
	if(u==n){
		ans++;
		return 1;
	}
	for(int i=2;i<=n;i++){
		if(!vis[i]){
		vis[i]=1;
		mp[u][i]=1;
		if(!dfs(i,n,m))mp[u][i]=0;
		vis[i]=0;
		}
	}
	return 1;
}
int main(void)
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B_samll.out","w",stdout);
	int t,cas=0;
	scanf("%d",&t);
	while(t--)
	{
		int b,m;
		scanf("%d%d",&b,&m);
		memset(vis,0,sizeof(vis));
		memset(mp,0,sizeof(mp));
		dfs(1,b,m);
		printf("Case #%d: ",++cas);
		if(ans<m){
			puts("IMPOSSIBLE");
			//continue;
		}
		else {
			puts("POSSIBLE");
			for(int i=1;i<=b;i++){
				for(int j=1;j<=b;j++){
				printf("%d",mp[i][j]);
				if(j!=b)printf(" ");
				else puts("");
				}
			}

		}

	}
	return 0;
}
