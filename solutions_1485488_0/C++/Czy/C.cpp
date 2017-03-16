#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 25;
typedef long long LL;

LL sum[1<<MAXN];
int data[MAXN] , n , ans1 , ans2;
bool vis[1<<MAXN];

void getsum( int mask , LL s )
{
	if (vis[mask]) return;
	vis[mask] = 1;
	sum[mask] = s;
	for ( int i = 0; i < n; i++) 
	{
		if (mask&(1<<i)) continue;
		getsum( mask|(1<<i) , s+data[i] );
	}
}

void dfs( int mk1 , int mk2 )
{
	if ( sum[mk1] < sum[mk2] ) return;
	if ( mk1 != mk2 && sum[mk1] == sum[mk2] )
	{
		ans1 = mk1;
		ans2 = mk2;
		return;
	}
	for ( int i = 0; i < n && ans1 == -1; i++ )
	{
		if ( (1<<i) & mk1) continue;
		if ( (1<<i) & mk2 ) continue;
		dfs( mk1 , mk2+(1<<i) );
	}
}

void printans( int mask ) 
{
	int first = 1;
	for ( int i = 0; i < n; i++ ) {
		if ( mask & (1<<i) ) {
			if ( first ) first = 0;
			else printf( " " );
			printf("%d" , data[i]);
		}
	}
	printf("\n");
}

int main() 
{
	freopen("out.txt","w",stdout);
	int cas;
	scanf( "%d" , &cas );
	for ( int t = 1; t <= cas; t++ ) {
		memset( vis , 0 , sizeof(vis) );
		memset( sum , 0 , sizeof(sum) );
		scanf( "%d" , &n );
		for ( int i = 0; i < n; i++ ) scanf( "%d" , &data[i] );
		sort( data , data+n );
		getsum(0,0);
		ans1 = -1;
		ans2 = -1;
		for ( int i = 0; i < (1<<n) && ans1 == -1; i++ ) 
		{
			dfs(i,0);
		}
		printf( "Case #%d:\n" , t );
		if ( ans1 == -1 ) printf( "Impossible\n" );
		else {
			printans(ans1);
			printans(ans2);
		}
	}
	return 0;
}
