#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

#define MaxN 10

const char xWon[] = "X won";
const char oWon[] = "O won";
const char draw[] = "Draw";
const char notCompleted[] = "Game has not completed";

char s[4][MaxN];
int T;

bool Try( char c1, char c2, char s1, char s2, char s3, char s4 )
{
    int p1 = 0;
    int p2 = 0;
    p1 = ( s1 == c1 ) + ( s2 == c1 ) + ( s3 == c1 ) + ( s4 == c1 );
    p2 = ( s1 == c2 ) + ( s2 == c2 ) + ( s3 == c2 ) + ( s4 == c2 );

    if ( p1 == 4 ) return true;
    if ( p1 == 3 && p2 == 1 ) return true;

    return false;
}

bool Win( char c1, char c2 )
{
    bool ret = false;
    bool ok;

    for (int i = 0; i < 4; ++i) {
        ret |= Try( c1, c2, s[i][0], s[i][1], s[i][2], s[i][3] );
        ret |= Try( c1, c2, s[0][i], s[1][i], s[2][i], s[3][i] );
    }

    ret |= Try( c1, c2, s[0][0], s[1][1], s[2][2], s[3][3] );
    ret |= Try( c1, c2, s[0][3], s[1][2], s[2][1], s[3][0] );

    return ret;
}

int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);

    scanf("%d",&T);
    for (int t = 0; t < T; ++t) {
        for (int i = 0; i < 4; ++i)
            scanf("%s",s[i]);

        bool x = false;
        bool o = false;
        bool filled = true;

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if ( s[i][j] == '.' ) filled = false;

        x = Win( 'X', 'T' );
        o = Win( 'O', 'T' );

        printf("Case #%d: ",t+1);
        if ( x ) printf("%s\n",xWon);
        else if ( o ) printf("%s\n",oWon);
        else if ( filled ) printf("%s\n",draw);
        else printf("%s\n",notCompleted);
    }

    return 0;
}
