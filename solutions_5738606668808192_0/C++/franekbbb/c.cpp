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
int a[MAXN];
int len;


set<LL> S;
LL chk(LL baza){
	LL dzi=100111;
	LL nr=0;
	FOR(i,1,len){
		nr*=baza;
		nr+=a[i];
	}
	if(baza==2&&S.find(nr)!=S.end()) {
		S.insert(nr);
		return -1;
	}
	S.insert(nr);
	if(dzi*dzi>nr) dzi=(LL)sqrt(nr)+10;
	if(dzi>=nr) dzi=nr-1;
	if(dzi>100111) dzi=100111;
	if(print)printf("%lld %lld %lld\n",baza,nr,dzi);
	for(LL i=2;i<=dzi;i++){
		if(print&&nr%i==0) printf("OK %lld\n",i);
		 if(nr%i==0) return i;
	}
	if(print)puts("ZLE");
	return -1;
}
	
main(){
	int test;scanf("%d",&test);
	FOR(casenr,1,test){
		srand(696969*time(NULL));
		int n,j;scanf("%d%d",&n,&j);
		len=n;
		printf("Case #%d:\n",casenr);
		int ilosc=0;
		while(ilosc<j){
			FOR(i,1,n){
				if(i==1||i==n){a[i]=1;continue;}
				if(n-i>16) a[i]=0;
				else a[i]=rand()%2;
			}
			//FOR(i,1,n) printf("%d",a[i]);puts("");
			vector<LL> ok;
			FOR(b,2,10){
				LL ob=chk((LL)b);
				ok.pb(ob);
				if(ob==-1) break;
			}
			if(ok.back()==-1) {continue;}
			FOR(i,1,n) printf("%d",a[i]);printf(" ");
			for(auto it:ok) printf("%lld ",it);
			puts("");
			ilosc++;
		}
	}
}
			
