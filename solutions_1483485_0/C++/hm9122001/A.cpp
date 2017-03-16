#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <cstring>

using namespace std;

string from[3] = { "ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv" };

string to[3] = { "our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up" };

char map[256];
char miss[256];

void prep() {
	memset(map, 0, sizeof(map));

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < (int) from[i].size(); ++j) {
			if (from[i][j] == ' ')
				continue;
			if (map[from[i][j]] == 0) {
				map[from[i][j]] = to[i][j];
			} else
				assert( map[from[i][j]] == to[i][j] );
		}
	}

	/*
	 memset( miss, 0, sizeof(miss) );
	 for( int i = 'a'; i <= 'z'; ++i ) {
	 cout << (char)i << " : ";
	 if( map[i] == 0 ) cout << "unknown\n";
	 else {
	 cout << map[i] << endl;
	 miss[map[i]] = 1;
	 }
	 }

	 for( int i = 'a'; i <= 'z'; ++i ) {
	 if( miss[i] == 0 ) cout << "missing " << (char)i << endl;
	 }
	 */
}

int main() {
	prep();
	map['q'] = 'z';
	map['z'] = 'q';
	/*
	 map['q'] = 'q';
	 map['z'] = 'z';
	 */

	int C;
	string s;
	getline(cin, s);
	C = atoi(s.c_str());
	for (int c = 0; c < C; ++c) {
		getline(cin, s);
		cout << "Case #" << c + 1 << ": ";
		for (int i = 0; i < (int) s.size(); ++i) {
			if (s[i] == ' ')
				cout << ' ';
			else
				cout << map[s[i]];
		}
		cout << endl;
	}
	return 0;
}
