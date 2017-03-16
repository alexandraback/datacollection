#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>
#include <cstring>

using namespace std;

#define NextLine() { char c = getchar(); while (c != 10 && c != EOF) { c = getchar(); } }

char remap[256];

void LoadMap(string s, string t)
{
	int i;
	for (i = 0; i < s.length(); i++)
	{
		remap[s[i]] = t[i];
	}
}

string s;

void Load()
{
	char c = getchar();
	s = "";
	while (c != 10 && c != EOF)
	{
		s += c;
		c = getchar();
	}
}

void Solve()
{
	int i;
	for (i = 0; i < s.length(); i++)
	{
		printf("%c", remap[s[i]]);
	}
	printf("\n");
}

int main()
{
	memset(remap, 0xFF, sizeof(remap));
	LoadMap("aozq", "yeqz");
	LoadMap("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
	LoadMap("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
	LoadMap("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
	int nt;
	scanf("%d", &nt);
	NextLine();
	int it;
	for (it = 0; it < nt; it++)
	{
		Load();
		printf("Case #%d: ", it + 1);
		Solve();
	}
	return 0;
}