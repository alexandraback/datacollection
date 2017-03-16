#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <string>
using namespace std;

string in[3] = { "ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv" };
string out[3] = { "our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up" };

char map[256];

char a[1000];

int main() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < in[i].size(); ++j) {
			map[in[i][j]] = out[i][j];
		}
	}
	map['q'] = 'z';
	map['z'] = 'q';

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		scanf(" ");
		gets(a);
		int l = strlen(a);
		cout << "Case #" << i + 1 << ": ";
		for (int j = 0; j < l; ++j) {
			if (a[j] == ' ')
				cout << a[j];
			else
				cout << map[a[j]];
		}
		cout << endl;
	}
	return 0;
}
