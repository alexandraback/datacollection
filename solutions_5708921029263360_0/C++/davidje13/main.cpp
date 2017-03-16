#include <iostream>
#include <vector>
#include <array>
#include <stdlib.h>

// https://code.google.com/codejam/contest/4314486/dashboard#s=p2

bool check(
	const std::vector<std::array<long,3>> &solution,
	const std::array<long,3> &counts,
	const long maxRep
) {
	std::vector<long> rep012( counts[0] * counts[1] * counts[2] );
	std::vector<long> rep01( counts[0] * counts[1] );
	std::vector<long> rep12( counts[1] * counts[2] );
	std::vector<long> rep02( counts[0] * counts[2] );
	for( const auto &day : solution ) {
		++ rep012[(day[0]*counts[1]+day[1])*counts[2]+day[2]];
		++ rep01[day[0]*counts[1]+day[1]];
		++ rep12[day[1]*counts[2]+day[2]];
		++ rep02[day[0]*counts[2]+day[2]];
	}
	for( const long rep : rep012 ) {
		if( rep > 1 ) {
			return false;
		}
	}
	for( const long rep : rep01 ) {
		if( rep > maxRep ) {
			return false;
		}
	}
	for( const long rep : rep12 ) {
		if( rep > maxRep ) {
			return false;
		}
	}
	for( const long rep : rep02 ) {
		if( rep > maxRep ) {
			return false;
		}
	}
	return true;
}

std::vector<std::array<long,3>> solve(
	const std::array<long,3> &counts,
	const long maxRep
) {
	std::vector<std::array<long,3>> result;
	// max combination space = 10 * 10 * 10 = 1000 in large dataset,
	// which gives 10 * 10 * 3 = 300 for pair tracking, so we can easily track
	// all history.

	// order does not matter, so just go through all combinations of clothes
	// and see if they are permitted based on the earlier combinations

	std::vector<long> rep01( counts[0] * counts[1] );
	std::vector<long> rep12( counts[1] * counts[2] );
	std::vector<long> rep02( counts[0] * counts[2] );
	for( long c0 = 0; c0 < counts[0]; ++ c0 ) {
		for( long c1 = 0; c1 < counts[1]; ++ c1 ) {
			for( long c2 = 0; c2 < counts[2]; ++ c2 ) {
				if( rep01[c1 * counts[0] + c0] >= maxRep ) {
					break;
				}
				if( rep12[c2 * counts[1] + c1] >= maxRep ) {
					continue;
				}
				if( rep02[c2 * counts[0] + c0] >= maxRep ) {
					continue;
				}
				std::array<long,3> current;
				current[0] = c0;
				current[1] = c1;
				current[2] = c2;
				result.push_back( current );
				++ rep01[c1 * counts[0] + c0];
				++ rep12[c2 * counts[1] + c1];
				++ rep02[c2 * counts[0] + c0];
			}
		}
	}

	return result;
}

void solveBruteBest(
	const std::vector<std::array<long,3>> all,
	const std::array<long,3> &counts,
	const long maxRep,
	std::vector<std::array<long,3>> &work,
	std::vector<std::array<long,3>> &result,
	std::size_t &best,
	const std::size_t n
) {
	if( work.size( ) + all.size( ) - n <= best ) {
		return;
	}
	if( !check( work, counts, maxRep ) ) {
		return;
	}
	if( n < all.size( ) ) {
		solveBruteBest( all, counts, maxRep, work, result, best, n + 1 );
		work.push_back( all[n] );
		solveBruteBest( all, counts, maxRep, work, result, best, n + 1 );
		work.resize( work.size( ) - 1 );
	} else {
		if( work.size( ) > best ) {
			best = work.size( );
			result = work;
		}
	}
}

std::vector<std::array<long,3>> solveBrute(
	const std::array<long,3> &counts,
	const long maxRep
) {
	std::vector<std::array<long,3>> all;
	for( long c0 = 0; c0 < counts[0]; ++ c0 ) {
		for( long c1 = 0; c1 < counts[1]; ++ c1 ) {
			for( long c2 = 0; c2 < counts[2]; ++ c2 ) {
				std::array<long,3> current;
				current[0] = c0;
				current[1] = c1;
				current[2] = c2;
				all.push_back( current );
			}
		}
	}

	std::size_t best = 0;
	std::vector<std::array<long,3>> work;
	std::vector<std::array<long,3>> result;
	solveBruteBest( all, counts, maxRep, work, result, best, 0 );
	return result;
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
		std::array<long,3> counts;
		long maxRep;
		std::cin >> counts[0] >> counts[1] >> counts[2] >> maxRep;

		const auto best = solveBrute( counts, maxRep );
		if( !check( best, counts, maxRep ) ) {
			std::cerr << "!!!!!! ERROR !!!!!!" << std::endl;
		}

		std::cout << "Case #" << (n + 1) << ": " << best.size( ) << std::endl;
		for( const auto &day : best ) {
			for( std::size_t i = 0; i < day.size( ); ++ i ) {
				if( i > 0 ) {
					std::cout << ' ';
				}
				std::cout << (day[i] + 1);
			}
			std::cout << std::endl;
		}
	}

	return EXIT_SUCCESS;
}
