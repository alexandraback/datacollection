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

int zn, n, m, nn, mm;
char a[20];

void go(int k){
	if (mm >= m) return;
	if (k < nn){
		a[k+1] = '0';
		go(k+1);
		a[k+1] = '1';
		go(k+1);
		return;
	}
	mm++;
	printf("%s%s", a, a);
	for (int b = 2; b <= 10; b ++){
		LL x = 0;
		REP(j, nn+2) x = x * b + (a[j] - '0');
		printf(" %lld", x);
	}
	puts("");
}

void solve(){
	printf("Case #1:\n");
	nn = n/2 - 2, mm = 0;
	a[0] = '1';
	REP(i, nn) a[i+1] = '0';
	a[nn+1] = '1';	
	a[nn+2] = 0;
	go(0);	
}


int main() {
	RI(zn, n, m);
	solve();
	return 0;
}

