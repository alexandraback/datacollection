#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int w[20];

void prework()
{
    w[0]=1;
    for (int i=1;i<16;i++)
        w[i]=w[i-1]<<1;
}

int T;
char map[4][4];
int a,b,now;
int ans[10]={15,240,3840,61440,4369,8738,17476,34952,33825,4680};
bool flag;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    prework();
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        getchar();
        for (int i=0;i<4;i++) gets(map[i]);
        a=b=0;
        now=-1;
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++)
            {
                now++;
                if (map[i][j]=='X') a=a|w[now];
                if (map[i][j]=='O') b=b|w[now];
                if (map[i][j]=='T')
                {
                    a=a|w[now];
                    b=b|w[now];
                }
            }
        flag=false;
        printf("Case #%d: ",t);
        for (int i=0;i<10;i++)
        {
            if ((a&ans[i])==ans[i])
            {
                printf("X won\n");
                flag=true;
                break;
            }
            if ((b&ans[i])==ans[i])
            {
                printf("O won\n");
                flag=true;
                break;
            }
        }
        if (flag) continue;
        if ((a|b)==65535) printf("Draw\n");
            else printf("Game has not completed\n");
    }
}
