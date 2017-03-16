#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <cmath>
#include <deque>
#include <map>
#include <cstring>
#include <set>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};

vector<int> list[1006];
int indeg[1006];
deque<int> d;
vector<int> order;
long long cnt[1006];

int main() {
	int cases;

	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		int N;
		cin >> N;
		for( int i = 0; i < N; ++i ) {
			indeg[i] = 0;
			list[i].clear();
			int M;
			cin >> M;
			for( int j = 0; j < M; ++j ) {
				int x;
				cin >> x;
				list[i].push_back( x-1 );
			}
		}
		for( int i = 0; i < N; ++i ) {
			for( int j = 0; j < (int)list[i].size(); ++j ) {
				++indeg[list[i][j]];
			}
		}
		d.clear();
		for( int i =0 ; i< N; ++i ) {
			if( indeg[i] == 0 ) d.push_back(i);
		}
		order.clear();
		while( !d.empty() ) {
			int x = d.front(); d.pop_front();
			order.push_back(x);
			for( int i =0; i < (int)list[x].size(); ++i ) {
				if( --indeg[list[x][i]] == 0 ) {
					d.push_back(list[x][i]);
				}
			}
		}
		assert( (int)order.size() == N );
		for( int i =0 ; i < N; ++i ) {
			for( int j =0 ; j < N; ++j)  {
				cnt[j] = 0;
			}
			cnt[order[i]] = 1;
			for( int j = i; j < N; ++j ) {
				int x = order[j];
				for( int k = 0; k < (int)list[x].size(); ++k ) {
					cnt[list[x][k]] += cnt[x];
					if( cnt[list[x][k]] > 1 ) goto found;
				}
			}
		}
		cout << "Case #" << caseid << ": No\n";
		continue;
	found:;
		cout << "Case #" << caseid << ": Yes\n";
	}
	return 0;
}
