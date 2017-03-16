#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char ch[10][10];
int main()
{
    freopen("aa.in","r",stdin);
    freopen("aa.out","w",stdout);
    int i,j,k;
    int T;
    scanf("%d",&T);
    int tt=0;
    bool isover,xwin,owin;
    while(T--)
    {
        tt++;
        for(i=0;i<4;i++) scanf("%s",ch[i]);
        isover=true;xwin=owin=false;
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                if(ch[i][j]!='O'&&ch[i][j]!='X'&&ch[i][j]!='T') isover=false;
        for(i=0;i<4;i++) if(ch[i][i]!='X'&&ch[i][i]!='T') break;
        if(i==4) xwin=true;
        for(i=0;i<4;i++) if(ch[i][3-i]!='X'&&ch[i][3-i]!='T') break;
        if(i==4) xwin=true;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(ch[i][j]!='X'&&ch[i][j]!='T') break;
            }if(j==4) xwin=true;
            for(j=0;j<4;j++)
            {
                if(ch[j][i]!='X'&&ch[j][i]!='T') break;
            }if(j==4) xwin=true;
        }

        for(i=0;i<4;i++) if(ch[i][i]!='O'&&ch[i][i]!='T') break;
        if(i==4) owin=true;
        for(i=0;i<4;i++) if(ch[i][3-i]!='O'&&ch[i][3-i]!='T') break;
        if(i==4) owin=true;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(ch[i][j]!='O'&&ch[i][j]!='T') break;
            }if(j==4) owin=true;
            for(j=0;j<4;j++)
            {
                if(ch[j][i]!='O'&&ch[j][i]!='T') break;
            }if(j==4) owin=true;
        }
        printf("Case #%d: ",tt);
        if(xwin) printf("X won\n");
        else if(owin) printf("O won\n");
        else if(isover) printf("Draw\n");
        else printf("Game has not completed\n");
    }
    return 0;
}
