#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 60;

int MM,R,C,_;
char s[MAXN][MAXN] ;

void out()
{
    for (int i=1; i<=R; i++)
    {
        for (int j=1; j<=C; j++)
            printf("%c",s[i][j]);
        printf("\n");
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&_);
    int cas=0;
    while (_--)
    {
        scanf("%d%d",&R,&C);
        int MM;
        scanf("%d",&MM);
        MM=R*C-MM;
        printf("Case #%d:\n",++cas);
        //printf("%d %d %d\n",R,C,MM);
        if (MM==1){

            for (int i=1; i<=R; i++)
                {
                    for (int j=1; j<=C; j++)
                        if (i==1&&j==1) printf("c");
                        else printf("*");
                    printf("\n");
                }
            continue ;
        }
        if (R<=2||C<=2)
        {
            if (R==1)
            {
                for (int i=1; i<=MM; i++)
                    printf("%c",(i==1)?'c':'.');
                for (int i=MM+1; i<=C; i++)
                    printf("*");
                printf("\n");
                continue ;
            }
            if (C==1)
            {
                for (int i=1; i<=MM; i++)
                    printf("%c\n",(i==1)?'c':'.');
                for (int i=MM+1; i<=R; i++)
                    printf("*\n");
                continue ;
            }
            if (MM==3||MM==2||(MM%2==1))
            {
                printf("Impossible\n");
                continue ;
            }
            if (R==2)
            {
                for (int i=1; i<=R; i++)
                    for (int j=1; j<=C; j++)
                        s[i][j]='*';
                for (int i=1; i<=(MM+1)/2; i++) s[1][i]='.';
                for (int i=1; i<=MM/2; i++) s[2][i]='.';
                s[1][1]='c';
                out();
                continue;
            }
            for (int i=1; i<=R; i++)
                for (int j=1; j<=C; j++)
                    s[i][j]='*';
            for (int i=1; i<=(MM+1)/2; i++) s[i][1]='.';
            for (int i=1; i<=MM/2; i++) s[i][2]='.';
            s[1][1]='c';
            out();
            continue;
        }
        else
        {
            if (MM==2||MM==3||MM==5||MM==7)
            {
                printf("Impossible\n");
            }
            else if (MM==1)
            {

                for (int i=1; i<=R; i++)
                {
                    for (int j=1; j<=C; j++)
                        if (i==1&&j==1) printf("c");
                        else printf("*");
                    printf("\n");
                }
            }
            else if (R==C && (R-1)*(R-1)+R==MM)
            {
                for (int i=1; i<=R; i++)
                {
                    if (i==1)
                    {
                        for (int j=1; j<=R-2; j++)
                            if (j==1) printf("c");
                            else printf(".");
                        for (int j=1; j<=2; j++)
                            printf("*");
                        printf("\n");
                    }
                    else if (i==R||i==R-1)
                    {
                        for (int j=1; j<=R; j++)
                            printf(".");
                        printf("\n");
                    }
                    else
                    {
                        for (int j=1; j<=R-1; j++)
                            printf(".");
                        printf("*\n");
                    }
                }
            }
            else
            {

                bool flag = false;
                for (int N=2; N<=R; N++)
                {
                    if (flag) continue ;
                    for (int M=2; M<=C-1; M++)
                    {

                        if (flag) continue ;
                        for (int k=0; k<=N; k++)
                            if (k!=1 && N*M+k==MM)
                            {
                                flag=true;
                                for (int i=1; i<=R; i++)
                                    for (int j=1; j<=C; j++)
                                        s[i][j]='*';
                                for (int i=1; i<=N; i++)
                                    for (int j=1; j<=M; j++)
                                        s[i][j]='.';
                                for (int j=1; j<=k; j++)
                                    s[j][M+1]='.';
                                s[1][1]='c';
                                out();
                            }
                    }
                }
                for (int M=2; M<=C; M++)
                {
                    if (flag) continue ;
                    for (int N=2; N<=R-1; N++)
                    {

                        if (flag) continue ;
                        for (int k=0; k<=M; k++)
                            if (k!=1 && N*M+k==MM)
                            {
                                flag = true ;
                                for (int i=1; i<=R; i++)
                                    for (int j=1; j<=C; j++)
                                        s[i][j]='*';
                                for (int i=1; i<=N; i++)
                                    for (int j=1; j<=M; j++)
                                        s[i][j]='.';
                                for (int j=1; j<=k; j++)
                                    s[N+1][j]='.';
                                s[1][1]='c';
                                out();
                            }
                    }
                }
            }
        }
    }
    return 0 ;
}
