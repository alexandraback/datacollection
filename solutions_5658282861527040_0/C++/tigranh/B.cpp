
#include <iostream>

using namespace std;

int get_bit( long long n, int bit )
{
	return (int)((n >> bit) % 2);
}

long long solve_greater( long long a, long long b, long long k )
{
	//assert( a > k );
	//assert( b > k );
	for ( int bit = 32; bit >= 0; --bit ) {
		if ( get_bit( k, bit ) == 0 ) {
		}
	}
	return -1;
}

long long solve( long long a, long long b, long long k )
{
	if ( a < k || b < k )
		return a * b;
	long long r = 0;
	r = a * b;
	r -= solve_greater( a, b, k );
	return r;
}

long long solve_fast( long long a, long long b, long long k )
{
	int r = 0;
	for ( int A = 0; A < a; ++A )
		for ( int B = 0; B < b; ++B )
			if ( (A&B) < k )
				++r;
	return r;
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t ) {
		int a, b, k;
		cin >> a >> b >> k;
		cout << "Case #" << t << ": " << solve_fast( a, b, k ) << endl;
	}
	return 0;
}
