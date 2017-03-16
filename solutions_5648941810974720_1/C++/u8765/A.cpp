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

struct digit_t {
	string name;
	char letter;
	int order;
	int index;
	
	bool operator<( const digit_t& other ) const {
		return order < other.order;
	}
};

vector<digit_t> digits = { 
		{"ZERO", 'Z', 0, 0 },
		{"ONE", 'O', 5, 1 },
		{"TWO", 'W', 1, 2 },
		{"THREE", 'T', 8, 3 },
		{"FOUR", 'U', 2, 4 },
		{"FIVE", 'F', 6, 5 },
		{"SIX", 'X', 4, 6 },
		{"SEVEN", 'S', 7, 7 },
		{"EIGHT", 'G', 3, 8 },
		{"NINE", 'I', 9, 9 } };

int main() {
	int cases;
	
	sort( digits.begin(), digits.end() );
	
	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ": ";
		
		string s;
		cin >> s;
		
		//cout << "s = " << s << endl;
		
		int cnt[26];
		memset( cnt, 0, sizeof(cnt) );
		
		for( size_t i = 0; i < s.size(); ++i ) {
			assert( 'A' <= s[i] && s[i] <= 'Z' );
			++cnt[s[i]-'A'];
		}
		
		int res[10];
		memset( res, 0, sizeof(res) );
		
		for( int i = 0; i < 10; ++i ) {
			const digit_t& d = digits[i]; 
			int mult = cnt[d.letter-'A'];
			if( mult == 0 ) continue;
			//cout << "found i = " << i << "; letter = " << d.letter << endl;
			res[d.index] = mult;
			for( int j = 0; j < (int)d.name.size(); ++j ) {
				assert( cnt[d.name[j]-'A'] >= mult );
				cnt[d.name[j]-'A'] -= mult;
			}
		}
		for( int i = 0; i < 26; ++i ) {
			assert( cnt[i] == 0 );
		}
		for( int i = 0; i < 10; ++i ) {
			for( int j = 0; j < res[i]; ++j ) {
				cout << (char)('0'+i);
			}
		}
		cout << endl;
	}
	return 0;	
}
