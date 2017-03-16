#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
T read(){
	T temp;
	cin >> temp;
	return temp;
}

struct CounterSpeak{
	int n{ read<int>() };
	vector<int> best;
	
	CounterSpeak() : best( n+1, numeric_limits<int>::max() ){}
	
	int flipInt( int t ){
		auto flipped = to_string( t );
		reverse( flipped.begin(), flipped.end() );
		return stoi( flipped );
	}
	
	int result(){
		best[0] = 0;
		for( int i=1; i<=n; i++ ){
			auto& current = best[i];
			best[i] = min( best[i-1]+1, best[i] );
			
			auto flipped = flipInt( i-1 );
			if( flipped <= n )
				best[flipped] = min( best[flipped], best[i-1]+1 );
		}
		
	//	for( int i=1; i<=n; i++ )
	//		cout << i << "\t" << best[i] << endl;
		
		return best[n];
	};
};


int main(){
	auto amount = read<int>();
	
	for( int i=1; i<=amount; i++ )
		cout << "Case #" << i << ": " << CounterSpeak().result() << endl;
	
	return 0;
}
