#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static inline int isVowel(char c)
{
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int main(int argc, char **argv)
{
	int tests; scanf("%d", &tests);
	char *name = malloc(1000002);
	int n, start, end, length, flag, count, i, laststart;
	for (i=1;i<=tests;++i)
	{
		scanf("%s %d", name, &n);
		length = strlen(name);
		count = 0;
		laststart = 0;
		for (start=0; start<=length - n; ++start)
		{
			flag = 0;
			for (end=start; end<start+n; ++end)
			{
				if (isVowel(name[end]))
				{
					start = end;
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				count += (start-laststart+1) * (length - end + 1);
				laststart = start+1;
			}
		}
		printf("Case #%d: %d\n", i, count);
	}
	return 0;
}
