#include <iostream>
#include <cstring>
using namespace std;
char w[1256], s[256];

int main()
{

    int n;
    w['a'] = 'y';
    w['b'] = 'h';
    w['c'] = 'e';
    w['d'] = 's';
    w['e'] = 'o';
    w['f'] = 'c';
    w['g'] = 'v';
    w['h'] = 'x';
    w['i'] = 'd';
    w['j'] = 'u';
    w['k'] = 'i';
    w['l'] = 'g';
    w['m'] = 'l';
    w['n'] = 'b';
    w['o'] = 'k';
    w['p'] = 'r';
    w['q'] = 'z';
    w['r'] = 't';
    w['s'] = 'n';
    w['t'] = 'w';
    w['u'] = 'j';
    w['v'] = 'p';
    w['w'] = 'f';
    w['x'] = 'm';
    w['y'] = 'a';
    w['z'] = 'q';
    scanf( "%d", &n );
    gets(s);
    int count = 0;
    for (int i = 0; i < n; ++i )
    {
        count += 1;
        printf( "Case #%d: ", count);
        gets(s);
        int len = strlen(s);
        for ( int j = 0; j < len; ++j )
        {
            if ( s[j] >= 'a' && s[j] <= 'z')
                printf( "%c", w[s[j]]);
            else
                printf( "%c", s[j]);
        }
        printf("\n");
    }

            
                

}

