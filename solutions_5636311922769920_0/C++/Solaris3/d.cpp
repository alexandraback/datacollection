#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;

void solve() {
	int k,c,s;
	scanf("%d%d%d",&k,&c,&s);
	if(k!=s){puts("???");return;}
	fru(i,k+1)if(i){
		ll ret=i;
		fru(j,c-1)ret=(ret-1)*k+i;
		printf("%lld ",ret);
	}
	puts("");
}

int main() {
	int te = 1;
	scanf("%d",&te);
	fru(ti,te) {
		printf("Case #%d: ",ti+1);
		solve();
	}
	return 0;
}
