#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>


using namespace std;


const string ss[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
const string tt[3] = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};


char trans[128];

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	memset(trans, 0, sizeof(trans));

	for (int i = 0; i < 3; i ++)
		for (int j = 0; j < ss[i].length(); j ++)
			trans[ss[i][j]] = tt[i][j];

	trans['z'] = 'q';
	trans['q'] = 'z';

	int T;
	string s;
	cin >> T;
	getline(cin, s);
	for (int i = 1; i <= T; i ++)
	{
		cout << "Case #" << i << ": ";
		getline(cin, s);
		for (int j = 0; j < s.length(); j ++)
			cout << trans[s[j]];
			
		cout << endl;
	}

	return 0;
}