#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t, teste;
	int n;
	scanf("%d\n", &teste);
	for (int t = 0; t < teste; t++)
	{
		char s[1100];
		scanf("%s\n", &s);
		int n = strlen(s);
		char inv[1100];
		int invc = 0;
		char norm[1100];
		int normc = 0;

		char last = 'A';
		for (int i = 0; i < n; i++)
		{
			if (s[i] >= last)
			{
				last = s[i];
				inv[invc++] = s[i];
			}
			else
			{
				norm[normc++] = s[i];
			}
		}
		norm[normc++] = 0;

		printf("Case #%d: ", t + 1, last);
		for (int i = invc - 1; i >= 0; i--)
		{
			printf("%c", inv[i]);
		}
		printf("%s", norm);
		printf("\n");
	}
	return 0;
}
