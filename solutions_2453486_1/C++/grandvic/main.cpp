/*
 * main.cpp
 *
 *  Created on: 06.04.2013
 *      Author: grand
 */

#include <stdio.h>

typedef char Field[4][5];

bool isWon(const Field &a, char who)
{
    for(int x=0; x<4; ++x)
    {
        bool won = true;
        for(int y=0; y<4; ++y)
        {
            if((a[x][y] != who) && (a[x][y]!='T'))
            {
                won=false;
                break;
            }
        }
        if(won)return true;
    }

    for(int y=0; y<4; ++y)
    {
        bool won = true;
        for(int x=0; x<4; ++x)
        {
            if((a[x][y] != who) && (a[x][y]!='T'))
            {
                won=false;
                break;
            }
        }
        if(won)return true;
    }

    bool won = true;
    for(int x=0; x<4; ++x)
    {
        if((a[x][x] != who) && (a[x][x]!='T'))
        {
            won=false;
            break;
        }
    }
    if(won)return true;

    won = true;
    for(int x = 0; x < 4; ++x)
    {
        if((a[x][3-x] != who) && (a[x][3-x] != 'T'))
        {
            won = false;
            break;
        }
    }
    if(won) return true;
    return false;
}

bool noPoints(const Field &a)
{
    for(int x=0; x<4; ++x)
    {
        for(int y=0; y<4; ++y)
        {
            if(a[x][y]=='.')return false;
        }
    }
    return true;
}

void analyze(const Field &a)
{
    if(isWon(a, 'X'))printf("X won\n");
    else if(isWon(a, 'O'))printf("O won\n");
    else if(noPoints(a))printf("Draw\n");
    else printf("Game has not completed\n");
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int t=1; t<=N; ++t)
    {
        Field a;
        for(int i=0; i<4; ++i)
        {
            a[i][0]=0;
            while(!a[i][0])
            {
                scanf("%s", &a[i][0]);
            }
        }
        printf("Case #%d: ", t);
        analyze(a);
    }

    return 0;
}

