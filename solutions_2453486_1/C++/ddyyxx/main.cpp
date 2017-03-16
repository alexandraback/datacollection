#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char bo[4][4];
int check()
{
    int i,j,tx=0,to=0,tru=0;
    for(i=0;i<4;i++)//枚举行
    {
        tx=to=0;
        for(j=0;j<4;j++)
        {
            if(bo[i][j]=='.')
            tru=1;
            if(bo[i][j]!='.'&&bo[i][j]!='O')
            tx++;
            if(bo[i][j]!='.'&&bo[i][j]!='X')
            to++;
        }
        if(tx==4)
        return 1;
        if(to==4)
        return 2;
    }
    for(j=0;j<4;j++)//枚举列
    {
        tx=to=0;
        for(i=0;i<4;i++)
        {
            if(bo[i][j]!='.'&&bo[i][j]!='O')
            tx++;
            if(bo[i][j]!='.'&&bo[i][j]!='X')
            to++;
        if(tx==4)
        return 1;
        if(to==4)
        return 2;
        }
    }
    tx=to=0;
    for(i=0;i<4;i++)
    {
        if(bo[i][i]!='.'&&bo[i][i]!='O')
        tx++;
        if(bo[i][i]!='.'&&bo[i][i]!='X')
        to++;
    }
    if(tx==4)
    return 1;
    if(to==4)
    return 2;
    tx=to=0;
    for(i=0;i<4;i++)
    {
        if(bo[i][3-i]!='.'&&bo[i][3-i]!='O')
        tx++;
        if(bo[i][3-i]!='.'&&bo[i][3-i]!='X')
        to++;
    }
    if(tx==4)
    return 1;
    if(to==4)
    return 2;
    if(tru)
    return 0;
    return 3;

}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("dd.txt","w+",stdout);
    int ncase,time=0;
    scanf("%d",&ncase);
    while(ncase--)
    {
        printf("Case #%d: ",++time);
        int i,j,tmp;
        for(i=0;i<4;i++)
        scanf("%s",bo[i]);
        tmp=check();
        if(tmp==1)
        printf("X won\n");
        else if(tmp==2)
        printf("O won\n");
        else if(tmp==3)
        printf("Draw\n");
        else
        printf("Game has not completed\n");
    }
    return 0;
}
