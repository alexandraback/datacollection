#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 6
using namespace std;
char map[MAXN][MAXN];
int process(char c)
{
    int C=0,X=0,O=0,D=0,T,cnt;
    for(int i=0;i<4;++i)
    {
        cnt=0,T=0;
        for(int j=0;j<4;++j)
        {
            if(map[i][j]==c) cnt++;
            else if(map[i][j]=='T') T++;
            else if(map[i][j]=='.') C++;
        }
        if(cnt==4) return 1;
        if(cnt==3&&T==1) return 1;
    }
    for(int i=0;i<4;++i)
    {
        cnt=0,T=0;
        for(int j=0;j<4;++j)
        {
            if(map[j][i]==c) cnt++;
            else if(map[j][i]=='T') T++;
        }
        if(cnt==4) return 1;
        if(cnt==3&&T==1) return 1;
    }
    cnt=0,T=0;
    for(int i=0;i<4;++i)
    {
        if(map[i][4-i-1]==c) cnt++;
        else if(map[i][4-i-1]=='T') T++;
    }
    if(cnt==4) return 1;
    if(cnt==3&&T==1) return 1;
    cnt=0,T=0;
    for(int i=0;i<4;++i)
    {
        if(map[i][i]==c) cnt++;
        else if(map[i][i]=='T') T++;
    }
    if(cnt==4) return 1;
    if(cnt==3&&T==1) return 1;
    if(C) return 2;
    else return 3;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t,T;
    scanf("%d",&t);
    T=t;
    while(t--)
    {
        for(int i=0;i<4;++i)
            scanf("%s",map[i]);
        int x=process('X');
        int o=process('O');
        printf("Case #%d: ",T-t);
        if(x==1)
            printf("X won\n");
        else if(o==1)
            printf("O won\n");
        else if(x==2)
            printf("Game has not completed\n");
        else printf("Draw\n");
    }
    return 0;
}
