#include <cstdio>
#include <cstdlib>
#include <iostream>

const char A[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y qee z";
const char B[] = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a zoo q";

int map[26];
void calmap()
{
	int i;
	for (i = 0; A[i]; i++)
		if (A[i] >= 'a' && A[i] <= 'z')
			map[A[i] - 'a'] = B[i] - 'a';
}
char str[200];
int T, l;
int main(void)
{
	int i, c;
	calmap();
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (c = 1; c <= T; c++)
	{
		printf("Case #%d: ", c);
		scanf("\n%[^\n]", str);
		for (i = 0; str[i]; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				printf("%c", map[str[i] - 'a'] + 'a');
			else
				printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}
