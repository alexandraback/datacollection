#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;

map<char, char> tr;
char str[1000];

int main() {
    tr['a'] = 'y';
    tr['b'] = 'h';
    tr['c'] = 'e';
    tr['d'] = 's';
    tr['e'] = 'o';
    tr['f'] = 'c';
    tr['g'] = 'v';
    tr['h'] = 'x';
    tr['i'] = 'd';
    tr['j'] = 'u';
    tr['k'] = 'i';
    tr['l'] = 'g';
    tr['m'] = 'l';
    tr['n'] = 'b';
    tr['o'] = 'k';
    tr['p'] = 'r';
    tr['q'] = 'z';
    tr['r'] = 't';
    tr['s'] = 'n';
    tr['t'] = 'w';
    tr['u'] = 'j';
    tr['v'] = 'p';
    tr['w'] = 'f';
    tr['x'] = 'm';
    tr['y'] = 'a';
    tr['z'] = 'q';
    tr[' '] = ' ';
    int i, n, t;
    scanf("%d", &t);
    getchar();
    for (int cas=1; cas<=t; cas++) {
        //scanf("%s", str);
        gets(str);
        n = strlen(str);
        for (i = 0; i < n; i++)
            str[i] = tr[str[i]];
        printf("Case #%d: %s\n", cas, str);
    }
    return 0;
}
