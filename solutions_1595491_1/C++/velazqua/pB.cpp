#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		cout << "Case #" << i+1 << ": ";
		int N, S, p, c = 0;
		cin >> N >> S >> p;
		vector<int> nums( N );
		for( int j=0; j<N; ++j )
			cin >> nums[j], c += ((nums[j]>0)?1:0);
		if( p == 0 )
			cout << N << endl;
		else if( p == 1 )
			cout << c << endl;
		else 
		{
			int counter = 0;
			for( int j=0; j<N; ++j )
			{
				if( nums[j] >= 3*p-2 )
					++counter;
				else if( S > 0 && nums[j] >= 3*p-4 )
				{
					++counter;
					--S;
				}
			}
			cout << counter << endl;
		}
	}
}
