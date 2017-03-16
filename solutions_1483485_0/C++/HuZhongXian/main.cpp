#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_NUM 256

int main(int argc, char* argv[])
{
	char filename[2][MAX_STR_NUM];
	sprintf(filename[0], "%s", "data.in");
	sprintf(filename[1], "%s.out", filename[0]);

	FILE* input = fopen(filename[0], "r");
	FILE* output = fopen(filename[1], "w");

	int map[256];
	bool use[256];
	memset(map, -1, sizeof(map));
	memset(use, 0, sizeof(use));
	char fuck1[] = "yeqejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	char fuck2[] = "aozour language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	for (int i = 0; i < strlen(fuck1); ++i)
	{
		map[fuck1[i]] = fuck2[i];
		use[fuck2[i]] = true;
	}
	for (int i = 'a'; i <= 'z'; ++i)
		if (map[i] == -1)
		{
			for (int j = 'a'; j <= 'z'; ++j)
				if (!use[j])
				{
					use[j] = true;
					map[i] = j;
					break;
				}
		}

	char buf[MAX_STR_NUM];
	fgets(buf, MAX_STR_NUM, input);
	for (int i = 0; i < 256; ++i)
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			break;
		}
	int T = atoi(buf);

	char data[30][MAX_STR_NUM];
	for (int i = 0; i < T; ++i)
	{
		fgets(data[i], MAX_STR_NUM, input);
		for (int j = 0; j < MAX_STR_NUM; ++j)
			if (data[i][j] == '\n' || data[i][j] == EOF)
			{
				data[i][j] = '\0';
				break;
			}
			else data[i][j] = map[data[i][j]];
		fprintf(output, "Case #%d: %s\n", i + 1, data[i]);
	}

	fclose(output);
	fclose(input);

//	system("pause");
	return 0;
}