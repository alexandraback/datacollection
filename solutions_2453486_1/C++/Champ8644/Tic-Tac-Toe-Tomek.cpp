#include<cstdio>
char bg[4][5];
int checkwin (char *x)
{
    char t;
    for (int i=0;i<4;i++)
        if (x[i]=='.')
            return 0;
    t = x[0];
    if (t=='T')
        t = x[1];
    for (int i=0;i<4;i++)
        if (x[i]!='T' and x[i]!=t)
            return 0;
    if (t=='X')
        return 1;
    return 2;
}
int check ()
{
    char x[4];
    int i,j;
    for (i=0;i<4;i++)
        x[i] = bg[i][i];
    if (checkwin(x))
        return checkwin(x);
    for (i=0;i<4;i++)
        x[i] = bg[i][3-i];
    if (checkwin(x))
        return checkwin(x);
    for (j=0;j<4;j++)
    {
        for (i=0;i<4;i++)
            x[i] = bg[i][j];
        if (checkwin(x))
            return checkwin(x);
        for (i=0;i<4;i++)
            x[i] = bg[j][i];
        if (checkwin(x))
            return checkwin(x);
    }
    for (i=0;i<4;i++)
        for (j=0;j<4;j++)
            if (bg[i][j]=='.')
                return 4;
    return 3;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out_tic-tac-toe-tomek-large.txt","w",stdout);
    int tt,T,i,j;
    scanf("%d",&T);
    for (tt=1;tt<=T;tt++)
    {
        for (i=0;i<4;i++)
            scanf("%s",bg[i]);
        printf("Case #%d: ",tt);
        switch(check())
        {
        case 1 :
            printf("X won\n");
            break;
        case 2 :
            printf("O won\n");
            break;
        case 3 :
            printf("Draw\n");
            break;
        case 4 :
            printf("Game has not completed\n");
            break;
        }
    }
    return 0;
}
