#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const char d[30] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
char s[110];
int t;

int main()
{
	scanf("%d", &t);
	gets(s);
	int ca = 0;
	while (t--)
	{
		ca++;
		gets(s);
		int l = strlen(s);
		printf("Case #%d: ", ca);
		for (int i = 0; i < l; i++)
			if (s[i] >= 'a' && s[i] <= 'z')
				printf("%c", d[s[i] - 'a']);
			else printf("%c", s[i]);
		puts("");
	}
	return 0;
}
