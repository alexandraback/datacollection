#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
int t,n;
FILE *in = fopen("A.in","r");
FILE *out = fopen("A.out","w");
fscanf(in,"%d",&t);

for (int ca=0;ca<t;ca++)
    {
         cout<<ca<<endl;
    fprintf(out,"Case #%d:",ca+1);
    fscanf(in,"%d",&n);
    int a[n],b[n];
    int sum=0;
    for (int i=0;i<n;i++)
        {
        fscanf(in,"%d",&a[i]);
        b[i]=a[i];
        sum+=a[i];
        }

    sort(&a[0], &a[n]);
                
    for (int i=0;i<n;i++)
    {
        double este=sum;
        int lo=0;
        while ((a[lo]<b[i])&&(lo<n))
              {
              este-=b[i]-a[lo];
              lo++;
              }

        double hlasov=0;
        while ((este>0)&&(lo<n))
              {
              int delta=a[lo]-(b[i]+hlasov);
              if (delta*lo<=este)
                 {
                 este-=delta*lo;
                 hlasov+=delta;
                 lo++;
                 }
              else 
                   {
                   hlasov+=este/lo;
                   este=0;
                   }
              }
              
        if (este>0)
           hlasov+=este/n;
    
        fprintf(out," %f",100*hlasov/sum);
    }
    
    fprintf(out,"\n");
    }
    
fclose(out);
             
return 0;
}
