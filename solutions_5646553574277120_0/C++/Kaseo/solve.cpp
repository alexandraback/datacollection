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

int dp[55];
vector <int> a;

void go( int v ){
	dp[0] = 1;
	for(int i=1; i<=v; i++)
		dp[i] = 0;
	for(int j=0; j<a.size(); j++)
		for(int i=v-1; i>=0; i--)
			if( i+a[j] <= v && dp[i] )
				dp[i+a[j]] = 1;
		

}

void solve(){
	int c, d, v, kk;
	scanf("%d %d %d", &c, &d, &v);
	
	for(int i=0; i<d; i++){
		scanf("%d", &kk);
		a.push_back( kk );
	}
	sort( a.begin(), a.end() );

	go( v );
	for(int i=0; i<=v; i++){
		if( !dp[i] ) {
			a.push_back( i );
		}
		go( v );

	}
	printf("%d\n", a.size() - d );
	a.clear();
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