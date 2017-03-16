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

char s[200];

int solve(){
	int n = strlen(s), ans = 0;
	s[n] = '+';
	REP(i, n) if(s[i]!=s[i+1]) ans++;
	return ans;
}

int main() {
	int zn;
	RI(zn);
	REP(i, zn){
		scanf("%s", s);
		printf("Case #%d: %d\n", i+1, solve());
	}
	return 0;
}

