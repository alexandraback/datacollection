#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

int code[32];
int T;
char line[256] = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
char ans[256] = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

int main()
{
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);
	for(int i = 0; i < strlen(line); ++i)
		code[line[i] - 'a'] = ans[i] - 'a';
	code['z' - 'a'] = 'q' - 'a';
	code['q' - 'a'] = 'z' - 'a';
	scanf("%d\n", &T);
	for(int t = 1; t <= T; ++t)
	{
		printf("Case #%d: ", t);
		gets(line);
		for(int i = 0; i < strlen(line); ++i)
			if(line[i] >= 'a' & line[i] <= 'z')
				printf("%c", code[line[i] - 'a'] + 'a');
			else
				printf("%c", line[i]);
		printf("\n");
	}
	return 0;
}