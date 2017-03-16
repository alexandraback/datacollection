#include<cstdio>
#include<cstring>
using namespace std;
int b[100];
int a[100];
int z[26];
char s[100][105];
char s1[10000];
int ans;
void dfs( int x, int y )
{
	if ( x == y + 1 )
	{
		for ( int i = 0; i < 26; i++ )
			z[i] = 0;
		int q = 0;
		for ( int i = 1; i <= y; i++ )
		{
			int l = strlen(s[a[i]-1]);
			for ( int j = 0; j < l; j++ )
				s1[q++] = s[a[i]-1][j];
			s1[q] = '\n';
		}
		bool u = true;
		z[s1[0]-'a'] = 1;
		for ( int i = 1; i < q; i++ )
		if ( s1[i] != s1[i-1] )
		{
			if ( z[s1[i]-'a'] == 0 ) z[s1[i]-'a'] = 1;
			else 
			{
				u = false;
				break;
			}
		}
		if ( u ) ans++;
		return;
	}
	for ( int i = 0; i < y; i++ )
	if ( b[i+1] == 0 )
	{
		b[i+1] = x;
		a[x] = i+1;
		dfs( x + 1, y );
		b[i+1] = 0;
	}
}
int main()
{
	int cas;

	scanf( "%d", &cas );
	for ( int c = 0; c < cas; c++ )
	{
		int n;
		scanf( "%d", &n );
		for ( int i = 1; i <= n; i++ )
			b[i] = 0;
		for ( int i = 0; i < n; i++ )
			scanf( "%s", s[i] );
		ans = 0;
		dfs( 1, n );
		printf("Case #%d: %d\n",c+1,ans);
	}

	return 0;
}