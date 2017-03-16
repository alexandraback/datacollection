#include <iostream>
#include <vector>
#include <stdlib.h>

// https://code.google.com/codejam/contest/4314486/dashboard#s=p1

typedef unsigned long long accum_t;

std::size_t edge_index(
	const std::size_t maxNodes,
	const std::size_t from,
	const std::size_t to
) {
	return from * maxNodes + to;
}

bool solve(
	const std::size_t maxNodes,
	const accum_t routes,
	std::vector<bool> &edgesOut
) {
	if( maxNodes < 2 ) {
		return false;
	}
	if( routes == 0 ) {
		return true;
	}
	// upper-triangular matrix (no loops)
	std::vector<accum_t> routesFrom( maxNodes );
	routesFrom[maxNodes-1] = 1;
	for( std::size_t i = maxNodes - 1; (i --) > 0; ) {
		accum_t &connectivity = routesFrom[i];
		for( std::size_t j = i + 1; j < maxNodes; ++ j ) {
			if( connectivity + routesFrom[j] <= routes ) {
				edgesOut[edge_index(maxNodes,i,j)] = true;
				connectivity += routesFrom[j];
			}
		}
	}
	return routesFrom[0] == routes;
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
		std::size_t maxNodes;
		accum_t routes;
		std::cin >> maxNodes >> routes;

		std::vector<bool> edges( maxNodes * maxNodes );
		const bool possible = solve( maxNodes, routes, edges );

		std::cout << "Case #" << (n + 1) << ": ";
		if( possible ) {
			std::cout << "POSSIBLE" << std::endl;
			for( std::size_t i = 0; i < maxNodes; ++ i ) {
				for( std::size_t j = 0; j < maxNodes; ++ j ) {
					std::cout << (edges[edge_index(maxNodes,i,j)] ? '1' : '0');
				}
				std::cout << std::endl;
			}
		} else {
			std::cout << "IMPOSSIBLE" << std::endl;
		}
	}

	return EXIT_SUCCESS;
}
