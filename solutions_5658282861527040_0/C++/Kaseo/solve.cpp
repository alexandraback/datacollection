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


int main(){ //freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int R=1; R<=T; R++){
		long long a, b, k;
		scanf("%lld %lld %lld", &a, &b, &k);

		
		long long res = 0;
		for(int i=0; i<a; i++)
			for(int j=0; j<b; j++)
				if( (i & j) < k )
					++ res;		
				

		
		printf("Case #%d: ", R);
		printf("%lld\n", res);

		
	}
	
}