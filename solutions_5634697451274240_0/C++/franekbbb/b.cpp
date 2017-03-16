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
const int MAXN=1001;

char a[MAXN];


main(){
	int test;scanf("%d",&test);
	FOR(casenr,1,test){
		scanf("%s",a+1);
		int as=strlen(a+1);
		int stan=0;
		int wyn=0;
		FORD(i,as,1){
			int st1=(a[i]=='-')?1:0;
			//printf("%d %c %d %d\n",i,a[i],stan,st1);
			if((stan^st1)==1) stan^=1,wyn++;
		}
		printf("Case #%d: %d\n",casenr,wyn);
	}
}
