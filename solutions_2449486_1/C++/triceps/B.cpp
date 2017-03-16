#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T = 0;
	cin >> T;
	for ( int t = 1; t <= T; t++ ) {
		int N, M;
		cin >> N >> M;
		vector<vector<int>> lawn( N, vector<int>(M) );
		for ( int i = 0; i < N; i++ ) {
			for ( int j = 0; j < M; j++ ) {
				cin >> lawn[i][j];
			}
		}

		multimap<int,pair<int,int>> m;
		for ( int i = 0; i < N; i++ ) {
			for ( int j = 0; j < M; j++ ) {
				m.insert( make_pair( lawn[i][j], make_pair(i,j) ) );
			}
		}
		
		bool possible = true;
		for ( auto e : m ) {
			int r = e.second.first, c = e.second.second, h = e.first;
			set<int> s;
			for ( int i = 0; i < N; i++ ) {
				if ( lawn[i][c] <= 100 ) {
					s.insert( lawn[i][c] );
					if ( s.size() > 1 ) {
						break;
					}
				}
			}
			if ( s.empty() || s.size() == 1 && *s.begin() == h ) {
				for ( int i = 0; i < N; i++ ) {
					lawn[i][c] = 101;
				}
				continue;
			}

			s.clear();
			for ( int i = 0; i < M; i++ ) {
				if ( lawn[r][i] <= 100 ) {
					s.insert( lawn[r][i] );
					if ( s.size() > 1 ) {
						break;
					}
				}
			}
			if ( s.empty() || s.size() == 1 && *s.begin() == h ) {
				for ( int i = 0; i < M; i++ ) {
					lawn[r][i] = 101;
				}
				continue;
			}

			possible = false;
			break;
		}
		printf( "Case #%d: %s\n", t, possible ? "YES" : "NO" );
	}
	return 0;
}
