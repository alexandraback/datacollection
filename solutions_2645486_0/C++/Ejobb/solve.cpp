#include<algorithm>
#include<iostream>
#include<cstdio>

using namespace std;

const int maxn = 10010;

int e , r , n , S[maxn] , T[maxn];
pair<int,int> V[maxn];

int main() {
	freopen( "solve.in" , "r" , stdin );
	freopen( "solve.out" , "w" , stdout );
	
	int cas; scanf( "%d" , &cas );
	for ( int c = 1 ; c <= cas ; c++ ) {
		scanf( "%d%d%d" , &e , &r , &n );
		for ( int i = 1 ; i <= n ; i++ ) {
			scanf( "%d" , &V[i].first );
			V[i].second = i;
			S[i] = 0;
			T[i] = e;
		}
		sort( V + 1 , V + 1 + n );
		
		long long ans = 0;
		for ( int k = n ; k >= 1 ; k-- ) {
			int i = V[k].second;
			
			ans += ( long long ) V[k].first * ( T[i] - S[i] );
			
			for ( int j = i - 1 ; j >= 1 ; j-- )
				if ( S[j] < T[i] - r * ( i - j ) ) S[j] = T[i] - r * ( i - j );
					else continue;
			
			for ( int j = i + 1 ; j <= n ; j++ )
				if ( T[j] > S[i] + r * ( j - i ) ) T[j] = S[i] + r * ( j - i );
					else continue;
			
			T[i] = S[i];
		}
		
		printf( "Case #%d: " , c );
		cout << ans << endl;
	}
	
	return 0;
}
