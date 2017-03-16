#include <cstdio>
#include <cstdlib>

using namespace std;

char s[12][12];

bool is_win(char c)
{
    int c1, c2;
    for( int i = 0; i < 4; i++ )
    {
        c1 = c2 = 0;
        for( int j = 0; j < 4; j++ )
        {
            if( s[i][j] == c ) c1++;
            else if( s[i][j] == 'T' ) c2++;
        }
        if( ( c1 == 4 ) || ( c1 == 3 && c2 == 1 ) ) return true;
    }
    for( int i = 0; i < 4; i++ )
    {
        c1 = c2 = 0;
        for( int j = 0; j < 4; j++ )
        {
            if( s[j][i] == c ) c1++;
            else if( s[j][i] == 'T' ) c2++;
        }
        if( ( c1 == 4 ) || ( c1 == 3 && c2 == 1 ) ) return true;
    }
    c1 = c2 = 0;
    for( int i = 0; i < 4; i++ )
    {
        if( s[i][i] == c ) c1++;
        else if( s[i][i] == 'T' ) c2++;
    }
    if( ( c1 == 4 ) || ( c1 == 3 && c2 == 1 ) ) return true;
    c1 = c2 = 0;
    for( int i = 0; i < 4; i++ )
    {
        if( s[i][3 - i] == c ) c1++;
        else if( s[i][3 - i] == 'T' ) c2++;
    }
    if( ( c1 == 4 ) || ( c1 == 3 && c2 == 1 ) ) return true;
    return false;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    for( int tt = 1; tt <= cases; tt++ )
    {
        int count = 0;
        scanf("%s %s %s %s", &s[0], &s[1], &s[2], &s[3]);
        printf("Case #%d: ", tt);
        for( int i = 0; i < 4; i++ )
            for( int j = 0; j < 4; j++ )
                if( s[i][j] != '.' ) count++;
        if( is_win('O') ) puts("O won");
        else if( is_win('X') ) puts("X won");
        else if( count != 16 ) puts("Game has not completed");
        else puts("Draw");
    }
    return 0;
}
