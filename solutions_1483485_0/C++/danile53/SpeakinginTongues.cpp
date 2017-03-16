/*
 * Google Code Jam
 * Qualification Round 2012
 * Problem A. Speaking in Tongues
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

string hint[3] = { "ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv" };

string hint_decoded[3] = { "our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up", };

int main() {
	// build function
	char f[256];
	memset(f, 0, sizeof(f));
	f['q'] = 'z';
	f['z'] = 'q';
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < hint[i].length(); j++) {
			f[hint[i][j]] = hint_decoded[i][j];
		}

	// solve
	int tt;
	cin >> tt;
	string line;
	getline(cin, line);
	for (int t = 1; t <= tt; t++) {
		getline(cin, line);
		for (int j = 0; j < line.length(); j++)
			line[j] = f[line[j]];
		printf("Case #%d: ", t);
		cout << line << endl;
	}
	return 0;
}
