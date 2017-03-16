#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
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

ll ANS[MAXN];
set<int> S;
void add(ll w){
	while(w){
		S.insert(w%10);w/=10;
	}
}
ll solve(int n) {
	if(n==0)return 0;	
	S.clear();
	ll i;
	for(i=1;S.size()<10;i++){
		add(i*n);
	}
	return (i-1)*n;
}

int main() {
	fru(i,MAXN){
		ANS[i]=solve(i);
	}
	int te = 1;
	scanf("%d",&te);
	fru(ti,te) {
		printf("Case #%d: ",ti+1);
		int a;
		scanf("%d",&a);
		if(ANS[a]!=0)printf("%lld\n",ANS[a]);
		else puts("INSOMNIA");
	}
	return 0;
}
