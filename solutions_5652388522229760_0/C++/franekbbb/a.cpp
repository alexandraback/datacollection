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
typedef pair<PII,int> PPI;
typedef pair<LL,LL> PLL;
const bool print=false;
const int MAXN=111;
int dp[MAXN];
int il=0;

void zerow(){
	FOR(i,0,9) dp[i]=0;
	il=0;
}
bool ustaw(LL k){
	while(k>0){
		if(dp[k%10]==0) il++;
		dp[k%10]++;
		k/=10;
	}
	if(il==10) return true;
	return false;
}

main(){
	int test;scanf("%d",&test);
	int end=100111000;
	FOR(casenr,1,test){
		LL n;scanf("%lld",&n);
		printf("Case #%d: ",casenr);
		if(n==0){puts("INSOMNIA");continue;}
		zerow();
		for(LL i=1;i<=end;i++){
			if(ustaw(i*n)) {printf("%lld\n",i*n);break;}
		}
	}
}
		

