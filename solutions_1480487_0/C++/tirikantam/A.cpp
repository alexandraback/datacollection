#include <iostream>
#include <stdio.h>
using namespace std;
int S;
int A[20];
int N;
bool Q(int ii, double d)
{
    int i;
    double my=A[ii]+d*S;
    double w=1-d;
    for (i=0;i<N;i++) if (i!=ii && A[i]<my) w-=(my-A[i])/S;
    return w<0;
}
void main()
{
    int i,j,k;
    int T;
    bool ch;
    double x,y,z;
    scanf("%d",&T);
    for (k=0;k<T;k++)
    {
        printf("Case #%d: ",k+1);
    scanf("%d",&N);
    S=0;
    double d;
    bool ch;
    for (i=0;i<N;i++) scanf("%d",&A[i]);
    for (i=0;i<N;i++) S+=A[i];
    for (i=0;i<N;i++)
    {
        ch=true;
        for (d=0;d<=1;d+=1e-7)
        {
            if (Q(i,d))
            {
                printf("%10g ",d);
                ch=false;
                break;
            }
        }
        if (ch) printf("%10g ",d);
    }
    printf("\n");
    }
}
