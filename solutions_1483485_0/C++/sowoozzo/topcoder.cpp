#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <functional>
#include <sstream>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	char map[30];
	memset(map, 0, sizeof(map));
	string a[3] = { "ejp mysljylc kd kxveddknmc re jsicpdrysi", 
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	string b[3] = { "our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up"};
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < a[i].size(); j++)
		if (a[i][j] != ' ') 
			map[a[i][j]-'a'] = b[i][j];
	map['y'-'a'] = 'a';
	map['q'-'a'] = 'z';
	map['e'-'a'] = 'o';
	map['z'-'a'] = 'q';

	int T;
	cin >> T;
	char stmp[1000];
	gets(stmp);
	for (int t = 1; t <= T; t++) {
		string s;
		
		gets(stmp);
		s = string(stmp);
		string ts = s;
		for (int i = 0; i < s.size(); i++) if (s[i] != ' ') ts[i] = map[s[i]-'a'];
		printf("Case #%d: %s\n", t, ts.c_str());

	}
}