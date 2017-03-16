#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inft = 1000000009;
const int MOD = 1000000007;
const int MAXN = 1000;

bool pr[MAXN];
vi P;
int kontr[11];
int n;
int licz(LL x, int bas){
	for(int p: P){
		int w=0,tu=1;
		fru(i,n){
			if(x&(1LL<<i)) w+=tu;
			tu=tu*bas%p;
		}
		if(w%p==0) return p;
	}
	return -1;
}

int main(){
	fru(i,MAXN) pr[i]=1;
	for(int i=2;i<MAXN;i++) if(pr[i]){
		P.pb(i);
		for(int j=i*2;j<MAXN;j+=i) pr[j]=0;
	}
	int o;
	scanf("%d",&o);
	fru(oo,o){
		 printf("Case #%d:\n",oo+1);
		 int J;
		 scanf("%d%d",&n,&J);
		 for(LL x=(1LL<<(n-1))+1;J;x+=2){
			 bool ok=1;
			 for(int bas=2;bas<=10;++bas){
				 int w=licz(x,bas);
				 if(w==-1) {
					 ok=0;
					 break;
				 }
				 kontr[bas]=w;
			 }
			 if(ok==1){
				 for(int i=n-1;i>=0;--i) printf("%d",(x&(1LL<<i))?1:0);
				 for(int bas=2;bas<=10;++bas) printf(" %d",kontr[bas]); puts("");
				 J--;
			 }
		 }
	}
    return 0;
}
