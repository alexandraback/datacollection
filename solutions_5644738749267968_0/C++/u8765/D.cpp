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

using namespace std;

int conv( string s ) {
	auto p = s.find('.');
	assert( p != string::npos );

	auto digits = s.size()-1-p;
	assert( 1 <= digits && digits <= 5 );

	while( digits < 5 ) {
		s += '0';
		++digits;
	}

	return atoi( s.c_str()+p+1 );
}

int main() {
	int cases;

	cin >> cases;

	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ": ";

		int N;
		cin >> N;

		vector<int> naomi;
		vector<int> ken;

		for( int i = 0; i < N; ++i ) {
			string s;
			cin >> s;
			naomi.push_back( conv(s));
		}
		for( int i = 0; i < N; ++i ) {
			string s;
			cin >> s;
			ken.push_back( conv(s));
		}

		sort( naomi.begin(), naomi.end() );
		sort( ken.begin(), ken.end() );

		// war
		vector<int> ken_copy = ken;
		int naomi_war_win = 0;
		for( int i = 0; i < N; ++i ) {
			int j;
			for( j = 0; j < N && ken_copy[j] < naomi[i]; ++j );

			if( j == N ) ++naomi_war_win;
			else {
				assert( ken_copy[j] > naomi[i] ); // all weights different
				ken_copy[j] = -1; // mark as used
			}
		}

		// deceitful war
		int naomi_deceitful_loss = 0;
		for( int i = N-1, j = N-1; i >= naomi_deceitful_loss; --j ) {
			assert( naomi[i] != ken[j] );
			if( naomi[i] > ken[j] ) --i;
			else ++naomi_deceitful_loss;
		}
		cout << N-naomi_deceitful_loss << ' ' << naomi_war_win << endl;
	}
	return 0;
}
