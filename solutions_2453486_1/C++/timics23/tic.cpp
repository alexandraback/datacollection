#include<stdio.h>
int T,a[5][5],ok=0,done=0;
char c;
int main()
{
    freopen("input.in","r",stdin);
    freopen("bla.out","w",stdout);
    scanf("%d",&T);
    for(int k=1;k<=T;++k)
    {
        scanf("%c",&c);
        ok=0;
        done=0;
        for(int i=1;i<=4;++i)
        {
            for(int j=1;j<=4;++j)
            {
                a[i][j]=0;
                scanf("%c",&c);
                if(c=='X')
                    a[i][j]=1;
                else if(c=='O')
                    a[i][j]=-1;
                else if(c=='T')
                    a[i][j]=8;
                else
                    done=1;

            }
            scanf("%c",&c);
        }
        int x=a[1][1]+a[1][2]+a[1][3]+a[1][4];

        if(x==4 || x==11)
        {
            if(ok==0)
                printf("Case #%d: X won\n",k);
            ok=1;
        }
        if(x==-4 || x==5)
        {
            if(ok==0)
            printf("Case #%d: O won\n",k);
            ok=1;
        }

        x=a[2][1]+a[2][2]+a[2][3]+a[2][4];

        if(x==4 || x==11)
        {
            if(ok==0)
            printf("Case #%d: X won\n",k);
            ok=1;
        }
        if(x==-4 || x==5)
        {
            if(ok==0)
            printf("Case #%d: O won\n",k);
            ok=1;
        }

        x=a[3][1]+a[3][2]+a[3][3]+a[3][4];

        if(x==4 || x==11)
        {
            if(ok==0)
            printf("Case #%d: X won\n",k);
            ok=1;
        }
        if(x==-4 || x==5)
        {
            if(ok==0)
            printf("Case #%d: O won\n",k);
            ok=1;
        }

        x=a[4][1]+a[4][2]+a[4][3]+a[4][4];

        if(x==4 || x==11)
        {
            if(ok==0)
            printf("Case #%d: X won\n",k);
            ok=1;
        }
        if(x==-4 || x==5)
        {
            if(ok==0)
            printf("Case #%d: O won\n",k);
            ok=1;
        }

        x=a[1][1]+a[2][1]+a[3][1]+a[4][1];

        if(x==4 || x==11)
        {
            if(ok==0)
            printf("Case #%d: X won\n",k);
            ok=1;
        }
        if(x==-4 || x==5)
        {
            if(ok==0)
            printf("Case #%d: O won\n",k);
            ok=1;
        }

        x=a[1][4]+a[2][4]+a[3][4]+a[4][4];

        if(x==4 || x==11)
        {
            if(ok==0)
            printf("Case #%d: X won\n",k);
            ok=1;
        }
        if(x==-4 || x==5)
        {
            if(ok==0)
            printf("Case #%d: O won\n",k);
            ok=1;
        }

        x=a[1][2]+a[2][2]+a[3][2]+a[4][2];

        if(x==4 || x==11)
        {
            if(ok==0)
            printf("Case #%d: X won\n",k);
            ok=1;
        }
        if(x==-4 || x==5)
        {
            if(ok==0)
            printf("Case #%d: O won\n",k);
            ok=1;
        }

        x=a[1][3]+a[2][3]+a[3][3]+a[4][3];

        if(x==4 || x==11)
        {
            if(ok==0)
            printf("Case #%d: X won\n",k);
            ok=1;
        }
        if(x==-4 || x==5)
        {
            if(ok==0)
            printf("Case #%d: O won\n",k);
            ok=1;
        }

        x=a[1][1]+a[2][2]+a[3][3]+a[4][4];

        if(x==4 || x==11)
        {
            if(ok==0)
            printf("Case #%d: X won\n",k);
            ok=1;
        }
        if(x==-4 || x==5)
        {
            if(ok==0)
            printf("Case #%d: O won\n",k);
            ok=1;
        }

        x=a[1][4]+a[2][3]+a[3][2]+a[4][1];

        if(x==4 || x==11)
        {
            if(ok==0)
            printf("Case #%d: X won\n",k);
            ok=1;
        }
        if(x==-4 || x==5)
        {
            if(ok==0)
            printf("Case #%d: O won\n",k);
            ok=1;
        }

        if(ok==0)
        {
            if(done==0)
                printf("Case #%d: Draw\n",k);
            else
                printf("Case #%d: Game has not completed\n",k);
        }

    }
    return 0;
}

