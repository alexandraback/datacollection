#include<cstdio>
#include<cstring>
using namespace std;
long long rr,t;
long long binary( long long l, long long r )
{
	if ( l > r ) return -1;
	long long mid = ( l + r ) / 2;
	if ( t / mid < rr ) return binary( l, mid - 1 );
	if ( t * 2 / mid < ( 2 +  4  * ( mid -1 ) ) ) return binary( l, mid - 1 ); 
	long long q = rr * mid * 2 + ( 2 +  4  * ( mid -1 ) ) * mid / 2;
	if ( q > t ) return binary( l, mid - 1 );
	else
	{
		long long p = binary( mid + 1, r );
		if ( p == -1 ) return mid;
		else return p;
	}
}
int main()
{
	int cas;
	int ca = 0;
	scanf( "%d", &cas );
	while ( cas-- )
	{
		scanf("%lld%lld", &rr, &t );
		printf("Case #%d: %lld\n",++ca,binary(1,t/rr));
	}
	return 0;
}
