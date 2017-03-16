#include <iostream>
#include <vector>
#include <ctime>
#include <map>

using namespace std;

static clock_t s;

bool check( int N, const vector<int>& chest, const vector<vector<int>> keyin, int keys[], bool open[], vector<int>& order )
{
	map<int,int> m;
	for ( int i = 0; i < N; i++ ) {
		if ( !open[i] ) {
			int c = chest[i];
			m[c]++;
			for ( auto e : keyin[i] ) {
				m[e]--;
			}
		}
	}
	for ( auto e : m ) {
		if ( e.second - keys[e.first] > 0 ) {
			return false;
		}
		if ( keys[e.first] == 0 ) {
			bool locked = true;
			for ( int i = 0; i < N; i++ ) {
				if ( open[i] ) continue;
				if ( chest[i] != e.first ) {
					auto it = find( keyin[i].begin(), keyin[i].end(), e.first );
					if ( it != keyin[i].end() ) {
						locked = false;
						break;
					}
				}
			}
			if ( locked ) return false;
		}
	}

	if ( double(clock()-s) /CLOCKS_PER_SEC> 60 ) return false;
	bool allopen = true;
	for ( int i = 0; i < N; i++ ) {
		int c = chest[i];
		if ( !open[i] && keys[c] > 0 ) {
			keys[c]--;
			open[i] = true;
			order.push_back(i);
			for ( int j = 0; j < keyin[i].size(); j++ ) {
				keys[keyin[i][j]]++;
			}
			if ( check( N, chest, keyin, keys, open, order ) ) {
				return true;
			}
			for ( int j = 0; j < keyin[i].size(); j++ ) {
				keys[keyin[i][j]]--;
			}
			order.pop_back();
			open[i] = false;
			keys[c]++;
		}
		if ( !open[i] ) allopen = false;
	}
	return allopen;
}

int main()
{
	int T = 0;
	cin >> T;
	for ( int t = 1; t <= T; t++ ) {
		int K, N;
		cin >> K >> N;
		int keys[500] = {0};
		for ( int i = 0; i < K; i++ ) {
			int k;
			cin >> k;
			if ( k ) keys[k]++;
		}
		vector<int> chest(N);
		vector<vector<int>> keyin(N);
		for ( int i = 0; i < N; i++ ) {
			int t, k;
			cin >> t >> k;
			chest[i] = t;
			for ( int j = 0; j < k; j++ ) {
				int ki;
				cin >> ki;
				keyin[i].push_back(ki);
			}
		}
		bool open[300] = {0};
		printf( "Case #%d: ", t );
		s = clock();
		vector<int> order;
		if ( check( N, chest, keyin, keys, open, order ) ) {
			if ( order.size() != N ) cerr << "invalid!!" << endl;
			for ( size_t i = 0; i < order.size(); i++ ) {
				cout << order[i]+1;
				if ( i != order.size()-1 ) cout << " ";
			}
			cout << endl;
		} else {
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}
