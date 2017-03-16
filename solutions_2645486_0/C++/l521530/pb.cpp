
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define N 20010
typedef long long int LL;

using namespace std;

int e,r,n;
int a[N];
LL dp[2][N];
int th[N];

void go(){
	static int zi=0;
	scanf("%d%d%d",&e,&r,&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);

	int tn=0;
	for(int i=0;i<=n;i++){
		if( i*r<e ) th[tn++]=i*r;
		if( e-i*r>0 ) th[tn++]=e-i*r;
	}
	sort(th,th+tn);
	tn = unique(th,th+tn)-th;

	//printf("tn=%d ",tn);for(int i=0;i<tn;i++)printf("%d ",th[i]);puts("");

	int pre=0, now=1;
	memset(dp,0,sizeof(dp));
	for(int ai=0; ai<n; ai++){
		LL v=a[ai];
		LL mx=0;
		int st=tn-1,ed=tn-1;
		for(int st=tn-1,ed=tn-1; st>=0; st--){
			while(ed>=0 && th[ed]+r>=th[st]){
				mx = max(mx, dp[pre][ed] + v*th[ed]);
				ed--;
			}
			//printf("%d %d =%lld\n",ai,st,mx);
			dp[now][st]=mx-v*max(0, th[st]-r);
		}
		//printf("Lv %d\n",ai);
		//for(int i=0;i<tn;i++)printf("%lld ",dp[now][i]);puts("");
		swap(pre,now);
	}
	LL ans=0;
	for(int i=0;i<tn;i++) ans = max(ans,dp[pre][i]);
	printf("Case #%d: %lld\n",++zi,ans);
}

int main(){

	int zn;
	scanf("%d",&zn);
	for(int zi=0;zi<zn;zi++){
		go();
	}

	return 0;
}
