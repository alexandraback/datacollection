
#include <iostream>

#include <vector>
#include <string>

#include <algorithm>

using namespace std;

int tests;

int N, S, p;


int main()
{
	cin >> tests;

	for( int curTest=0; curTest<tests; ++curTest )
	{

		cin >> N >> S >> p;

		int res = 0;
		for( int i=0; i<N; ++i )
		{
			int val;
			cin >> val;
			const int base = val / 3;
			int alea = base;
			int best = base;

			bool sok = false;
			switch( val % 3 )
			{
				case 0:
					if ( base > 0 )
						best = base+1;
					if ( best >= p )
						sok = true;
					break;
				case 1:
					best = base+1;
					break;
				case 2:
					alea = base+1;
					best = base+2;
					if ( best >= p )
						sok = true;
					break;
			}
			if ( alea >= p )
			{
				++res;
			}
			else if ( sok && S > 0 )
			{
				++res;
				--S;
			}
			else if ( !sok && best >= p )
			{
				++res;
			}
		}

		cout << "Case #" << (curTest+1) << ": ";
		cout << res;
		cout << endl;
	}

	return 0;
}

