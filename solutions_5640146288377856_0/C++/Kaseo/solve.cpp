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

void solve(){
	int r, c, w;
	scanf("%d %d %d", &r, &c, &w);

	int re = 0;
	for(int i=0; i<r; i++){
		if( i == r-1 )
			re += (c-w+w-1)/w;
		else
			re += c/w;
	}
	re += w;
	printf("%d\n", re);
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