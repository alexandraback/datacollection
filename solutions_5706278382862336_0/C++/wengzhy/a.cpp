#include<cstdio>
#include<cstring>
using namespace std;
long long a,b;
char s[1000];
int main()
{
	int cas;
	scanf( "%d", &cas );
	for ( int c = 0; c < cas; c++ )
	{
		scanf( "%s", s );
		int l = strlen( s );
		for ( int j = 0; j < l; j++ )
		if ( s[j] == '/' )
		{
			a = 0;
			for ( int i = 0; i < j; i++ )
				a = a * 10 + ( s[i] - '0' );
			b = 0;
			for ( int i = j + 1; i < l; i++ )
				b = b * 10 + ( s[i] - '0' );
			break;
		}
		bool u = false;
		int ans = -1;
		for ( int i = 0; i < 41; i++ )
		{
			
			if ( a == b )
			{
				u = true;
				if ( ans == -1 )
				ans = i;
				break;
			}
			if ( a > b )
			{
				if ( ans == -1 )
				ans = i;
				a = a - b;
			}
			if ( b % 2 != 0 ) break;
			b = b / 2;
		}
		if ( u ) printf("Case #%d: %d\n",c+1,ans);
		else printf("Case #%d: impossible\n",c+1);
	}
	
}