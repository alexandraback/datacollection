#include <cstdio>
#include <cstring>

#define MAX_LEN 1000+5

char buff[MAX_LEN];
char buff2[MAX_LEN*2];

int main()
{
	/*int max = 0;
	for (int i=1; i<1000000; ++i)
	{
		int c = count(i);
		if (c > max)
		{
			max = c;
			printf("%d: %d\n", i, c);
		}
	}*/
	int T;
	int N;
	scanf("%d\n", &T);

	for (int i=0; i<T; ++i)
	{
		scanf("%s\n", buff);
		printf("Case #%d: ", i+1);
		int j = MAX_LEN;
		buff2[j] = buff[0];
		for (int i=1; buff[i]; ++i)
		{
			buff2[j+i] = buff[i];
			buff2[j-1] = buff[i];
			if (strncmp(buff2 + j, buff2 + j - 1, i + 1) < 0)
				--j;
		}
		for (int i=0; buff[i]; ++i)
			printf("%c", buff2[j+i]);
		printf("\n");
	}
	return 0;
}
