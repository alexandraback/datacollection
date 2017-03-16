#include <stdio.h>
#include <string.h>

int all_are(char c, char *s, int len)
{
	int i;
	for(i = 0; i < len; i++)
		if(s[i] != c)
			return 0;
	return 1;
}

int count_flips(char c, char *s, int len)
{
	if(all_are(c, s, len))
		return 0;
	int pos = len - 1;
	while(s[pos] == c)
		pos--;
	return 1 + count_flips(c == '+' ? '-' : '+', s, pos + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	int test;
	for(test = 1; test <= T; test++)
	{
		char s[200];
		scanf("%s", s);
		int len = strlen(s);
		printf("Case #%d: %d\n", test, count_flips('+', s, len));
	}
}
