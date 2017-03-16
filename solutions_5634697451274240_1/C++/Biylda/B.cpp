#include <stdio.h>

int main(int argc, char **argv)
{
	char S[101];
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		scanf("%s", S);
		int flips = 0;
		char *begin = S;
		for (char *end = S+1; *end != 0; ++end)
		{
			if (*begin != *end)
			{
				++flips;
				begin = end;
			}
		}
		printf("Case #%d: %d\n", t+1, flips + (*begin == '-'));
	}
	return 0;
}
