#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int f[55][55];
int main()
{
    int T,i,j,cas=0;
    int r,c,m;
    freopen("C-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&r,&c,&m);
        int n=r*c-m;
        printf("Case #%d:\n",++cas);
        if(r==1)
        {
            printf("c");
            for(i=1;i<n;i++)
            printf(".");
            for(i=0;i<m;i++)
            printf("*");
            puts("");
        }
        else if(c==1)
        {
            printf("c\n");
            for(i=1;i<n;i++)
            printf(".\n");
            for(i=0;i<m;i++)
            printf("*\n");
        }
        else if(n==1)
        {
            printf("c");
            for(i=1;i<c;i++)
            printf("*");
            puts("");
            for(i=1;i<r;i++)
            {
                for(j=0;j<c;j++)
                printf("*");
                puts("");
            }
        }
        else
        {
            memset(f,0,sizeof f);
            int biao=1;
            for(i=2;i<=r;i++)
            {
                if(n/i>1&&n%i!=1&&(n/i<c||n%i==0&&n/i<=c))
                {
                    //printf("123:%d\n",i);
                    biao=0;
                    for(j=0;j<i;j++)
                    for(int k=0;k<n/i;k++)
                    f[j][k]=1;
                    for(j=0;j<n%i;j++)
                    f[j][n/i]=1;
                    break;
                }
            }
            if(biao)
            for(i=2;i<=c;i++)
            {
                if(n/i>1&&n%i!=1&&(n/i<r||n%i==0&&n/i<=r))
                {
                    biao=0;
                    for(j=0;j<i;j++)
                    for(int k=0;k<n/i;k++)
                    f[k][j]=1;
                    for(j=0;j<n%i;j++)
                    f[n/i][j]=1;
                    break;
                }
            }
            if(biao)
            {
                int bia=0;
                int  qwe=sqrt(m);
                if(qwe*qwe==m)
                {
                    if(qwe<r-1&&qwe<c-1)
                    {
                        for(i=0;i<qwe;i++)
                            for(j=0;j<qwe;j++)
                            {
                                f[r-1-i][c-1-j]=1;
                            }
                        bia=1;
                    }
                }
                else  if(qwe*(qwe+1)>=m)
                {
                    if(qwe<r-1&&(qwe+1)<c-1)
                    {
                        for(i=0;i<qwe;i++)
                        for(j=0;j<qwe;j++)
                        f[r-1-i][c-1-j]=1;
                        for(i=0;i<(m-qwe*qwe);i++)
                        f[r-1-i][c-1-qwe]=1;
                        bia=1;
                    }
                    else if((qwe+1)<r-1&&qwe<c-1)
                    {
                        for(i=0;i<qwe;i++)
                        for(j=0;j<qwe;j++)
                        f[r-1-i][c-1-j]=1;
                        for(i=0;i<(m-qwe*qwe);i++)
                        f[r-1-qwe][c-1-i]=1;
                        bia=1;
                    }
                }
                else {
                    if((qwe+1)<r-1&&(qwe+1)<c-1)
                    {
                        int su=m;
                        for(i=0;i<qwe+1;i++){
                            if(su==0) break;
                            for(j=0;j<qwe+1;j++)
                            {
                                f[r-1-i][c-1-j]=1;
                                su--;
                                if(su==0) break;
                            }
                        }
                        bia=1;
                    }
                }
                if(bia)
                {
                    f[0][0]=-1;
                    for(i=0;i<r;i++)
                    {
                        for(j=0;j<c;j++)
                        if(f[i][j]==-1)
                        printf("c");
                        else if(f[i][j]==0)
                        printf(".");
                        else printf("*");
                        puts("");
                    }
                }
                else puts("Impossible");
            }
            else
            {
                f[0][0]=-1;
                for(i=0;i<r;i++)
                {
                    for(j=0;j<c;j++)
                    if(f[i][j]==-1)
                    printf("c");
                    else if(f[i][j]==1)
                    printf(".");
                    else printf("*");
                    puts("");
                }
            }
        }
    }
    return 0;
}
