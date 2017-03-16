#include <stdio.h>
#include <string.h>

char goo[3][128] =
{
	"ejp mysljylc kd kxveddknmc re jsicpdrysi",
	"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
	"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

char eng[3][128] =
{
	"our language is impossible to understand",
	"there are twenty six factorial possibilities",
	"so it is okay if you want to just give up"
};

char map[128];
bool used[128];


int main()
{
	freopen( "A.in", "r", stdin );
	freopen( "A.out", "w", stdout );

	static char g[104];
	int i, j;
	int t;

	// calculate mapping
	memset( map, 0, sizeof(map) );
	memset( used, false, sizeof(used) );
	for( i = 0; i < 3; ++i )
		{
		for( j = 0; goo[i][j] != '\0'; ++j )
			{
			map[goo[i][j]] = eng[i][j];
			used[eng[i][j]] = true;
			}//end for
		}//end for
	for( i = 'z'; i >= 'a'; --i )
		{
		if( !used[i] )
			{
			used[i] = true;
			for( j = 'a'; j <= 'z'; ++j )
				{
				if( map[j] == 0 )
					{
					map[j] = i;
					break;
					}//end if
				}//end for
			}//end if
		}//end for

	scanf( "%d\n", &t );
	for( i = 1; i <= t; ++i )
		{
		gets( g );
		printf( "Case #%d: ", i );
		for( j = 0; g[j] != '\0'; ++j )
			{
			putchar( map[g[j]] );
			}//end for
		putchar( '\n' );
		}//end for
	return 0;
}
