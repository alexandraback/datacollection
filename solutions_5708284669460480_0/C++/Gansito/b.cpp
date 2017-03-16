#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long int i64;

int ban , can , mban;
int K , L , S;
string match;
char di[ 102 ] , tar[ 102 ]; 

void solve( int f , string n )
{
	if( f == S )
	{
		can ++;
		if( n.find( match ) != string::npos )
		{
			int nb = 0;
			for( int i = 0; i < S; i++ )
			{
				if( n.substr( i , L ) == match )
				{
					nb++;
				}
			}
			mban = max( nb , mban );
			ban += nb;
		}	
	}
	else
	{
		for( int i = 0; i < K; i++ )
		{
			solve( f + 1 , n + di[ i ] );
		}
	}
}

int main()
{
	int noCase;
	scanf("%d",&noCase);

	for( int nCase = 1 ; nCase <= noCase; nCase++ )
	{
		ban =  can = mban = 0;
		scanf("%d %d %d",&K,&L,&S);
		scanf("%s",di);
		scanf("%s",tar);
		match = tar;
		solve( 0 , "" );
		double ans = ( double )( mban ) - ((double)ban / (double)can);
		printf("Case #%d: %.9f\n",nCase,ans);
	}

	return 0;
}