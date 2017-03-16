#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> PI;

int get_id( const string& s, map<string,int>& m ) {
	auto iter = m.find( s );
	if( iter == m.end() ) {
		int id = m.size();
		m[s] = id;
		return id;
	}
	return iter->second;
}

template<int N, int M> struct BM2 {
	int a[N][M];
	int a_cnt[N];
	int dad[M];
	int seen[N];
	int n, m;
	
	void reset( int _n, int _m ) {
	    n = _n;
	    m = _m;
	    for( int i = 0; i < n; ++i ) {
	        a_cnt[i] = 0;
	    }
	}
	inline void edge( int from, int to ) {
	    a[from][a_cnt[from]++] = to;
	}
	bool dfs( int x ) {
		if( x == -1 ) return true;
		if( seen[x] ) return false;
		seen[x] = 1;
		
		for( int i = 0; i < a_cnt[x]; ++i ) {
			if( dfs( dad[a[x][i]] ) ) {
				dad[a[x][i]] = x;
				return true;
			}		
		}
		return false;
	}
	int max_value() {
		int cnt = 0;
		
		for( int i = 0; i < m; ++i ) {
			dad[i] = -1;
		}
		for( int i = 0; i < n; ++i ) {
			for( int j = 0; j < n; ++j ) {
				seen[j] = 0;
			}
			if( dfs( i ) ) {
				++cnt;
			}
		}
		return cnt;
	}
}; 

BM2<1024,1024> bm;

int main() {
	int cases;
	
	vector<PI> v;
	map<string,int> left_id, right_id;
	
	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ": ";
		int N;
		cin >> N;
		
		assert( 1 <= N && N <= 1000 );
		
		v.clear();
		left_id.clear();
		right_id.clear();
		
		for( int i = 0; i < N; ++i ) {
			string a, b;
			cin >> a >> b;
			v.push_back( { get_id( a, left_id ), get_id( b, right_id ) } );
		}
		
		bm.reset( left_id.size(), right_id.size() );
		
		for( int i = 0; i < (int)v.size(); ++i ) {
			bm.edge( v[i].first, v[i].second );
		}
		
		int res = bm.max_value();
		cout << N-(left_id.size() + right_id.size() - res) << endl;
		//cout << N-res << endl;
	}
	return 0;	
}
