#include <stdio.h>
#include <string.h>

char s[10][10];
bool ans[2];
int now[4];

bool good(int now[4],int x)
{
    int num=0;
    for(int i=0;i<4;i++)
     if (now[i]==x||now[i]==2) num++;
    return num==4;
}

bool ck(bool &x,bool y)
{
    if (y==1) x=1;
}

int main()
{
    int cas;

    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&cas);
    for(int ii=1;ii<=cas;ii++)
    {
        int empty=0;
        for(int i=0;i<4;i++)
        {
            scanf("%s",s[i]);
            for(int j=0;j<4;j++)
            {
                if (s[i][j]=='X') s[i][j]=0; else
                if (s[i][j]=='O') s[i][j]=1; else
                if (s[i][j]=='T') s[i][j]=2; else
                {
                    s[i][j]=3;
                    empty++;
                }
            }
        }
        for(int yo=0;yo<2;yo++)
        {
            ans[yo]=0;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                    now[j]=s[i][j];
                ck(ans[yo],good(now,yo));
                for(int j=0;j<4;j++)
                    now[j]=s[j][i];
                ck(ans[yo],good(now,yo));
            }
            for(int i=0;i<4;i++)
                now[i]=s[i][i];
            ck(ans[yo],good(now,yo));
            for(int i=0;i<4;i++)
                now[i]=s[3-i][i];
            ck(ans[yo],good(now,yo));
        }
        printf("Case #%d: ",ii);
        if (ans[0]) puts("X won"); else
        if (ans[1]) puts("O won"); else
        if (empty) puts("Game has not completed");
        else puts("Draw");
    }
    return 0;
}
