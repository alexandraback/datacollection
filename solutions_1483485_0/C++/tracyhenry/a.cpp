#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;

map<char, char> M;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
	string s[3], w[3];
	s[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	s[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	s[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	w[0] = "our language is impossible to understand";
    w[1] = "there are twenty six factorial possibilities";
    w[2] = "so it is okay if you want to just give up";
	M.clear();
	for (int i = 0; i < 3; i ++)
		for (int j = 0; j < s[i].size(); j ++)
			M[s[i][j]] = w[i][j];
	M['z'] = 'q';
	M['q'] = 'z';
	int T;
	cin >> T;
	getline(cin, s[0]);
	for (int i = 1; i <= T; i ++)
	{
		string a;
		getline(cin, a);
		cout << "Case #" << i << ": ";
		for (int j = 0; j < a.size(); j ++)
			if (a[j] != ' ')
				cout << M[a[j]];
			else cout << ' ';
		cout << endl;
	}
	return 0;
}
