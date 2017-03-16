#include <cstdio>
#include <cstring>

int main()
{
	int T, test, n, i, j, k, len, count, resp;
	char L[1000 + 1];

	scanf("%d", &T);
	for (test = 1; test <= T; test++)
	{
		scanf("%s", &L[0]);
		scanf("%d", &n);

		len = strlen(L);

		resp = 0;
		for (i = 0; i < len; i++)
		{
			for (j = i; j < len; j++)
			{
				for (k = i, count = 0; k <= j; k++)
				{
					if (L[k] == 'a' || L[k] == 'o' || L[k] == 'e' || L[k] == 'u' || L[k] == 'i')
					{
						count = 0;
					}
					else if (++count == n)
					{
						resp++;
						break;
					}
				}
			}
		}

		printf("Case #%d: %d\n", test, resp);
	}

	return 0;
}
