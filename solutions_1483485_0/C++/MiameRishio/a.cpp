#include <iostream>
using namespace std;

char sample1[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
char sample2[] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
char sample3[] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
char sample4[] = "y qee";

char result1[] = "our language is impossible to understand";
char result2[] = "there are twenty six factorial possibilities";
char result3[] = "so it is okay if you want to just give up";
char result4[] = "a zoo";

char wordMapping[256];
int main()
{
	freopen("A-small-attempt3.in", "r", stdin);
	freopen("A-small-attempt3.out", "w", stdout);
	for (int i = 0; i < 256; i++)
		wordMapping[i] = '0';
	for (int i = 0; i < strlen(sample1); i++)
		wordMapping[sample1[i]] = result1[i];
	for (int i = 0; i < strlen(sample2); i++)
		wordMapping[sample2[i]] = result2[i];
	for (int i = 0; i < strlen(sample3); i++)
		wordMapping[sample3[i]] = result3[i];
	for (int i = 0; i < strlen(sample4); i++)
		wordMapping[sample4[i]] = result4[i];
	wordMapping['z'] = 'q';

	int nTestCase;
	scanf("%d\n", &nTestCase);
	char str[1000];
	for (int i = 0; i < nTestCase; i++)
	{
		printf("Case #%d: ", i + 1);
		gets(str);
		for(int j = 0; j < strlen(str); j++)
		{
			if ('a' <= str[j] && str[j] <= 'z')
				printf("%c", wordMapping[str[j]]);
			else
				printf("%c", str[j]);
		}
		printf("\n");
	}
	return 0;
}