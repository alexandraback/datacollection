#include <stdio.h>

char str[4][4];

bool row(int r,char ch)
{
    int i,cnt1=0,cnt2=0;
    for (i=0;i<4;i++)
    {
        if (str[r][i]==ch) cnt1++;
        else if (str[r][i]=='T') cnt2++;
    }
    return (cnt1==4)||(cnt1==3&&cnt2==1);
}

bool col(int c,char ch)
{
    int i,cnt1=0,cnt2=0;
    for (i=0;i<4;i++)
    {
        if (str[i][c]==ch) cnt1++;
        else if (str[i][c]=='T') cnt2++;
    }
    return (cnt1==4)||(cnt1==3&&cnt2==1);
}

bool diag1(char ch)
{
    int i,cnt1=0,cnt2=0;
    for (i=0;i<4;i++)
    {
        if (str[i][i]==ch) cnt1++;
        else if (str[i][i]=='T') cnt2++;
    }
    return (cnt1==4)||(cnt1==3&&cnt2==1);
}

bool diag2(char ch)
{
    int i,cnt1=0,cnt2=0;
    for (i=0;i<4;i++)
    {
        if (str[i][3-i]==ch) cnt1++;
        else if (str[i][3-i]=='T') cnt2++;
    }
    return (cnt1==4)||(cnt1==3&&cnt2==1);
}

int main()
{
    freopen("ain.txt","r",stdin);
    freopen("aout.txt","w",stdout);
    int test,cas,i,cnt,j;
    bool x,o;
    scanf("%d",&test);
    for (cas=1;cas<=test;cas++)
    {
        for (i=0;i<4;i++) scanf("%s",str[i]);
        x=o=0;
        for (i=0;i<4;i++)
        {
            if (row(i,'X')) x=1;
        }
        for (i=0;i<4;i++)
        {
            if (col(i,'X')) x=1;
        }
        if (diag1('X')) x=1;
        if (diag2('X')) x=1;
        if (x)
        {
            printf("Case #%d: X won\n",cas);
            continue;
        }
        for (i=0;i<4;i++)
        {
            if (row(i,'O')) o=1;
        }
        for (i=0;i<4;i++)
        {
            if (col(i,'O')) o=1;
        }
        if (diag1('O')) o=1;
        if (diag2('O')) o=1;
        if (o)
        {
            printf("Case #%d: O won\n",cas);
            continue;
        }
        cnt=0;
        for (i=0;i<4;i++)
        {
            for (j=0;j<4;j++)
            {
                if (str[i][j]=='.') cnt++;
            }
        }
        if (!cnt) printf("Case #%d: Draw\n",cas);
        else printf("Case #%d: Game has not completed\n",cas);
    }
    return 0;
}
