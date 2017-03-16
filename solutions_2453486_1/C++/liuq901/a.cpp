#include <cstdio>
char a[10][10];
bool same(int x,int y,int dx,int dy,char ch)
{
    for (int i=1;i<=4;i++)
    {
        if (a[x][y]!=ch && a[x][y]!='T')
            return(false);
        x+=dx,y+=dy;
    }
    return(true);
}
bool win(char ch)
{
    for (int i=1;i<=4;i++)
        if (same(i,1,0,1,ch) || same(1,i,1,0,ch))
            return(true);
    return(same(1,1,1,1,ch) || same(1,4,1,-1,ch));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=1;i<=4;i++)
            scanf("%s",a[i]+1);
        static int id=0;
        printf("Case #%d: ",++id);
        if (win('O'))
            printf("O won\n");
        else if (win('X'))
            printf("X won\n");
        else
        {
            bool full=true;
            for (int i=1;i<=4;i++)
                for (int j=1;j<=4;j++)
                    if (a[i][j]=='.')
                        full=false;
            printf("%s\n",full?"Draw":"Game has not completed");
        }
    }
    return(0);
}

