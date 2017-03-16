#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int N, test, len;
	int i, j;
	int consonantCount;
	long long count;
	int start, n;
	char isTrue;
	char tempInput[10];
	char input[1000050];
	char name[1000010];
	fgets(tempInput, 10, stdin);
	sscanf(tempInput, "%d", &N);
	for (test = 1; test <= N; test++)
	{
		fgets(input, 1000050, stdin);
		sscanf(input, "%s %d", name, &n);
		len = strlen(name);
		start = 0;
		consonantCount = 0;
		isTrue = 0;
		count = 0;
		for (i = 0; i < len; i++)
		{
			if (name[i] != 'a' && name[i] != 'i' && name[i] != 'u' &&
				name[i] != 'e' && name[i] != 'o')
			{
				consonantCount++;
				if (isTrue)
				{
					count += len - i;
				}
				else
				{
					if (consonantCount >= n)
					{
						count += (long long) ((i - n - start) + 2) * (len - i);
						isTrue = 1;
					}
				}
			}
			else
			{
				if (isTrue)
				{
					start = i - n + 1;
				}
				consonantCount = 0;
				isTrue = 0;
			}
		}
		printf("Case #%d: %lld\n", test, count);
	}
	return 0;
}

