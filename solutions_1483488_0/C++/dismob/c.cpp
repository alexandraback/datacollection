
#include <iostream>

#include <vector>
#include <string>

#include <set>
#include <map>

using namespace std;

int tests;

long long a, b;

char am[128], bm[128];
char mem[128], mem2[128];

int main()
{
	cin >> tests;

	for( int curTest=0; curTest<tests; ++curTest )
	{
		cin >> a >> b;
		sprintf( am, "%d", a );
		sprintf( bm, "%d", b );
		const int len = strlen( am );

		const long long mx = (a+b)/2 - (a+b)%2;

		set< pair<int,int> > s;
		for( long long i=a; i<=b; ++i )
		{
			sprintf( mem, "%d", i );
			for( int l=1; l<len; ++l )
			{
				for( int j=0; j<len; ++j )
				{
					mem2[j] = mem[(len-l+j)%len];
				}
				mem2[len] = '\0';
				const int rev = atoi( mem2 );
				if ( rev <= b && rev >= a && rev != i )
				{
					const int mi = min( (int)i, rev );
					const int ma = max( (int)i, rev );
					s.insert( make_pair( mi, ma ) );
					/*
					if ( curTest == 1 )
					{
						cout << i << ":" << rev << endl;
					}
					*/
				}
			}
		}


		cout << "Case #" << (curTest+1) << ": ";
		cout << s.size();
		cout << endl;
	}

	return 0;
}

