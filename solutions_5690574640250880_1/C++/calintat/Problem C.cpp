#include <cstdio>
#include <cmath>
using namespace std;
void zero(int,int);
void afisare(int,int);
int k,T,R,C,M,N,A[51][51],i,j,dx,dy,dn,num,ok,mx,my,end;
int main()
{
    freopen("Problem C.in","r",stdin);
    freopen("Problem C.out","w",stdout);
    scanf("%d",&T);
    for(k=1;k<=T;k++)
    {
        scanf("%d %d %d",&R,&C,&M);
        end=1;
        for(mx=1;mx<=1 && end;mx++)
        {
            for(my=1;my<=1 && end;my++)
            {
                zero(R,C);
                N=1;
                A[mx][my]=1;
                ok=1;
                while(N+M<R*C && ok)
                {
                    dn=0;
                    for(i=1;i<=R;i++)
                    {
                        for(j=1;j<=C;j++)
                        {
                            if(A[i][j]==1)
                            {
                                num=0;
                                if(A[i-1][j]==0 && i>=2)
                                num++;
                                if(A[i+1][j]==0 && i<=R-1)
                                num++;
                                if(A[i][j-1]==0 && j>=2)
                                num++;
                                if(A[i][j+1]==0 && j<=C-1)
                                num++;
                                if(A[i-1][j-1]==0 && j>=2 && i>=2)
                                num++;
                                if(A[i+1][j-1]==0 && j>=2 && i<=R-1)
                                num++;
                                if(A[i-1][j+1]==0 && j<=C-1 && i>=2)
                                num++;
                                if(A[i+1][j+1]==0 && j<=C-1 && i<=R-1)
                                num++;
                                if(num>=1)
                                {
                                    if(dn)
                                    {
                                        if(num<dn && num!=1)
                                        {
                                            dx=i;
                                            dy=j;
                                            dn=num;
                                        }
                                    }
                                    else
                                    {
                                        dx=i;
                                        dy=j;
                                        dn=num;
                                    }

                                }
                                if(num==0)
                                A[i][j]=2;
                            }
                        }
                    }
                    if(dn<=R*C-N-M)
                    {
                        N+=dn;
                        i=dx;
                        j=dy;
                        A[i][j]=2;
                        if(A[i-1][j]==0 && i>=2)
                        A[i-1][j]=1;
                        if(A[i+1][j]==0 && i<=R-1)
                        A[i+1][j]=1;
                        if(A[i][j-1]==0 && j>=2)
                        A[i][j-1]=1;
                        if(A[i][j+1]==0 && j<=C-1)
                        A[i][j+1]=1;
                        if(A[i-1][j-1]==0 && j>=2 && i>=2)
                        A[i-1][j-1]=1;
                        if(A[i+1][j-1]==0 && j>=2 && i<=R-1)
                        A[i+1][j-1]=1;
                        if(A[i-1][j+1]==0 && j<=C-1 && i>=2)
                        A[i-1][j+1]=1;
                        if(A[i+1][j+1]==0 && j<=C-1 && i<=R-1)
                        A[i+1][j+1]=1;
                    }
                    else
                    ok=0;
                }
                if(ok)
                {
                    printf("Case #%d:\n",k);
                    for(i=1;i<=R;i++)
                    {
                        for(j=1;j<=C;j++)
                        {
                            if(i==mx && j==my)
                            printf("c");
                            else if(A[i][j]==0)
                            printf("*");
                            else
                            printf(".");
                        }
                        printf("\n");
                    }
                    end=0;
                }
            }
        }
        if(end)
        printf("Case #%d:\nImpossible\n",k);
    }
    return 0;
}
void afisare(int S1,int S2)
{
    int s1,s2;
    for(s1=1;s1<=S1;s1++)
    {
        for(s2=1;s2<=S2;s2++)
        printf("%d ",A[s1][s2]);
        printf("\n");
    }
    printf("\n");
}

void zero(int S1,int S2)
{
    int s1,s2;
    for(s1=1;s1<=S1;s1++)
    {
        for(s2=1;s2<=S2;s2++)
        A[s1][s2]=0;
    }
}
