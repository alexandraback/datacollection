#include <iostream>
#include <stdio.h>
using namespace std;
int B[2000010];
void main()
{
    int i,j,k;
    int T,N;
    int S;
    int A[25];
    bool ch;
    double x,y,z;
    scanf("%d",&T);
    for (k=0;k<T;k++)
    {
        printf("Case #%d:\n",k+1);
    scanf("%d",&N);
    for (i=0;i<N;i++) scanf("%d",&A[i]);
    for (i=0;i<2000010;i++) B[i]=-1;
    ch=false;
    //printf("%d\n",A[0]);
    for (i=1;i<(1<<N);i++)
    {
        S=0;
        for (j=0;j<20;j++)
        {
            if ((i>>j)&1) S+=A[j];
        }
        if (B[S]==-1) B[S]=i;
        else
        {
            ch=true;
            for (j=0;j<20;j++) if ((B[S]>>j)&1) printf("%d ",A[j]);
            printf("\n");
            for (j=0;j<20;j++) if ((i>>j)&1) printf("%d ",A[j]);
            printf("\n");
            break;
        }
    }
    if (!ch) printf("Impossible\n");
    }
}
