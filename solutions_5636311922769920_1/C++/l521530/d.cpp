// TwT514 {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
	    scanf("%d",&head);
		    RI(tail...);
}
// }}}

int k, c, n;
void input(){
	RI(k, c, n);
}

void solve(){	
	if (k > c * n){
		puts(" IMPOSSIBLE");
		return;
	}
	for (int x = 0; x < k; x += c){
		LL ans = 0;
		REP(i, c){
			int d = (x + i) < k ? (x + i) : 0;
			ans = ans * k + d;
		}
		printf(" %lld", ans + 1);
	}
	puts("");
}

int main() {
	int zn;
	RI(zn);
	REP(i, zn){
		input();
		printf("Case #%d:", i+1);
		solve();
	}
	return 0;
}

