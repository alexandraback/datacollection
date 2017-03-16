#include<iostream>
#include<cstdio>
using namespace std;
char s[10][10];
int check(char c)
{
    int cnt;
    for(int i=0;i<4;i++)
    {
        cnt=0;
        for(int j=0;j<4;j++)
            if(s[i][j]==c||s[i][j]=='T')
            cnt++;
        if(cnt==4)return 1;
    }
    for(int j=0;j<4;j++)
    {
        cnt=0;
        for(int i=0;i<4;i++)
            if(s[i][j]==c||s[i][j]=='T')
            cnt++;
        if(cnt==4)return 1;
    }
    cnt=0;
    for(int i=0;i<4;i++)
        if(s[i][i]==c||s[i][i]=='T')
            cnt++;
    if(cnt==4)return 1;

    cnt=0;
    for(int i=0;i<4;i++)
        if(s[i][3-i]==c||s[i][3-i]=='T')
        cnt++;
    if(cnt==4)return 1;
    return 0;

}

int hasdot()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        if(s[i][j]=='.')
            return 1;
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        printf("Case #%d: ",cas);
        for(int i=0;i<4;i++)
            scanf(" %s",s[i]);
        if(check('X'))
            printf("X won\n");
        else if(check('O'))
            printf("O won\n");
        else if(hasdot())
            printf("Game has not completed\n");
        else
            printf("Draw\n");
    }
    return 0;
}
