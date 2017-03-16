#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100005;
struct node
{
	int x,i;
}a[maxn],b[maxn];
int c[maxn], d[maxn];
bool cmp1( node x, node y )
{
	return b[x.i].x > b[y.i].x;
}
bool cmp( node x, node y )
{
	return x.x < y.x;
}
int main()
{
	int cas,n,ca = 0;
	scanf( "%d", &cas );
	while ( cas-- )
	{
		scanf( "%d", &n );
		memset( c, 0, sizeof( c ));
		memset( d, 0, sizeof( d ));
		for ( int i = 0; i < n; i++ )
		{
			scanf( "%d", &a[i].x );
			a[i].i = i;
			scanf( "%d", &b[i].x );
			b[i].i = i;
		}
		sort( a, a+n, cmp1 );
		sort( b, b+n, cmp );
		int sum = 0;
		int ans = 0;
		bool u = true;
		while ( u )
		{
			u = false;
			for ( int j = 0; j < n; j++ )
			if ( d[b[j].i] == 0 && b[j].x <= sum )
			{
				d[b[j].i] = 1;
				if ( c[b[j].i] == 0 )
				sum = sum + 2;
				else sum = sum + 1;
				ans++;
//				printf( "%d 2\n",b[j].i);
				u = true;
			}
			for ( int j = 0; j < n; j++ )
			if ( d[a[j].i] == 0 && c[a[j].i] == 0 && a[j].x <= sum )
			{
				c[a[j].i] = 1;
//				printf( "%d 1\n",a[j].i);
				sum = sum + 1;
				ans++;
				u = true;
				break;
			}
		}
		ca++;
		if ( sum != n * 2 )
		{
			printf( "Case #%d: Too Bad\n",ca);
		}
		else
		{
			printf( "Case #%d: %d\n",ca,ans);
		}
	}
	return 0;
}