// TwT514 {{{
#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset(x,0,(n)*sizeof(*x))
#define MS1(x,n) memset(x,-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}
#define N 1010
int n;
char c[N];

void input(){
	RI(n);
	scanf("%s",c);
}

void solve(){
	int sm=0, nd=0;
	for(int i=0; i<=n; i++){
		int k = c[i]-'0';
		nd = max(nd, i-sm);
		sm+=k;
	}
	static int zi = 0;
	printf("Case #%d: %d\n", ++zi, nd);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		input();
		solve();
	}
    return 0;
}

