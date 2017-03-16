#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


bool possible( const vector<int>& card, const vector<int>& v )
{
	set<int> prd;
	for ( int i = 0; i < (1<<card.size()); i++ ) {
		int p = 1;
		for ( int j = 0; j < card.size(); j++ ) {
			if ( i & (1<<j) ) {
				p *= card[j];
			}
		}
		prd.insert(p);
	}

	for ( auto e : v ) {
		if ( prd.count(e) == 0 ) return false;
	}
	return true;
}

bool Solve( int N, int M, int c, int m, vector<int>& card, const vector<int>& v )
{
	if ( c == N ) {
		auto ret = possible( card, v );
		if ( ret ) {
			for ( auto e : card ) {
				cout << e;
			}
			cout << endl;
		}
		return ret;
	}

	for ( int i = m; i <= M; i++ ) {
		card.push_back(i);
		if ( Solve( N, M, c+1, i, card, v ) ) {
			return true;
		}
		card.pop_back();
	}
	return false;
}

int main()
{
    int T;
    cin >> T;
    for ( int t = 1; t <= T; t++ ) {
        printf( "Case #%d:\n", t );
		int R, N, M, K;
		cin >> R >> N >> M >> K;
		for ( int i = 0; i < R; i++ ) {
			vector<int> c(K);
			for ( int j = 0; j < K; j++ ) {
				cin >> c[j];
			}
			vector<int> card;
			Solve( N, M, 0, 2, card, c );
		}
    }
    return 0;
}
