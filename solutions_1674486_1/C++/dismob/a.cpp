
#include <iostream>

#include <vector>
#include <string>

using namespace std;

int tests;

int N;
int g[1000+1][1000+1];
int c[1000+1];
int ied[1000+1];

bool check( int si, int from )
{
	for( int i=0; i<N; ++i )
	{
		if ( g[si][i] )
		{
			if ( c[i] )
			{
				return true;
			}
			c[i] = 1;
			//cout << "check" << i;
			if ( check( i, si ) )
				return true;
		}
	}
	return false;
}


int main()
{
	cin >> tests;

	for( int curTest=0; curTest<tests; ++curTest )
	{

		bool res = false;
		cin >> N;
		memset( g, 0, sizeof(g) );
		memset( ied, 0, sizeof(ied) );
		for( int i=0; i<N; ++i )
		{
			int n;
			cin >> n;
			for( int j=0; j<n; ++j )
			{
				int t;
				cin >> t;
				g[i][t-1] = 1;
				ied[t-1] = 1;
			}
		}

		for( int i=0; i<N; ++i )
		{
			if ( ied[i] == 0 )
			{
				memset( c, 0, sizeof(c) );
				//cout << "disp" << i;
				c[i] = 1;
				if ( check( i, i ) )
				{
					res = true;
					break;
				}
			}
		}

		cout << "Case #" << (curTest+1) << ": ";
		cout << (res?"Yes":"No");
		cout << endl;
	}

	return 0;
}

