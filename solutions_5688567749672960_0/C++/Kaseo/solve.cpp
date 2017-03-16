#include<cstdio>
#include<cassert>
#include<cstring>
#include<map>
#include<set>
#include<time.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include <limits>
   
using namespace std;
  
long long gcd( long long b, long long s ){
    return (s!=0) ? gcd( s, b%s ) : b;
}
  
long long Pow( long long a, long long b, long long c ){
    if( b == 0 ) return 1%c;
    else if( b == 1 ) return a%c;
    else{
        long long A = Pow( a, b/2, c );
        A = (A*A) % c;
        if( b & 1 ) A = (A*a) % c;
        return A;
    }
}

const long long INF = 1e9 + 7;
const long long INF9 = 1e9 + 9;
typedef pair <int, int> ii;

long long rev( long long n){
	long long r = 0;
	while( n ){
		r = r*10 + (n%10);
		n /= 10;
	}
	return r;
}

int d[10000007];
long long N;


void solve(){
	long long n;
	scanf("%lld", &n);

	for(int i=1; i<=n; i++)
		d[i] = i;
	d[1] = 1;
	for(int i=1; i<=n; i++){
		long long r = rev(i);
		d[r] = min( d[r], d[i]+1 );
		d[i+1] = min( d[i+1], d[i]+1 );
	}
	
	printf("%d\n", d[n]);
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int R=1; R<=T; R++){
		printf("Case #%d: ", R);
		solve();
	}
}