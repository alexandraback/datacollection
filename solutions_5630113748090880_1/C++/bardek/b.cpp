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

const int MAXH=2505;

int ile[MAXH];
int main(){
	int o;
	scanf("%d",&o);
	fru(oo,o){
		 printf("Case #%d: ",oo+1);
		 int n;
		 scanf("%d",&n);
		 fru(i,MAXH) ile[i]=0;
		 fru(i,2*n-1) fru(j,n){
			  int a;
			  scanf("%d",&a);
			  ile[a]++;
		 }
		 fru(i,MAXH) if(ile[i]%2) printf("%d ",i);
		 puts("");
	}
    return 0;
}
