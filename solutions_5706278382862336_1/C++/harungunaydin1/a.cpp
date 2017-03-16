#include <algorithm>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
using namespace std;
long long gcd( long long a , long long b )
{
	return !b ? a : gcd(b,a%b);
}
int coz( long long a , long long b )
{
	int s(1);
	while(1)
	{
		if( a >= b/2 ) return s;
		b /= 2;
		s++;
	}
}
void solve()
{
	long long a,b,i,g;
	scanf("%lld/%lld" , &a , &b );
	g = gcd(a,b);
	a /= g;
	b /= g;

	for(i = 1; i <= b; i *= 2)
		if( i == b )
			break;

	if(i > b) { printf("impossible\n"); return; }

	long long t = (1ll << 42ll);

	int res(123123123);

	while(a <= t && b <= t)
	{
		res = min( res , coz(a,b) );
		a *= 2ll;
		b *= 2ll;
	}

	printf("%d\n" , res );

}
int main()
{
	int T,i;
	scanf("%d" , &T);
	FOR(i,1,T)
	{
		printf("Case #%d: " , i );
		solve();
	}
	return 0;
}
