#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

size_t read_block() {
	char s[100]; cin >> s;
	size_t weight = 0;
	// ignore this decimal crap
	size_t k;
	for( k = 2; s[k] != '\0'; ++k ) {
		weight *= 10;
		weight += s[k] - '0';
	}
	for( ; k < 8; ++k ) weight *= 10;
	return weight;
}

// res[i] is the first index j for which bblocks[j] > gblocks[i]
void fill_next_largest( size_t N, vector<size_t> &gblocks, vector<size_t> &bblocks, 
		vector<size_t> &res ) {
	res.clear(); res.reserve(N);
	size_t next_smallest = 0;
	for( size_t p = 0; p < N; ++p ) {
		while( next_smallest < N && bblocks[next_smallest] < gblocks[p] )
			++next_smallest;
		res[p] = next_smallest;
	}
}

size_t war_points( size_t N, vector<size_t> &nblocks, vector<size_t> &kblocks ) {
	vector<size_t> k_next_largest;
	fill_next_largest( N, nblocks, kblocks, k_next_largest );
	size_t Kpts = 0;
	vector<bool> k_used( N, false );
	size_t k_next_smallest = 0;
	for( size_t Npp = N, Np = Npp-1; Npp > 0; --Npp, --Np ) {
		// Naomi plays nblocks[Np].
		size_t kplay = k_next_largest[Np];
		while( kplay < N && k_used[kplay] ) ++kplay;
		if( kplay == N ) {
			// Naomi wins
			while( k_used[k_next_smallest] ) ++k_next_smallest;
			k_used[k_next_smallest] = false;
		}
		else {
			// Ken wins
			k_used[kplay] = true;
			++Kpts;
		}
	}
	return N - Kpts;
}

size_t dwar_points( size_t N, vector<size_t> &nblocks, vector<size_t> &kblocks ) {
	// We can always have Ken play his smallest
	// (say something near 0 if we will lose,
	// or say something near 1 if we will win.)
	// so we can pre-match our blocks in a maximum way, and just play accordingly.
	// thus this is maximum matching.
	// match N's blocks to K's blocks,
	// so that an N block always goes to a larger K block.
	//
	// but we don't have to do flow or something similarly complicated:
	// process Naomi's blocks in ascending order.
	// If her smallest is smaller than Ken's remaining smallest, then we have to lose,
	// so lose to Ken's largest block.
	// If her smallest is bigger than Ken's smallest, then match those two.
	size_t k_smallest = 0;
	size_t Npts = 0;
	for( size_t Np = 0; Np < N; ++Np ) {
		if( nblocks[Np] < kblocks[k_smallest] ) {
			// have to lose, so just pass.
		}
		else {
			// can win, so take it
			++Npts; ++k_smallest;
		}
	}
	return Npts;
}

int main() {
	size_t T; cin >> T;
	for( size_t Case = 1; Case <= T; ++Case ) {
		size_t N; cin >> N;
		vector<size_t> nblocks;
		vector<size_t> kblocks;
		for( size_t i = 0; i < N; ++i ) nblocks.push_back( read_block() );
		for( size_t i = 0; i < N; ++i ) kblocks.push_back( read_block() );
		sort( nblocks.begin(), nblocks.end() );
		sort( kblocks.begin(), kblocks.end() );
		cout << "Case #" << Case << ": " << dwar_points(N, nblocks, kblocks)
			<< " " << war_points(N, nblocks, kblocks) << endl;
	}
	return 0;
}
