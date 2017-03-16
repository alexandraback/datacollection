#include<bits/stdc++.h>
#define FOR(i,s,e) for(int i=(s);i<=(e);i++)
#define FORD(i,s,e) for(int i=(s);i>=(e);i--)
#define FOREACH(i,c) for( __typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define ALL(k) (k).begin(),(k).end()
#define e1 first
#define e2 second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const bool print=false;
const int MAXN=69;
int tt[MAXN][MAXN];
LL dp[MAXN];

main(){
	int test;scanf("%d",&test);
	FOR(casenr,1,test){
		int n;LL k;scanf("%d%lld",&n,&k);
		dp[n]=dp[n-1]=1;
		FORD(i,n-2,1) dp[i]=dp[i+1]*2LL;
		FOR(i,2,n)
			FOR(j,1,n) 
				tt[i][j]=(i<j)?1:0;
		LL obw=0;
		tt[1][1]=0;
		FOR(i,2,n) {
			if(obw+dp[i]<=k) obw+=dp[i],tt[1][i]=1;
			else tt[1][i]=0;
		}
		printf("Case #%d: ",casenr);
		if(obw<k) {puts("IMPOSSIBLE");continue;}
		puts("POSSIBLE");
		FOR(i,1,n){
			FOR(j,1,n) printf("%d",tt[i][j]);
			puts("");
		}
	}
}
