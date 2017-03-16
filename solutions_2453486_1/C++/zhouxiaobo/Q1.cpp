#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int SIZE=4; //棋盘大小 

int status(int c[SIZE][SIZE]) //判断是否已经决出胜负，并返回获胜者 
{
    int i,j,s[3];
    for(i=0;i<SIZE;++i)
    {
        s[1]=s[2]=0;
        for(j=0;j<SIZE;++j)
            ++s[c[i][j]];
        if (s[1]==SIZE) return 1;
        if (s[2]==SIZE) return -1;
    }
    for(j=0;j<SIZE;++j)
    {
        s[1]=s[2]=0;
        for(i=0;i<SIZE;++i)
            ++s[c[i][j]];
        if (s[1]==SIZE) return 1;
        if (s[2]==SIZE) return -1;
    }
    
    s[1]=s[2]=0;
    for(i=0;i<SIZE;++i)
        ++s[c[i][i]];
    if (s[1]==SIZE) return 1;
    if (s[2]==SIZE) return -1;

    s[1]=s[2]=0;
    for(i=0;i<SIZE;++i)
        ++s[c[i][SIZE-1-i]];
    if (s[1]==SIZE) return 1;
    if (s[2]==SIZE) return -1;

    return 0;  
}

int c[SIZE][SIZE];

int main(void)
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int U,i,j;
    scanf("%d",&U);
    char st[20];
    for(int T = 1; T <= U; ++T)
    {
        gets(st);
        int c[SIZE][SIZE]={};
        int turn=1;
        int xx = -1, yy = -1;
        for(i=0;i<SIZE;++i)
        {
            gets(st);
            for(j=0;j<SIZE;++j)
            {
                if (st[j]=='X')
                {
                    c[i][j]=1;
                    ++turn;
                }
                if (st[j]=='O')
                {
                    c[i][j]=2;
                    ++turn;
                }
                if (st[j]=='T')
                {
                    xx = i;
                    yy = j;
                    ++turn;
                }
            }
        }
        if (xx < 0)
        {
            int g = status(c);
            if (g == -1)
                printf("Case #%d: O won\n", T);
            if (g == 1)
                printf("Case #%d: X won\n", T);
            if (g == 0 && turn > SIZE*SIZE)
                printf("Case #%d: Draw\n", T);
            if (g == 0 && turn <= SIZE*SIZE)
                printf("Case #%d: Game has not completed\n", T);
        }
        else
        {
            int g;
            c[xx][yy] = 1;
            g = status(c);
            if (g == 1)
            {
                printf("Case #%d: X won\n", T);
                continue;
            }
            c[xx][yy] = 2;
            g = status(c);
            if (g == -1)
            {
                printf("Case #%d: O won\n", T);
                continue;
            }
            g = 0;
            if (g == 0 && turn <= SIZE*SIZE)
                printf("Case #%d: Game has not completed\n", T);
            if (g == 0 && turn > SIZE*SIZE)
                printf("Case #%d: Draw\n", T);
        }
    }
    return 0;
}
