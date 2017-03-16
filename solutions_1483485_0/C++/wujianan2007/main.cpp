#include <cstdio>
char p['z' + 1];
char s[105];

int main() {
    p['a'] = 'y';
    p['b'] = 'h';
    p['c'] = 'e';
    p['d'] = 's';
    p['e'] = 'o';
    p['f'] = 'c';
    p['g'] = 'v';
    p['h'] = 'x';
    p['i'] = 'd';
    p['j'] = 'u';
    p['k'] = 'i';
    p['l'] = 'g';
    p['m'] = 'l';
    p['n'] = 'b';
    p['o'] = 'k';
    p['p'] = 'r';
    p['q'] = 'z';
    p['r'] = 't';
    p['s'] = 'n';
    p['t'] = 'w';
    p['u'] = 'j';
    p['v'] = 'p';
    p['w'] = 'f';
    p['x'] = 'm';
    p['y'] = 'a';
    p['z'] = 'q';
    int t;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    scanf("%d", &t);
    getchar();
    for (int tt = 1; tt <= t; tt++) {
        printf("Case #%d: ", tt);
        gets(s);
        for (int i = 0; s[i] != 0; i++)
            if (s[i] == ' ') printf(" ");
            else printf("%c", p[s[i]]);
        printf("\n");
    }
    return 0;
}