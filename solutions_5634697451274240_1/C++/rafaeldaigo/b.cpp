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
	scanf("%d\n", &teste);
	for (int t = 0; t < teste; t++)
	{
		char p[1000];
		scanf("%s\n", p);

		int resp = 0;
		int pos = strlen(p) - 1;
		while(pos >= 0 && p[pos] == '+')
		{
			pos--;
		}
		char last = '+';
		for (; pos >= 0; pos--)
		{
			if (p[pos] != last)
			{
				resp++;
				last = p[pos];
			}
		}
		printf("Case #%d: %d\n", t + 1, resp);
	}
	return 0;
}
