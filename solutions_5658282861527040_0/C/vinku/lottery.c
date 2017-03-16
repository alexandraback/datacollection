#include<stdio.h>
int main()
{
    int t,k,i,j,a,b,sol,z;
    scanf("%d",&t);
    z=1;
    while(t--)
    {
         scanf("%d%d%d",&a,&b,&k);
         sol=0;
         for(i=0;i<a;i++)
         {
             for(j=0;j<b;j++)
             {
                  if((i&j)<k)
                  {
                     //printf("%d\t%d\t%d\t\n",i,j,k);
                     sol++;
                  }    
             }        
         }
         printf("Case #%d: %d\n",z,sol);
         z++;
    }
    return(0);
}
