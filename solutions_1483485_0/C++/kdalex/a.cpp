#include <string>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<char, char> r;

string src[] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string res[] = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};

int n;
string s;

int main() {
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < src[i].size(); j++)
			r[src[i][j]] = res[i][j];
	r['z'] = 'q';
	r['q'] = 'z';
	cin >> n;
	getline(cin, s);
	for(int i = 0; i < n; i++) {
		getline(cin, s);
		cout << "Case #" << i + 1 << ": ";
		for(int j = 0; j < s.size(); j++)
			if(s[j] != ' ')
				cout << r[s[j]];
			else
				cout << s[j];
		cout << endl;
	}
	return 0;
}