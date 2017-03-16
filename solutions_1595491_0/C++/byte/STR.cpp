#include<iostream>
using namespace std;
int main()
{
	int T , S , N , P;
	cin >> T;
	for(int i = 1; i <= T; ++i)
	{
		cin >> N >> S >> P;
		int L , U;
		if ( P < 2 ) L = U = P;
		else L = 3 * P - 4, U = L + 2;
		int res = 0 , x;
		while( N-- )
		{
			cin >> x;
			if( x >= U ) res++;
			else if( x >= L )
			{
				if( S > 0 ){ S--; res++; }
			}
		}
		cout << "Case #" << i << ": " << res << "\n";
	}
	return 0;
}
