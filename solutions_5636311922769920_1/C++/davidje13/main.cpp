#include <iostream>
#include <vector>
#include <stdexcept>

// https://code.google.com/codejam/contest/6254486/dashboard#s=p3

typedef long long sample_t; // 63 bits is large enough to store 10^18, as specified

std::vector<sample_t> find_samples( const sample_t startTiles, const sample_t layers ) {
	if( layers <= 0 ) {
		throw std::invalid_argument( "layers" );
	}

	// dumb solution is to check a tile corresponding to each input tile
	// (requires startTiles samples; will always work for small input, but not for large)

	// better solution is to check multiple start tiles with each sample where possible
	// e.g.:
	// at layer 2, tile 2 is G if either tile 1 or 2 @ layer 1 was G
	// l2+: t2    = G if 1/2 = G
	//      t2K+4 = G if 3/4 = G
	// l3+: t3    = G if 1/2/3 = G
	// so each sample can cover <layers> tiles from the original pattern

	std::vector<sample_t> samples;
	for( sample_t p = 0; p < startTiles; ) {
		sample_t tile = 0;
		for( sample_t layer = 0; layer < layers && p < startTiles; ++ layer ) {
			tile *= startTiles;
			tile += p;
			++ p;
		}
		samples.push_back( tile );
	}
	return samples;
}

int main( int argc, const char *const *const argv ) {
	if( argc != 1 ) {
		std::cerr
			<< "Usage: " << argv[0] << std::endl
			<< std::endl
			<< "Takes input on stdin" << std::endl;
		return EXIT_FAILURE;
	}

	long totalTests;
	std::cin >> totalTests;

	for( long n = 0; n < totalTests; ++ n ) {
		int startTiles;
		int layers;
		int maxSamples;
		std::cin >> startTiles >> layers >> maxSamples;
		std::vector<sample_t> samples = find_samples( startTiles, layers );
		std::cout << "Case #" << (n + 1) << ":";
		if( samples.size( ) > (std::size_t) maxSamples ) {
			std::cout << " IMPOSSIBLE";
		} else {
			for( const sample_t sample : samples ) {
				std::cout << " " << (sample + 1);
			}
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}
