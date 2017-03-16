#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int table[256];

char org[3][1000] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
char to[3][1000] = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};

void makeTable()
{
	fill(table, table + 256, -1);

	for (int i = 0; i < 3; ++i)
	{
		int ln = strlen(org[i]);
		for (int j = 0; j < ln; ++j)
		{
			table[org[i][j]] = to[i][j];
		}
	}
}

int main()
{
	makeTable();

	int t, cases = 0;
	char buf[1024];
	scanf("%d", &t);
	gets(buf);
	while (t--)
	{
		gets(buf);
		int ln = strlen(buf);
		table['q'] = 'z';
		table['z'] = 'q';
		for (int i = 0; i < ln; ++i)
			buf[i] = table[buf[i]];
		printf("Case #%d: %s\n", ++cases, buf);

	}
}