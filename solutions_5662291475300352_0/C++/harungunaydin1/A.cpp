#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define all(x) x.begin(),x.end() 
using namespace std;
vector < pair < long long , long long > > V;
int solve()
{
	V.clear();
	long long N,d,h,i,j,m;
	scanf("%lld" , &N );
	FOR(i,1,N)
	{
		scanf("%lld %lld %lld" , &d , &h , &m );
		FOR(j,1,h)
			V.push_back( make_pair( d , m+j-1 ) );
	}
	
	if( V.size() < 2 ) return 0;
	
	sort( all(V) );
	
	long long a = V[1].f;
	long long b = V[0].f;
	long long x = V[1].s;
	long long y = V[0].s;
	
	if( x == y ) return 0;
	
	if( a == b )
		return 360 * max(x,y) <= (360 - a) * ( abs( x-y ) );
	
	if( x < y )
		return ( 360 - a + b ) * x <= ( 360 - b ) * ( y - x ); // Ondeki hizliysa
		
	return ( 360 + a - b ) * y <= ( x - y ) * ( 360 - a ); // 2 kere gecebiliyorsa
	
}

int main()
{
	freopen( "input.txt" , "r" , stdin );
	freopen( "output.txt" , "w" , stdout );
	int T,i;
	
	scanf("%d" , &T );
	
	FOR(i,1,T)
		printf("Case #%d: %d\n" , i , solve() );
	
	return 0;
}
