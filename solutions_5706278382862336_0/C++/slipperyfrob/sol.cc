#include <cstdio>
#include <iostream>

using namespace std;

typedef unsigned long long int ULL;

ULL gcd( ULL a, ULL b ) {
	while( b ) { ULL c = a % b; a = b; b = c; }
	return a;
}

bool is_pow2( ULL n ) { return !( (n - 1) & n ); }

ULL log_2( ULL n ) {
	ULL p = 0;
	while( ((ULL)1 << p) <= n ) ++p;
	return p-1;
}

int main() {
	size_t T; cin >> T;
	for( size_t Case = 1; Case <= T; ++Case ) {
		cout << "Case #" << Case << ": ";
		ULL num_1s, num_ancs;
		scanf(" %llu/%llu", &num_1s, &num_ancs);
		ULL g = gcd( num_1s, num_ancs );
		num_1s /= g; num_ancs /= g;
		if( !is_pow2(num_ancs) ) {
			cout << "impossible" << endl;
			continue;
		}
		cout << log_2( num_ancs ) - log_2( num_1s ) << endl;
	}
	return 0;
}
