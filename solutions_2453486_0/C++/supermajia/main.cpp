#include <iostream>
#include <cstdio>
using namespace std;
char map[6][6];
bool judge(char c)
{
    int i,j;
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=4;j++)
        {
            if(map[i][j]!=c&&map[i][j]!='T')
                break;
        }
        if(j==5)
            return 1;
        for(j=1;j<=4;j++)
        {
            if(map[j][i]!=c&&map[j][i]!='T')
                break;
        }
        if(j==5)
            return 1;
    }
    for(i=1;i<=4;i++)
    {
        if(map[i][i]!=c&&map[i][i]!='T')
            break;
    }
    if(i==5)
        return 1;
    for(i=1;i<=4;i++)
    {
        if(map[5-i][i]!=c && map[5-i][i]!='T')
           break;
    }
    if(i==5)
        return 1;
    return 0;
}
bool isend()
{
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(map[i][j]=='.')
                return 0;
        }
    }
    return 1;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    int cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                char c=getchar();
                while(c!='.'&&c!='T'&&c!='X'&&c!='O')
                    c=getchar();
                map[i][j]=c;
            }
        }
        printf("Case #%d: ",cas++);
        if(judge('X'))
        {
            printf("X won\n");
            continue;
        }
        if(judge('O'))
        {
            printf("O won\n");
            continue;
        }
        if(isend())
        {
            printf("Draw\n");
            continue;
        }
        printf("Game has not completed\n");
    }
    return 0;
}
