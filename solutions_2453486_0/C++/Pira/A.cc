#include <iostream>
#include <cstdio>
using namespace std;
char map[9][9];
void work()
{
    int i,j,owin=0,xwin=0,sum;
    for(sum=i=0;i<4;++i)
        for(j=0;j<4;++j)
            sum+=(map[i][j]!='.');
    for(i=0;i<4;++i)
    {
        for(j=0;j<4;++j)
            if(map[i][j]!='O'&&map[i][j]!='T')break;
        if(j>=4)owin=1;
        for(j=0;j<4;++j)
            if(map[i][j]!='X'&&map[i][j]!='T')break;
        if(j>=4)xwin=1;
    }
    for(j=0;j<4;++j)
    {
        for(i=0;i<4;++i)
            if(map[i][j]!='O'&&map[i][j]!='T')break;
        if(i>=4)owin=1;
        for(i=0;i<4;++i)
            if(map[i][j]!='X'&&map[i][j]!='T')break;
        if(i>=4)xwin=1;
    }
    for(i=j=0;i<4;++i,++j)
        if(map[i][j]!='O'&&map[i][j]!='T')break;
    if(i>=4)owin=1;
    for(i=j=0;i<4;++i,++j)
        if(map[i][j]!='X'&&map[i][j]!='T')break;
    if(i>=4)xwin=1;

    for(i=0,j=3;i<4;++i,--j)
        if(map[i][j]!='O'&&map[i][j]!='T')break;
    if(i>=4)owin=1;
    for(i=0,j=3;i<4;++i,--j)
        if(map[i][j]!='X'&&map[i][j]!='T')break;
    if(i>=4)xwin=1;
    if(owin&&xwin)puts("Draw");
    else if(owin)puts("O won");
    else if(xwin)puts("X won");
    else if(sum==16)puts("Draw");
    else puts("Game has not completed");
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int i,j,t,cs=0;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<4;++i)
            scanf("%s",map[i]);
        printf("Case #%d: ",++cs);
        work();
    }
    return 0;
}
