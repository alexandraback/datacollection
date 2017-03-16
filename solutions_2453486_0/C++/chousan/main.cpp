#include<stdio.h>
#include<iostream>
using namespace std;
char map[10][10];
bool check(char a)
{
    int i,j;
      for(i=0; i<4; ++i)
        {
            for(j=0; j<4; ++j)
            {
                if(map[i][j]!=a&&map[i][j]!='T')break;

            }
            if(j==4)return true;
        }
        for(i=0; i<4; ++i)
        {
            for(j=0; j<4; ++j)
            {
                if(map[j][i]!=a&&map[j][i]!='T')break;
            }
            if(j==4)return true;
        }
        for(i=0;i<4;++i)
        {
            if(map[i][i]!=a&&map[i][i]!='T')break;
        }
        if(i==4)return true;
        for(i=0;i<4;++i)
        {
            if(map[i][3-i]!=a&&map[i][3-i]!='T')break;
        }
        if(i==4)return true;
        return false;
}
bool man()
{
    int i,j;
    for(i=0;i<4;++i)
    {
        for(j=0;j<4;++j)
        {
            if(map[i][j]=='.')return false;
        }
    }
    return true;
}
int main()
{
    freopen("1.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    for(int c=1; c<=cas; ++c)
    {
        int i,j;
        printf("Case #%d: ",c);
        for(i=0; i<4; ++i)
        {
            scanf("%s",map[i]);
        }
        if(check('X'))printf("X won\n");
        else if(check('O'))printf("O won\n");
        else if(man())printf("Draw\n");
        else printf("Game has not completed\n");
    }
    return 0;
}
