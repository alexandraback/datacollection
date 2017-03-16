#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main ()
{
	int T;
	cin >> T;
	// find all recycled pairs
	vector<pair<int,int> > R;
	int LIMIT = 2000000;
	int numDigits = 1;
	int powerr = 1;
	for( int i=1; i<=LIMIT; ++i )
	{
		if( i >= 10 ) 		numDigits=2, powerr=10;
		if( i >= 100) 		numDigits=3, powerr=100;
		if( i >= 1000)		numDigits=4, powerr=1000;
		if( i >= 10000)		numDigits=5, powerr=10000;
		if( i >= 100000)	numDigits=6, powerr=100000;
		if( i >= 1000000)	numDigits=7, powerr=1000000;
		{
			// move digits from back to front
			int N = i;
			set<int> nums;
			for( int j=0; j<numDigits-1; ++j )
			{
				int lastDig = N%10;
				N /= 10;
				N += lastDig*powerr;
				if( N <= 2000000 ) nums.insert( N );
			}
			for( set<int>::iterator it=nums.begin(); it!=nums.end(); ++it )
			{
				if( *it > i )
				{
					//cout << "(" << i << "," << N << ")" << endl;
					R.push_back( make_pair( i, *it ) );
				}
			}
		}
	}
	//cout << R.size() << " elements in R" << endl;
	for( int i=0; i<T; ++i )
	{
		cout << "Case #" << i+1 << ": ";
		int A, B;
		cin >> A >> B;
		int ans = 0;
		for( vector<pair<int,int> >::iterator it=R.begin(); it!=R.end(); ++it )
		{
			if( it->first < A ) continue;
			if( it->first >= A && it->first <= B )
			{
				if( it->second >= A && it->second <= B )
				{
					//cout << "(" << it->first << " " << it->second << ")" << endl;
					++ans;
				}
			}
			else
				break;
		}
		cout << ans << endl;
	}
}
