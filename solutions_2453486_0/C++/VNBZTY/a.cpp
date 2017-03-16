#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
int tt,tot;
char map[20][20];
int a[20];
bool work()
{
    for(int i=1;i<=4;++i)
    {
        memset(a,0,sizeof(a));
        for(int j=1;j<=4;++j)
        {
            if (map[i][j]=='X') ++a[0];
            if (map[i][j]=='O') ++a[1];
            if (map[i][j]=='T') ++a[0],++a[1];
        }
        if (a[0]==4) 
        {
            puts("X won");
            return true;
        }
        if (a[1]==4) 
        {
            puts("O won");
            return true;
        }
    }
    for(int i=1;i<=4;++i)
    {
        memset(a,0,sizeof(a));
        for(int j=1;j<=4;++j)
        {
            if (map[j][i]=='X') ++a[0];
            if (map[j][i]=='O') ++a[1];
            if (map[j][i]=='T') ++a[0],++a[1];
        }
        if (a[0]==4) 
        {
            puts("X won");
            return true;
        }
        if (a[1]==4) 
        {
            puts("O won");
            return true;
        }
    }
    memset(a,0,sizeof(a));
    for(int i=1;i<=4;++i)
    {
        if (map[i][i]=='X') ++a[0];
        if (map[i][i]=='O') ++a[1];
        if (map[i][i]=='T') ++a[0],++a[1];
    }
    if (a[0]==4) 
    {
        puts("X won");
        return true;
    }
    if (a[1]==4) 
    {
        puts("O won");
        return true;
    }
    memset(a,0,sizeof(a));
    for(int i=1;i<=4;++i)
    {
        if (map[i][4-i+1]=='X') ++a[0];
        if (map[i][4-i+1]=='O') ++a[1];
        if (map[i][4-i+1]=='T') ++a[0],++a[1];
    }
    if (a[0]==4) 
    {
        puts("X won");
        return true;
    }
    if (a[1]==4) 
    {
        puts("O won");
        return true;
    }
    return false;
}
int main()
{
freopen("A-small-attempt0.in","r",stdin);
freopen("test.out","w",stdout);
    scanf("%d",&tt);
    for(int o=1;o<=tt;++o)
    {
        tot=0;
        for(int i=1;i<=4;++i)
        {
            scanf("\n");
            for(int j=1;j<=4;++j)
            {
                scanf("%c",&map[i][j]);
                if (map[i][j]=='.') ++tot;
            }
        }
        printf("Case #%d: ",o);
        if(!work()) 
        {
            if (tot==0) puts("Draw");
            else puts("Game has not completed");
        }
    }
}
