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


main(){
	int test;scanf("%d",&test);
	FOR(casenr,1,test){
		int k,c,s;scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d: ",casenr);
		int il=(k+c-1)/c;
		if(il>s) {puts("IMPOSSIBLE");continue;}
		LL suma=0;
		FOR(i,1,k){
			suma*=(LL)k;
			suma+=i-1;
			if(i%c==0) {printf("%lld ",suma+1);suma=0;}
		}
		if(k%c!=0) printf("%lld ",suma+1);
		puts("");
	}
}
