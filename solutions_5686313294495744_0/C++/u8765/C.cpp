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

int main() {
	int cases;
	
	vector<PI> v;
	map<string,int> left_id, right_id;
	
	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ": ";
		int N;
		cin >> N;
		assert( 1 <= N && N <= 16 );
		
		v.clear();
		left_id.clear();
		right_id.clear();
		
		for( int i = 0; i < N; ++i ) {
			string a, b;
			cin >> a >> b;
			v.push_back( { get_id( a, left_id ), get_id( b, right_id ) } );
		}
		
		assert( left_id.size() <= 16 );
		assert( right_id.size() <= 16 );
		
		int res = 0;
		for( int mask = (1<<N)-1; mask >= 0; --mask ) {
			int left_have = 0;
			int right_have = 0;
			
			int cnt_fakes = 0;
			for( int i = 0; i < N; ++i ) {
				if( !(mask & (1<<i )) ) {
					left_have |= 1<<v[i].first;
					right_have |= 1<<v[i].second;
				} else ++cnt_fakes;
			}
			if( cnt_fakes <= res ) continue;
			
			bool ok = true;
			for( int i = 0; i < N; ++i ) {
				if( mask & (1<<i ) ) {
					if( (left_have & (1<<v[i].first)) &&
						(right_have & (1<<v[i].second)) ) {
						//						
					} else {
						ok = false;
						break;
					}
				}
			}
			if( ok ) res = cnt_fakes;
		}		
		cout << res << endl;
	}
	return 0;	
}
