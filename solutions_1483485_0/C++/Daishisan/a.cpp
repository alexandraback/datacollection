#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

string CODED   = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
string DECODED = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

int main() {
	assert(CODED.length() == DECODED.length());
	bool seen[26];
	// set up decoding
	char decoding[26];
	fill(decoding, decoding + 26, '.');
	decoding['y' - 'a'] = 'a';
	decoding['e' - 'a'] = 'o';
	decoding['q' - 'a'] = 'z';
	// read in translated text
	for (int i = 0; i < (int) CODED.length(); ++i) {
		if (CODED[i] != ' ') {
			char& c = decoding[CODED[i] - 'a'];
			assert(c == '.' || c == DECODED[i]);
			c = DECODED[i];
		}
	}
	// get does_not_appear
	fill(seen, seen + 26, false);
	for (int i = 0; i < 26; ++i)
		seen[decoding[i] - 'a'] = true;
	char does_not_appear = '.';
	for (int i = 0; i < 26; ++i)
		if (!seen[i])
			does_not_appear = 'a' + i;
	// assert we have all
	if (does_not_appear != '.')
		for (int i = 0; i < 26; ++i)
			if (decoding[i] == '.')
				decoding[i] = does_not_appear;
	// solve problem
	int num_tests; cin >> num_tests;
	string line; getline(cin, line);
	for (int test = 1; test <= num_tests; ++test) {
		string line; getline(cin, line);
		for (int i = 0; i < (int) line.length(); ++i)
			if (line[i] != ' ')
				line[i] = decoding[line[i] - 'a'];
		cout << "Case #" << test << ": " << line << endl;
	}
}

