#include <cstdio>
#include <cstring>

const char a[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
char s[205];
int test;

int main()
{
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	
	scanf("%d", &test);
	getchar();
	for (int kase = 1; kase <= test; ++kase)
	{
		printf("Case #%d: ", kase);
		gets(s);
		int len = strlen(s);
		for (int i = 0; i != len; ++i)
			if (s[i] == ' ')
				printf(" ");
			else
				printf("%c", a[s[i] - 'a']);
		puts("");
	}
	
	return 0;
}
