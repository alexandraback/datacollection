#include <algorithm>
#include <cstdio>
#include <climits>
using namespace std;

char m[27] = "yhesocvxduiglbkrztnwjpfmaq";
char s[128];

int
main ()
{
	freopen ("As.in","r",stdin);
	freopen ("As.out","w",stdout);
	int t;
	scanf ("%d\n", &t);
	for (int tc = 1; tc <= t; tc ++){
		scanf ("%[^\n]\n", s);
		printf ("Case #%d: ", tc);
		for (int i = 0; s[i]; i ++)
			printf ("%c", s[i] == ' ' ? ' ' : m[s[i]-'a']);
		puts ("");
	}
	return 0;
}