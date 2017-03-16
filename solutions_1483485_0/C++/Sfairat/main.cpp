#include <cstdio>
#include <cstring>

char symbolMap[300];

char inp[] = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
char out[] = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

void buildsymbolMap()
{
	int len = strlen(inp);

	bool usedO[300];
	memset(usedO, 0, sizeof(usedO));
	memset(symbolMap, 0, sizeof(symbolMap));

	symbolMap['z'] = 'q';
	usedO['q'] = 1;

	for (int i = 0; i < len; i++)
	{
		symbolMap[inp[i]] = out[i];
		usedO[out[i]] = 1;
	}

	char unusedo = 0;

	for (int i = 'a'; i <= 'z'; i++)
	{
		if (!usedO[i])
			unusedo = i;
	}

	for (int i = 'a'; i <= 'z'; i++)
	{
		if (!symbolMap[i])
		{
			if (unusedo == 0)
				printf("Bida\n");
			symbolMap[i] = unusedo;
			unusedo = 0;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	buildsymbolMap();

	int n;
	scanf("%d", &n);

	char buf[150];

	for (int tc = 0; tc < n; tc++)
	{
		scanf(" ");
		//gets(buf);
		fgets(buf, 145, stdin);
		int len = strlen(buf);

		for (int i = 0; i < len; i++)
		{
			buf[i] = symbolMap[buf[i]];
		}

		printf("Case #%d: %s\n", tc+1, buf);
	}

	return 0;
}