#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char map[10][10];

int check_row(int x,char c)
{
    int cnt=0,i;
    for (i=0;i<4;i++)
        if (map[x][i]==c||map[x][i]=='T')
            cnt++;
    return cnt==4?1:0;
}
int check_column(int x,char c)
{
    int cnt=0,i;
    for (i=0;i<4;i++)
        if (map[i][x]==c||map[i][x]=='T')
            cnt++;
    return cnt==4?1:0;
}
int check_draw()
{
    int cnt=0,i,j;
    for (i=0;i<4;i++)
        for (j=0;j<4;j++)
            if (map[i][j]!='.')
                cnt++;
    return cnt==16?1:0;
}
int check_dig(char c)
{
    int i,cnt;

    for (cnt=0,i=0;i<4;i++)
        if (map[i][i]==c||map[i][i]=='T')
            cnt++;
    if (cnt==4)
        return 1;
    for (cnt=0,i=0;i<4;i++)
        if (map[i][3-i]==c||map[i][3-i]=='T')
            cnt++;
    if (cnt==4)
        return 1;
    return 0;
}

int main()
{
    int t,i,j,ans,n,c1,c2,ys;

    freopen("A-large.in","r",stdin);
    freopen("dataAlarge.out","w",stdout);
    scanf("%d",&t);
    ys=0;
    while (t--)
    {
        for (i=0;i<4;i++)
            scanf("%s",map[i]);
        c1=c2=0;
        for (i=0;i<4;i++)
        {
            c1+=check_row(i,'O')+check_column(i,'O');
            c2+=check_row(i,'X')+check_column(i,'X');
        }
        c1+=check_dig('O');
        c2+=check_dig('X');

        if (c1>0&&c2==0)
            ans=1;
        else if (c1==0&&c2>0)
            ans=2;
        else if (check_draw())
            ans=0;
        else
            ans=4;

        printf("Case #%d: ",++ys);
        switch(ans)
        {
            case 0: printf("Draw\n"); break;
            case 1: printf("O won\n"); break;
            case 2: printf("X won\n"); break;
            case 4: printf("Game has not completed\n"); break;
        }
    }

    return 0;
}
