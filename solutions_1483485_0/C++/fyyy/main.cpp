#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

char mapp[] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int n;
	char input[128];
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		gets(input);
		printf("Case #%d: ", i);
		for (int j = 0; j < strlen(input); j++)
			if (islower(input[j]))
				putchar(mapp[input[j] - 'a']);
			else putchar(' ');
		puts("");
	}
	return 0;
}