#include <stdio.h>
#include <string.h>
#include <string>
#include <set>
#include <iostream>

using namespace std;

char map[500];
char str[150];

void construct()
{
    ////
    map['a'] = 'y';
    map['b'] = 'h';
    map['c'] = 'e';
    map['d'] = 's';
    map['e'] = 'o';
    map['f'] = 'c';
    map['g'] = 'v';
    map['h'] = 'x';
    map['i'] = 'd';
    map['j'] = 'u';
    map['k'] = 'i';
    map['l'] = 'g';
    map['m'] = 'l';
    map['n'] = 'b';
    map['o'] = 'k';
    map['p'] = 'r';
    map['q'] = 'z';
    map['r'] = 't';
    map['s'] = 'n';
    map['t'] = 'w';
    map['u'] = 'j';
    map['v'] = 'p';
    map['x'] = 'm';
    map['y'] = 'a';
    map['w'] = 'f';
    map['z'] = 'q';
////
}

int main()
{
   /* freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-output.out", "w", stdout);*/
    construct();
    int t;
    scanf("%d", &t);
    int tz = 1;
    getchar();
    while ( t-- )
    {
        gets(str);
        int tm = strlen(str);
        printf("Case #%d: ", tz++);
        for (int i = 0; i < tm; i++)
            printf("%c", (str[i] >= 'a' && str[i] <= 'z') ? map[str[i]] : str[i]);
        printf("\n");

    }
    return 0;
}
