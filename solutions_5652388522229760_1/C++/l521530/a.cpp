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

int n;

void input(){
	RI(n);
}
int a[10];
int solve(){
	REP(i, 10) a[i]=0;
	for(int k=1, s=n; ; k++, s+=n){
		for(int t=s; t; t/=10) a[t%10] = 1;
		int all = true;
		REP(i, 10) if(a[i]==0) all = false;
		if(all) return s;	
	}
}

int main() {
	int zn;
	RI(zn);
	REP(i, zn){
		input();
		if(n==0) printf("Case #%d: INSOMNIA\n", i+1);
		else printf("Case #%d: %d\n", i+1, solve());
	}
	return 0;
}

