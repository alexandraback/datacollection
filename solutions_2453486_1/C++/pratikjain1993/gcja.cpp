#include<iostream>
#include<stdio.h>
using namespace std;
char matrix[4][5];
bool check( char ch)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(matrix[i][j] != ch && matrix[i][j] != 'T')
            {
                break;
            }
        }
        if( j == 4)
        {
            return 1;
        }
        for( j = 0; j < 4; j++)
        {
            if(matrix[j][i] !=ch && matrix[j][i] != 'T')
            {
                break;
            }
        }
        if( j == 4)
        {
            return 1;
        }
    }
    for( i = 0; i < 4; i++)
    {
        if( matrix[i][i] != ch && matrix[i][i] != 'T')
        {
            break;
        }
    }
    if( i == 4)
    {
        return 1;
    }
    for(i = 0; i < 4; i++)
    {
        if( matrix[3-i][i] != ch && matrix[3-i][i] != 'T')
        {
            break;
        }
    }
    if( i == 4)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int t,i,j,c;
    #ifndef ONLINE_JUDGE
        freopen( "a2.in", "r", stdin);
    #endif
    scanf( "%d", &t);
    getchar();
    for( c = 1; c <= t; c++)
    {
        int complete = 1;
        for( i = 0; i < 4; i++)
        {
            for( j = 0; j < 4; j++)
            {
                scanf("%c", &matrix[i][j]);
                if( matrix[i][j] == '.')
                {
                    complete = 0;
                }
            }
            getchar();
        }
        getchar();
        printf("Case #%d: ",c);
        if( check('X'))
        {
            printf("X won\n");
        }
        else
        if( check('O'))
        {
            printf("O won\n");
        }
        else
        if( complete == 1)
        {
            printf( "Draw\n");
        }
        else
        {
            printf( "Game has not completed\n");
        }
    }
    return 0;
}
