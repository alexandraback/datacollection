#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define ZERO(v) memset((v), 0, sizeof((v)))

size_t max_squares( size_t N, size_t M, size_t S ) {
	if( S < 4 ) return S;
	size_t best = S;
	for( size_t w = 1; w <= M-2; ++w )
	for( size_t h = 1; h <= N-2; ++h ) {
		size_t l, s;
		l = max(w,h), s = min(w,h);
		size_t use = 2*l + 1 + s;
		if( use > S ) continue;
		size_t encl = use;
		encl += s*(l-s);
		encl += s*(s+1)/2;
		best = max(best, encl);
	}
	for( size_t w = 0; w <= min(S/2, M-2); ++w ) {
		size_t h = (S - 2*w)/2;
		if( h > N-2 ) h = N-2;
		size_t left = S - (2*w + 2*h);
		best = max(best, h*w + 2*h + 2*w + left);
	}
	return best;
}

int main() {
	size_t T; cin >> T;
	for( size_t Case = 1; Case <= T; ++Case ) {
		cout << "Case #" << Case << ": ";
		size_t N, M, K;
		cin >> N >> M >> K;
		if( N <= 2 || M <= 2 ) {
			cout << K << endl;
		}
		else {
			size_t lb = 0, ub = 2*N+2*M-4;
			while( ub - lb > 1 ) {
				size_t mb = (lb+ub)/2;
				if( max_squares(N, M, mb) < K ) lb = mb;
				else ub = mb;
			}
			cout << ub << endl;
		}
	}
	return 0;
}
