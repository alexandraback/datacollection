#include <bits/stdc++.h>
using namespace std;

char S[1111];
char ans[1111];

void insert(char *str, char ch, int ind, int old_len)
{
	str[old_len] = ch;
	str[old_len + 1] = '\0';
	for (int i = old_len; i > ind; i--)
	{
		char tmp = str[i];
		str[i] = str[i - 1];
		str[i - 1] = tmp;
	}
}

int main()
{
	int T;
	
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%s", S);
		memset(ans, '\0', sizeof(ans));
		for (int i = 0; S[i]; i++)
		{
			if (ans[0] <= S[i])
				insert(ans, S[i], 0, i);
			else
				insert(ans, S[i], i, i);
		}
		printf("Case #%d: %s\n", t, ans);
	}
	
	return 0;
}