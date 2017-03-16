
#include<stdio.h>

int main()
{
int t,T,i,j,k,sum,n,a[201],nsum;
double s,avg;
scanf("%d",&T);
for(t=1;t<=T;t++)
    {
    scanf("%d",&n);
    sum=0;
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        sum=sum+a[i];
        }
    
    avg= 2.0*sum/n;
    nsum=0;
    k=0;
    for(i=0;i<n;i++)
        {
        if(a[i]<=avg)
            {nsum= nsum+a[i]; k++;}
            }
    printf("Case #%d:",t);    
    for(i=0;i<n;i++)
        {
        if(sum)
        {
        if(a[i]<=avg)
        s=100.0/k+100.0*nsum/(k*sum)-a[i]*100.0/sum;
        else s=0;
        //s= a[i]*1.0/sum;
        }
        else s=0;
        printf(" %.6f", s);    
        }
        printf("\n");
    }
    
return 0;    
}
