#include <cstdio>
#include <cassert>
#include <cctype>

#include <cstring>
char map[300];
int main()
{
	FILE *f0 = fopen("test.in", "r"),
		 *f1 = fopen("test.ans", "r");
	char c0, c1;
	char s0[1000] = {0}, s1[1000] = {0};
	fread(s0, 999, 1, f0);
	fread(s1, 999, 1, f1);
	//while (fscanf(f0, "%c", &c0) != EOF && fscanf(f1, "%c", &c1) != EOF)
	int t = strlen(s0);
	for (int i = 0; i < t; i ++)
	{
		c0 = s0[i], c1 = s1[i];
		if (s0[i] == 'e' && s0[i + 1] == 'o')
			int asdf = 0;
		if (isalpha(c0) && isalpha(c1))
		{
			if (c1 == 'i')
				int asdf =0;
			if (map[c0] && map[c0] != c1)
				printf("E: %c->%c,%c", c0, map[c0], c1);
			map[c0] = c1;
		}
	}
	map['z'] = 'q';
	bool tmp[300] = {0};
	for (char c = 'a'; c <= 'z'; c ++)
		tmp[map[c]] = true;
	int cnt = 0;
	for (char c = 'a'; c <= 'z'; c ++)
		if (!tmp[c])
			cnt ++;
	assert(cnt == 1);
	for (char c = 'a'; c <= 'z'; c ++)
	{
		if (!map[c])
		{
			for (int j = 'a'; j <= 'z'; j ++)
				if (!tmp[j])
					map[c] = j;
		}
	}

	fclose(f0);
	fclose(f1);

	int n;
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i ++)
	{
		printf("Case #%d: ", i);
		char str[1000] = {0};
		gets(str);
		for (int len = strlen(str),j = 0; j < len; j ++)
		{
			if (str[j] == 'e' && str[j + 1] == 'o')
				int asdf = 0;
			printf("%c", (str[j] >= 'a' && str[j] <= 'z') ? map[str[j]] : str[j]);
		}
		printf("\n");
	}
	return 0;
}

