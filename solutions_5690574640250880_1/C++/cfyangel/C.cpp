#include <cstring>
#include <cstdio>
#include <cstdlib>

int t,id,r,c,m;
int i,j,l,n;
char a[50][50];

void out()
{
    int i,j;
    for (i=0;i<r;i++)
    {
        for (j=0;j<c;j++)printf("%c",a[i][j]);
        printf("\n");
    }
}
int main()
{
    freopen("C-large.in","r",stdin);freopen("c.out","w",stdout);
    scanf("%d",&t);
    for (id=1;id<=t;id++)
    {
        scanf("%d%d%d",&r,&c,&m);
        printf("Case #%d:\n",id);
//printf("%d %d %d\n",r,c,m);
        memset(a,'*',sizeof(a));
        if (r*c-m==1)
        {
            a[0][0]='c';
            out();
        }
        else if (r==1)
        {
            for (i=1;i<=m;i++)printf("*");
            for (;i<c;i++)printf(".");
            printf("c\n");
        }
        else if (c==1)
        {
            for (i=1;i<=m;i++)printf("*\n");
            for (;i<r;i++)printf(".\n");
            printf("c\n");
        }
        else if (r==2)
        {
            if ((c-m/2>1) && (m%2==0))
            {
                for (i=1;i<=m/2;i++)printf("*");
                for (;i<c;i++)printf(".");
                printf("c\n");
                for (i=1;i<=m/2;i++)printf("*");
                for (;i<=c;i++)printf(".");
                printf("\n");
            }
            else
                printf("Impossible\n");
        }
        else if (c==2)
        {
            if ((r-m/2>1) && (m%2==0))
            {
                for (i=1;i<=m/2;i++)printf("**\n");
                for (;i<r;i++)printf("..\n");
                printf("c.\n");
            }
            else
                printf("Impossible\n");
        }
        else if (r*c-m<4 || r*c-m==5 || r*c-m==7 )  //2 3 5 7
        {
            printf("Impossible\n");
        }
        else  //4 6 8 9 10
        {
            l=r*c-m;
            if (l==4)
            for (i=0;i<2;i++)
                for (j=0;j<2;j++)a[i][j]='.';

            if (l==6)
            for (i=0;i<3;i++)
                for (j=0;j<2;j++)a[i][j]='.';

            if (l>=8)
            for (i=0;i<3;i++)
                for (j=0;j<3;j++)a[i][j]='.';
            a[2][2]='*';
            l-=8;

            if (l>0)
            {
                for (i=3;i<c && l>1;i++)
                {
                    a[0][i]=a[1][i]='.';
                    l-=2;
                }
                if (l<=c-2)
                {
                    for (i=2;i<l+2;i++)a[2][i]='.';
                    l=0;
                }
                else
                {
                    n=3;
                    a[3][0]=a[3][1]='.';
                    l-=2;
                    while(l>(c-2)*2)
                    {
                        l-=c;
                        for (i=2;i<c;i++)a[n-1][i]='.';
                        a[n+1][0]=a[n+1][1]='.';
                        n++;
                    }
                    if (l>=c-2)
                    {
                        l-=c-2;
                        for (i=2;i<c;i++)a[n-1][i]='.';
                        n++;
                    }
                    for (i=2;i<2+l;i++)a[n-1][i]='.';
                }
            }

            a[0][0]='c';

            out();
        }
    }
    return 0;
}
