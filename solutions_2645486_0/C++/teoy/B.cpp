#include "iostream"
#include "cstring"
#include "cstdio"
using namespace std;
const int N = 1010;
const int inf = 10000000;
int dp[N][N];
int v[N];
int T,E,R,n;
int gao(int now,int val)
{
	if(now==n){
		return val*v[n];
	}
	int ans=0;
	for(int i=0;i<=val;i++){
		ans=max(gao(now+1,min(E,val-i+R))+i*v[now],ans);
	}
	return ans;
}
int main(void)
{
	int g=0;
	freopen("B-small-attempt0.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&E,&R,&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&v[i]);
		}
		printf("Case #%d: %d\n",++g,gao(1,E));
	}
	return 0;
}