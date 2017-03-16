#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

char table[10][10];
bool isWin(char ch)
{
    for (int i = 0; i < 4; i++)
    {
        int j = 0;
        for (; j < 4; j++)
        {
            if (table[i][j] != ch &&
            table[i][j] != 'T')
            {
                break;
            }
        }
        if (j == 4)
        {
            return true;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int j = 0;
        for (; j < 4; j++)
        {
            if (table[j][i] != ch &&
            table[j][i] != 'T')
            {
                break;
            }
        }
        if (j == 4)
        {
            return true;
        }
    }
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        if (table[i][i] != ch && 
        table[i][i] != 'T')
        {
            break;
        }
    }
    if (i == 4)
    {
        return true;
    }
    for (i = 0; i < 4; i++)
    {
        if (table[i][3 - i] != ch && 
        table[i][3 -i] != 'T')
        {
            break;
        }
    }
    if (i == 4)
    {
        return true;
    }
    return false;
}
bool isAllComplete()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (table[i][j] == '.')
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int T;
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    while (scanf("%d", &T) != EOF)
    {
        for (int ca = 0; ca < T; ca++)
        {
            
            for (int i = 0; i < 4; i++)
            {
                scanf("%s", table[i]);
            }
            printf("Case #%d: ", ca + 1);
            if (isWin('O'))
            {
                printf("O won\n");
            }
            else if(isWin('X'))
            {
                printf("X won\n");
            }
            else if(!isAllComplete())
            {
                printf("Game has not completed\n");
            }
            else 
            {
                printf("Draw\n");
            }
        }
    }
    
}
