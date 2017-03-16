#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <cctype>
#include <cmath>
using namespace std;

#define UN(c) SORT(c),v.erase(unique(c.begin(),c.end()),c.end())
#define SORT(c) sort(c.begin(), c.end())

char cmap[256] = {0};
bool reset[256] = {0};
bool used[256] = {0};

void teach(const char *from, const char *to) {
	while(*from != '\0') {
		reset[*from] = true; used[*to] = true;
		cmap[*from++] = *to++;
	}
}

int main()
{
	if( freopen("A-small.in", "rt", stdin) ) {
		freopen("A-small.out", "wt", stdout);
	} else ( freopen("test.txt", "rt", stdin) );

	int T;
	cin >> T;
	cerr << "Total test cases: " << T << endl;

	for(int i = 0; i < 256; ++i) cmap[i] = char(i);
	cmap['a'] = 'y'; reset['a'] = true; used['y'] = true;
	cmap['o'] = 'e'; reset['o'] = true; used['e'] = true;
	cmap['z'] = 'q'; reset['z'] = true; used['q'] = true;
	teach("ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"our language is impossible to understand");
	teach("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"there are twenty six factorial possibilities");
	teach("de kr kd eoya kw aej tysr re ujdr lkgc jv",
		"so it is okay if you want to just give up");
	for(int i = 'a'; i <= 'z'; ++i) {
		if(!reset[i]) {
			for(int j = 'a'; j <= 'z'; ++j)
				if(!used[j]) {
					cmap[i] = j; reset[i] = used[j] = true;
				}
		}
	}
	for(int case_num = 1; case_num <= T; ++case_num)
	{
		cerr << case_num << endl;
		string str;
		do { getline(cin, str); } while( str.empty() );
		cout << "Case #" << case_num << ": ";
		for(string::iterator it = str.begin(); it != str.end(); ++it) {
			cout << cmap[*it];
		}
		cout << endl;
	}
 	return 0;
}

