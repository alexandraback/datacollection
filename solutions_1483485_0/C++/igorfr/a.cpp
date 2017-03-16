#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main (void)
{
    int t;
    map<char,char> m;

    m[' '] = ' ';

    m['a'] = 'y';
    m['b'] = 'h';
    m['c'] = 'e';
    m['d'] = 's';
    m['e'] = 'o';
    m['f'] = 'c';
    m['g'] = 'v';
    m['h'] = 'x';
    m['i'] = 'd';
    m['j'] = 'u';
    m['k'] = 'i';
    m['l'] = 'g';
    m['m'] = 'l';
    m['n'] = 'b';
    m['o'] = 'k';
    m['p'] = 'r';
    m['q'] = 'z';
    m['r'] = 't';
    m['s'] = 'n';
    m['t'] = 'w';
    m['u'] = 'j';
    m['v'] = 'p';
    m['w'] = 'f';
    m['x'] = 'm';
    m['y'] = 'a';
    m['z'] = 'q';

    scanf ("%d", &t);
    while (getchar() != '\n');

    for (int caso = 1; caso <= t; ++caso)
    {
        char linha[256];

        gets(linha);

        printf ("Case #%d: ", caso);

        int n = strlen(linha);
        for (int i = 0; i < n; ++i)
        {
            printf ("%c", m[linha[i]]);
        }
        printf ("\n");
    }

    return 0;
}

