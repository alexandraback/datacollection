#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <string>
#define N 51111
#define Inf 1000000000
using namespace std;
char ch[6][6];
int check()
{
    for(int i=1;i<=4;i++)
    {
        int findx=0,findo=0,find=0;
        for(int j=1;j<=4;j++)
        {
            if(ch[i][j]=='.')
            {
                find=1;break;
            }
            if(ch[i][j]=='X')
                findx=1;
            if(ch[i][j]=='O')
                findo=1;
        }
        if(find)continue;
        if(!findx)return 2;
        if(!findo)return 1;
    }
    for(int i=1;i<=4;i++)
    {
        int findx=0,findo=0,find=0;
        for(int j=1;j<=4;j++)
        {
            if(ch[j][i]=='.')
            {
                find=1;break;
            }
            if(ch[j][i]=='X')
                findx=1;
            if(ch[j][i]=='O')
                findo=1;
        }
        if(find)continue;
        if(!findx)return 2;
        if(!findo)return 1;
    }
    int findx=0,findo=0,find=0;
    for(int i=1;i<=4;i++)
    {
        if(ch[i][i]=='.')
        {
            find=1;break;
        }
        if(ch[i][i]=='X')
            findx=1;
        if(ch[i][i]=='O')
            findo=1;
    }
    if(!find&&!findx)return 2;
    if(!find&&!findo)return 1;
    find=findx=findo=0;
    for(int i=1;i<=4;i++)
    {
        if(ch[i][5-i]=='.')
        {
            find=1;break;
        }
        if(ch[i][5-i]=='X')
            findx=1;
        if(ch[i][5-i]=='O')
            findo=1;
    }
    if(!find&&!findx)return 2;
    if(!find&&!findo)return 1;
    find=0;
    for(int i=1;i<=4&&!find;i++)
        for(int j=1;j<=4&&!find;j++)
            if(ch[i][j]=='.')
                find=1;
    if(find)return 3;
    return 4;
}
int main()
{
//    freopen("output.txt","w",stdout);
    int t,T=0;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=4;i++)
            for(int j=1;j<=4;j++)
                scanf(" %c",&ch[i][j]);
        int f=check();
        printf("Case #%d: ",++T);
        if(f==1)puts("X won");
        if(f==2)puts("O won");
        if(f==3)puts("Game has not completed");
        if(f==4)puts("Draw");
    }
    return 0;
}
