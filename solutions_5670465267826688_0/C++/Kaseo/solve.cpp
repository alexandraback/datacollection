#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1e4 + 5;
char s[N];
int a[N];

int f[4][4] = { 1, 2, 3, 4,
				2, -1, 4, -3,
				3, -4, -1, 2,
				4, 3, -2, -1};

inline int mul( int a, int b ){
	int sa = 1, sb = 1;
	if( a < 0 ){
		sa = -1;
		a = -a;
	}
	if( b < 0 ){
		sb = -1;
		b = -b;
	}
	return sa*sb*f[a-1][b-1];
}
				

bool isMinusOne( long long l, long long x ){

	int cur = 1;
	for(int i=0; i<l; i++)
		cur = mul( cur, a[i] );
	int st = 1;
	for(int i=0; i<x%4LL; i++)
		st = mul( st, cur );
	if( st == -1 ) return 1;
	else return 0;
}

long long ok(long long pos, long long l, long long x, int key){

	long long en = min(pos+4*l, l*x);
	int cur = 1;
	for(long long i=pos; i<en; i++){
		cur = mul( cur, a[i%l] );
		if( cur == key ) return i+1;
	}
	return -1;
}

bool can( long long l, long long x ){
	long long p = ok( 0, l, x, 2 );
	if( p == -1 ) return 0;
	p = ok( p, l, x, 3 );
	if( p == -1 ) return 0;
	p = ok( p, l, x, 4 );
	if( p == -1 ) return 0;
	return 1;
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for(int R=1; R<=T; R++){
		long long l, x;
		scanf("%lld %lld %s", &l, &x, s);

		int n = l;
		for(int i=0; i<n; i++){
			if( s[i] == '1' ) a[i] = 1;
			else if( s[i] == 'i' ) a[i] = 2;
			else if( s[i] == 'j' ) a[i] = 3;
			else a[i] = 4;
		}
		bool good = 0;
		if( isMinusOne( l, x ) ){

			if( can( l, x ) )
				good = 1;
			
		}
		
		printf("Case #%d: ", R);
		if( good ) puts("YES");
		else puts("NO");
	}
}