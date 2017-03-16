#include <cstdio>
#include <cstring>

const char *source = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
const char *target = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";

int mapping[26];
char line[120];

void getMapping()
{
	memset(mapping, -1, sizeof mapping);
	mapping['z' - 'a'] = 'q' - 'a';
	mapping['q' - 'a'] = 'z' - 'a';

	int len = strlen(source);
	for (int i = 0; i < len; i++)
	{
		mapping[target[i] - 'a'] = source[i] - 'a';
	}
}

void solve(int t)
{
	printf("Case #%d: ", t + 1);
	int len = strlen(line);
	for (int i = 0; i < len; i++)
	{
		char ch = line[i];
		if (ch != ' ' && ch != '\n')
		{
			ch = mapping[ch - 'a'] + 'a';
		}
		printf("%c", ch);
	}
}

int main()
{
	int T;
	getMapping();

	scanf("%d\n", &T);
	for (int i = 0; i < T; i++)
	{
		fgets(line, sizeof line, stdin);
		solve(i);
	}
}