#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
int n;
char g[MAXN];
char s[MAXN];
char p[30] =
    "yhesocvxduiglbkrztnwjpfmaq";
//   abcdefghijklmnopqrstuvwxyz

int main()
{	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int csnum;

	scanf ("%d", &csnum);
	getchar();
	for (int cs = 1; cs <= csnum; cs++)
	{
		gets(g);
		
		printf ("Case #%d: ", cs);
		for (int i = 0; g[i]; i++)
		{
			char ch = g[i];
			if (g[i] >= 'a' && g[i] <= 'z')
				ch = p[g[i] - 'a'];
			printf ("%c", ch);
		}
		puts("");
	}

//	for (int i = 0; i < 26; i++)
//		printf ("%c -> %c\n", (char)i + 'a', p[i]);

	return 0;
}
