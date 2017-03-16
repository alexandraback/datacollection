#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;


int main() {

	int test;
	int n;

	scanf( "%d", &test );

	for ( int t = 1; t <= test; ++t ) {
		scanf( "%d", &n );

		priority_queue< pair< pair< int, int >, int >, vector< pair< pair< int, int >, int > >, greater< pair< pair< int, int >, int > > > PQ1, PQ2;

		for ( int i = 0; i < n; ++i ) {
			int a, b;
			scanf( "%d %d", &a, &b );
			PQ1.push( pair< pair< int, int >, int >( pair< int, int >( a, -b ), i ) );
			PQ2.push( pair< pair< int, int >, int >( pair< int, int >( b, -a ), i ) );
		}

		int nowHave = 0;
		bool flag = 0;
		int ret = 0;

		vector< int > used( n, 0 );

		while ( !PQ2.empty() && !flag ) {
			pair< pair< int, int >, int > now = PQ2.top();
			PQ2.pop();


			while ( nowHave < now.first.first && !PQ1.empty() && !flag ) {
				pair< pair< int, int >, int > next = PQ1.top();
				PQ1.pop();

				if ( used[ next.second ] == 2 ) {
					continue;
				}

				if ( nowHave < next.first.first ) {
					flag = 1;
				}
				else {
					nowHave += 1;
					used[ next.second ] = 1;
					++ret;
				}
			}

			if ( nowHave < now.first.first ) {
				flag = 1;
			}
			else {
				nowHave += 2 - used[ now.second ];
				used[ now.second ] = 2;
				++ret;
			}
		}

		if ( flag ) {
			printf( "Case #%d: Too Bad\n", t );
		}
		else {
			printf( "Case #%d: %d\n", t, ret );
		}

	}

	return 0;
}

