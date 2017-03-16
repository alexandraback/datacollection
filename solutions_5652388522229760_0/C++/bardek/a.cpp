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
const int MAXN = 1000006;
bool b[10];
int go(int _a){
	fru(i,10) b[i]=0;
	for(int a=_a;1;a+=_a){
		for(int q=a;q;q/=10) b[q%10]=1;
		bool ok=1;
		fru(i,10) ok&=b[i];
		if(ok) return a;
	}
}

int main(){
	//for(int i=1;i<=1000000;++i) printf("%d\n",go(i));
	int o;
	scanf("%d",&o);
	fru(oo,o){
		 printf("Case #%d: ",oo+1);
		 int a;
		 scanf("%d",&a);
		 if(a==0) puts("INSOMNIA");
		 else printf("%d\n",go(a));
	}
    return 0;
}
