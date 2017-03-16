#include <cstdio>
//            abcdefghijklmnopqrstuvwxyz
char T[99] = "yhesocvxduiglbkrztnwjpfmaq";

char Str[10000];

int main()
{
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	fgets(Str, 10000, stdin);
	for (int Case = 1; Case <= Cases; Case ++)
	{
		fgets(Str, 10000, stdin);
		printf("Case #%d: ", Case);
		for (int i = 0; Str[i]; i ++)
			printf("%c", ('a' <= Str[i] && Str[i] <= 'z') ? T[Str[i] - 'a'] : Str[i]);
	}
	return 0;
}