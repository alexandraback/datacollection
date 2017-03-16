#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const string sample[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
const string result[3] = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};

int test;
char map[30];

int main()
{
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < sample[i].size(); j++)
			if (sample[i][j] != ' ') map[sample[i][j] - 'a'] = result[i][j];
	map['z' - 'a'] = 'q';
	map['q' - 'a'] = 'z';
	//forr (char c = 'a'; c <= 'z'; c++) printf("%c = %c\n", c, map[c - 'a']);
	scanf("%d\n", &test);
	for (int num = 1; num <= test; num++)
	{
		string s, ans = "";
		getline(cin, s);
		for (int i = 0; i < s.size(); i++)
			ans += s[i] == ' ' ? ' ' : map[s[i] - 'a'];
		printf("Case #%d: %s\n", num, ans.c_str());
	}
	return 0;
}
