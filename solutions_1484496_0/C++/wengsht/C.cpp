#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 26;

#define LL long long 
LL sum[1<<MAX];
int T, data[MAX] , n , result1 , result2;
bool vis[1<<MAX];

void f( int mask , LL s )
{
	if (vis[mask]) return;
	vis[mask] = 1;
	sum[mask] = s;
    int i;
	for ( i = 0; i < n; i++) 
	{
		if (mask&(1<<i)) continue;
		f( mask|(1<<i) , s+data[i] );
	}
}

void work( int mask1 , int mask2 )
{
	if ( sum[mask1] < sum[mask2] ) return;
	if ( mask1 != mask2 && sum[mask1] == sum[mask2] )
	{
		result1 = mask1;
		result2 = mask2;
		return;
	}
    int i;
	for ( i = 0; i < n && result1 == -1; i++ )
	{
		if ( (1<<i) & mask1) continue;
		if ( (1<<i) & mask2 ) continue;
		work( mask1 , mask2+(1<<i) );
	}
}

inline void print( int dd ) 
{
	int first = 1;
    int i;
	for ( i = 0; i < n; i++ ) {
		if ( dd & (1<<i) ) {
			if ( first ) first = 0;
			else printf( " " );
			printf("%d" , data[i]);
		}
	}
	printf("\n");
}

int main() 
{
   // freopen("C-small-attempt0.in", "r", stdin); 
//	freopen("out","w",stdout);

	scanf("%d" , &T);
    int t = 0;
    while(++t)
    {
        if(t > T) break;
		memset( sum , 0 , sizeof(sum) );
		memset( vis , 0 , sizeof(vis) );
		scanf( "%d" , &n );
		for ( int i = 0; i < n; i++ ) scanf( "%d" , data+i );
		sort( data , data+n );
		f(0,0);
		result2 = result1 = -1;
		for ( int i = 0; i < (1<<n) && result1 == -1; i++ ) 
			work(i,0);
		printf( "Case #%d:\n" , t );
		if ( result1 == -1 ) printf( "Impossible\n" );
		else 
        {
			print(result1);
			print(result2);
		}
	}
	return 0;
}
