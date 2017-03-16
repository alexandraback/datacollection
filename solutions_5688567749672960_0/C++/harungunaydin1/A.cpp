#include <cstdio>
#include <cstring>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end() 
#define MAXN 
using namespace std;
int reverse( int a )
{
	int s = 0;
	while(a)
	{
		s = s * 10 + a % 10;
		a /= 10;
	}
	return s;
}
int N;
int DP[1000005];
int f(int n)
{
	int &ret = DP[n];
	if( ret ) return ret;
	if( n == N ) return ret = 1;
	ret = 100000000;
	int r = reverse(n);
	if( n < r && r <= N ) ret = f(r) + 1;
	return ret = min( ret , f(n+1) + 1 );
}
int main()
{
	freopen( "input.txt" , "r" , stdin );
//	freopen( "output.txt" , "w" , stdout );
	int T,i;
	
	scanf("%d" , &T );
	
	FOR(i,1,T)
	{
		scanf("%d" , &N );
		memset( DP , 0 , sizeof DP );
		printf("Case #%d: %d\n" , i , f(1) );
	}
	
	return 0;
}
