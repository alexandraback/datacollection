#include<stdio.h>
using namespace std;
int t,r,c,m;
char ar[55][55];
bool bisa;
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);

    scanf("%d",&t);
    for (int ll=1;ll<=t;ll++)
    {
        scanf("%d %d %d",&r,&c,&m);

        bisa=1;
        for (int i=1;i<=r;i++)
            for (int j=1;j<=c;j++)
                ar[i][j]='.';

        if (r==1 || c==1)
        {
            if (r==1)
            {
                for (int i=1;i<=m;i++)
                    ar[1][i]='*';
                ar[1][c]='c';
            }
            else
            {
                for (int i=1;i<=m;i++)
                    ar[i][1]='*';
                ar[r][1]='c';
            }
        }
        else if (r==2 || c==2)
        {
            if (m%2==1 && (r*c)-m != 1)
                bisa=0;

            if ((r*c)-m < 4 && (r*c)-m > 1)
                bisa=0;

            if (bisa==1){
                if (r==2)
                {
                    for (int i=1;i<=m/2;i++)
                        ar[1][i]=ar[2][i]='*';

                    if ((r*c)-m == 1)
                        ar[1][c]='*';

                    ar[2][c]='c';
                }
                else
                {
                    for (int i=1;i<=m/2;i++)
                        ar[i][1]=ar[i][2]='*';

                    if ((r*c)-m == 1)
                        ar[r][1]='*';

                    ar[r][2]='c';
                }
            }
        }
        else
        {
            int x,y;
            x=r;
            y=c;
            while(x>3 && m>=y){
                for (int i=1;i<=c;i++)
                    ar[x][i]='*';
                x--;
                m-=y;
            }

            if (x>3 && m<c){
                if (m<=c-2)
                {
                    for (int i=1;i<=m;i++)
                        ar[x][i]='*';
                    x--;
                    m=0;
                }
                else
                {
                    for (int i=1;i<=c-2;i++)
                        ar[x][i]='*';
                    x--;
                    ar[x][1]='*';
                    m=0;
                }
            }

            if (m>0){
                if ((x*y)-m < 4 && (x*y)-m > 1)
                    bisa=0;
                if ((x*y)-m == 5 || (x*y)-m == 7) bisa=0;

                if (bisa==1){
                    while(m>=3){
                        ar[1][y]=ar[2][y]=ar[3][y]='*';
                        y--;
                        m-=3;
                    }

                    if (m==1){
                        ar[3][y]='*';
                    }
                    if (m==2){
                        ar[3][y]='*';
                        if (y!=1)
                            ar[3][y-1]='*';
                        else ar[2][y]='*';
                    }
                }
            }
            ar[1][1]='c';
        }

        printf("Case #%d:\n",ll);

        if (bisa==0) printf("Impossible\n");
        else{
            for (int i=1;i<=r;i++){
                for (int j=1;j<=c;j++)
                    printf("%c",ar[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
