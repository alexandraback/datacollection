#include <stdio.h>
#include <string.h>

char a[300];

int t;
char s1[210];

int main()
{
    freopen("A-small-attempt3.in","r",stdin);
    freopen("output.txt","w",stdout);
    a['a'] = 'y';
	a['b'] = 'h';
	a['c'] = 'e';
	a['d'] = 's';
	a['e'] = 'o';
	a['f'] = 'c';
	a['g'] = 'v';
	a['h'] = 'x';
	a['i'] = 'd';
	a['j'] = 'u';
	a['k'] = 'i';
	a['l'] = 'g';
	a['m'] = 'l';
	a['n'] = 'b';
	a['o'] = 'k';
	a['p'] = 'r';
	a['q'] = 'z';
	a['r'] = 't';
	a['s'] = 'n';
	a['t'] = 'w';
	a['u'] = 'j';
	a['v'] = 'p';
	a['w'] = 'f';
	a['x'] = 'm';
	a['y'] = 'a';
	a['z'] = 'q';
	a[' '] = ' ';
    int i,j,k,l;
    scanf("%d", &t);
    gets(s1);
    for (k = 1;k <= t;k++)
    {
        gets(s1);
        l = strlen(s1);
        for (i = 0;i < l;i++)
        {
            s1[i] = a[s1[i]];
        }
        printf("Case #%d: %s\n", k, s1);
    }
    return 0;
}
