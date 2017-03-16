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

vector <long long> a;

void solve2(){
	long long c, d, v, kk;
	scanf("%lld %lld %lld", &c, &d, &v);
	
	for(int i=0; i<d; i++){
		scanf("%lld", &kk);
		a.push_back( kk );
	}
	sort( a.begin(), a.end() );
	
	long long en = 0, re = 0;
	for(int i=0; i<d; i++){
		while( en+1 < a[i] && en <= v ) {
			++re;
			en = (c)*(en+1)+en;
		}
		en = max( en, c*a[i]+en );
	}

	printf("%lld\n", re);

	a.clear();
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int R=1; R<=T; R++){
		printf("Case #%d: ", R);

		solve2();
	}
}