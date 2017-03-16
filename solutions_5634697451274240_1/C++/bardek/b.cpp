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

char S[123];
void flipuj(int j){
	reverse(S,S+j);
	fru(i,j) S[i]^='-'^'+';
}
int main(){
	int o;
	scanf("%d",&o);
	fru(oo,o){
		 printf("Case #%d: ",oo+1);
		 scanf("%s",S);
		 int n=strlen(S),ret=0;
		 S[n]='+';
		 fru(i,n) if(S[i]!=S[i+1]) ++ret;
		 printf("%d\n",ret);
	}
    return 0;
}
