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
const int MAXN = 1006;

bool byl[MAXN];
int F[MAXN];
vi V[MAXN];

int najdl(int u,int par){
	 int ret=0;
	 tr(it,V[u]) if(*it!=par) ret=max(ret,najdl(*it,u));
	 return ret+1;
}

int main(){
	 int o;
	 scanf("%d",&o);
	 fru(oo,o){
		  printf("Case #%d: ",oo+1);
		  int n;
		  scanf("%d",&n);
		  fru(i,n) scanf("%d",&F[i]);
		  fru(i,n) F[i]--;
		  fru(i,n) V[i].clear();
		  fru(i,n) V[F[i]].pb(i);
		  int ret=0;
		  fru(i,n){
				fru(j,n) byl[j]=0;
				int q=i;
				int t=0;
				while(1){
					 if(byl[q]){
						  if(q==i) ret=max(ret,t);
						  break;
					 }
					 byl[q]=1;
					 q=F[q];
					 ++t;
				}
		  }
		  int sum=0;
		  fru(i,n) if(F[F[i]]==i && i<F[i]){
				int a=najdl(i,F[i]),
					 b=najdl(F[i],i);
				sum+=a+b;
		  }
		  ret=max(ret,sum);
		  printf("%d\n",ret); 
	 }
	 return 0;
}
