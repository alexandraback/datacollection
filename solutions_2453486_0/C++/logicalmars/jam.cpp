#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cassert>
using namespace std;

char map[10][10];

int check_same(string temp, char c)
{
    assert(temp.size() == 4);

    for (int i = 0;i<4;i++)
    {
        if (temp[i] != c && temp[i] != 'T')
            return 0;
    }

    return 1;
}

int check_win(char c)
{
    string temp = "";
    for (int i = 0;i<4;i++)
    {
        temp = map[i];
        if (check_same(temp, c))
            return 1;
    }

    for (int j = 0;j<4;j++)
    {
        temp = "";
        for (int i = 0;i<4;i++)
            temp += map[i][j];
        if (check_same(temp, c))
        {
            return 1;
        }
    }

    temp = "";
    for (int i = 0;i<4;i++)
        temp += map[i][i];
    if (check_same(temp, c))
        return 1;

    temp = "";    
    for (int i = 0;i<4;i++)
        temp += map[i][3-i];
    if (check_same(temp, c))
        return 1;

    return 0;
}

int check_uncomplete()
{
    for (int i =0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            if (map[i][j] == '.')
                return 1;
        }
    }

    return 0;
}

void work()
{
    for (int i = 0;i<4;i++)
    {
        scanf("%s", map[i]);
    }
    
    if (check_win('X'))
    {
        printf("X won\n");        
    }
    else if (check_win('O'))
    {
        printf("O won\n");
    }
    else if (check_uncomplete())
    {
        printf("Game has not completed\n");
    }   
    else
    {
        printf("Draw\n");
    }
}
 
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    // freopen("A-large-practice.in", "r", stdin);    
    // freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
 
    int cs, t;
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++)
    {
        printf("Case #%d: ", cs);
        work();
    }
 
    return 0;
}