#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:268435456")

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

string s1 = string("ejp mysljylc kd kxveddknmc re jsicpdrysi") +
			string("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd") +
			string("de kr kd eoya kw aej tysr re ujdr lkgc jv");
string s2 = string("our language is impossible to understand") +
			string("there are twenty six factorial possibilities") +
			string("so it is okay if you want to just give up");

map<char, char> mp;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (int i = 0; i < (int)s1.length(); i++)
		mp[s1[i]] = s2[i];
	mp['z'] = 'q';
	mp['q'] = 'z';

	int testCount;
	scanf("%d\n", &testCount);
	for (int test = 1; test <= testCount; test++)
	{
		string s;
		getline(cin, s);

		printf("Case #%d: ", test);
		for (int i = 0; i < (int)s.length(); i++)
		{
			char ch = mp[s[i]];
			printf("%c", ch);
		}
		printf("\n");
	}

	return 0;
}