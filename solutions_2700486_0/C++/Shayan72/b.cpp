#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main()
{
	ll T,N,X,Y,o=1;
	cin >> T;
	
	while( T-- )
	{
		cin >> N >> X >> Y;
		
		long double p = 1.0;
		
		if( X != 0 )
		{
			ll l = X+Y-1;
			ll movesGholeZir = (l*(l+1))/2;
			ll moves = movesGholeZir + Y+1;
			ll maxMoves = movesGholeZir + X+Y+Y+1;
			if( N >= maxMoves )
				p = 1.0;
			else if( N < moves )
			{
				p = 0.0;
			}
			else
			{
				p = pow(0.5,Y+1);
				int countDown = Y;
				for (ll i = moves+1; i <= N; i++)
				{
					if( countDown != 0 )
					{
						p += p;
						countDown--;
					}
					else
					{
						p += p*0.5;
					}
					
				}	
			}
		}
		else
		{
			ll moves = ((Y+1)*(Y+2))/2;
			if( N >= moves ) p = 1.0;
			else p = 0.0;
		}
		
		cout << "Case #" << o << ": " << p << endl;
		o++;
	}
	
	return 0;
}
