#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <functional>
#include <iostream>
 
using namespace std;
 
//const int INF = 5003;
const long long INF = 1000000007;
const int MAXN = 100005;
typedef pair <int, int> ii;
//typedef pair <long long, long long> ii;
long long gcd( long long b, long long s ){
    return (s!=0) ? gcd( s, b%s ) : b;
}

 
int main(){ //freopen("in.txt", "r",  stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int R=1; R<=T; R++){
		long long p, q;
		scanf("%lld/%lld", &p, &q);
		long long g  = gcd( p, q );
		long long qq = q;
		qq /= g;
		q /= g;
		p /= g;
		
		bool can = 1;
		long long ret = 0;
		while( qq > 1 ){
			if( qq % 2 == 0 ){
				qq /= 2;
				++ret;
			}
			else{
				can = 0;
				break;
			}
		}
		
		long long res = ret+1;
		if( can ){
			
			qq = 1;
			for(int i=ret; i>=0; i--){
				qq = (1LL<<i);
				if( q/qq <= p )
					res = min( res, (long long)i );
			}	
		}

		printf("Case #%d: ", R);
		if( can ) printf("%lld\n", res);
		else printf("impossible\n");
	}
}  