#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int T;
string a, b, s;
map<char, char> m;

int main() {
	freopen("asmall.in", "r", stdin);
	freopen("asmall.out", "w", stdout);
	
	a = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	b = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

	for (int i = 0; i < a.size(); i++) m[a[i]] = b[i];
	m['z'] = 'q';
	m['q'] = 'z';

	cin >> T; getchar();
	for (int j = 1; j <= T; j++) {
		getline(cin, s);
		for (int i = 0; i < s.size(); i++) s[i] = m[s[i]];
		cout << "Case #" << j << ": " << s << endl;
	}
	
	fclose(stdout);
	return 0;
}
