#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int initial_keys[201];

struct chest {
	int key_to_open;
	vector<int> keys;
};

vector<chest> chests;
int memo[1<<20];

int N;
int rec( int mask ) {
	if( mask == (1<<N)-1 ) return 1;
	
	int& res = memo[mask];
	if( res != -1 ) return res;
	res = 0;
	
	int keys[201];
	memcpy( keys, initial_keys, sizeof(keys));
	
	for( int i = 0; i < N; ++i ) {
		if( mask & (1<<i ) ) {
			--keys[chests[i].key_to_open];
			for( int j = 0; j < chests[i].keys.size(); ++j ) {
				++keys[chests[i].keys[j]];
			}
		}
	}
	
	for( int i = 0; i < N; ++i ) {
		if( !(mask & (1<<i)) ) {
			if( keys[chests[i].key_to_open] > 0 && rec( mask ^ (1<<i) ) ) {
				return res = i+1;
			}
		}
	}
	
	return res;
}

int main(int argc, char** argv) {
	int cases;
	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {		
		cout << "Case #" << caseid << ":";
		
		int K;
		cin >> K >> N;
		memset( initial_keys, 0, sizeof(initial_keys));
		for( int i = 0; i < K; ++i ) {
			int x;
			cin >> x;
			++initial_keys[x];
		}
		chests.resize(N);
		for( int i = 0; i < N; ++i ) {
			int additional_keys;
			cin >> chests[i].key_to_open >> additional_keys;
			chests[i].keys.resize(additional_keys);
			for( int j =0 ; j < additional_keys; ++j ) {
				cin >> chests[i].keys[j];
			}			
		}
		memset(memo,-1,sizeof(memo));
		int x = rec( 0 );
		if( x == 0 ) {
			cout << " IMPOSSIBLE\n";
			continue;
		}
		
		int mask = 0;
		for( int i = 0; i < N; ++i ) {
			cout << ' ' << x;
			mask |= 1<<(x-1);
			x = rec( mask );
		}
		cout << endl;
	}
	return 0;
}

