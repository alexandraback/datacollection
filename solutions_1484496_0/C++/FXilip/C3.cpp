#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int znamienko[501];
void znamienka_plus(int k)
{

if (znamienko[k]==0)
   znamienko[k]=1;
else if (znamienko[k]==1)
   znamienko[k]=-1;
else
   {
   znamienko[k]=0;
   if (k<n+1) znamienka_plus(k+1);
   }
}


int main()
{
int t;
FILE *in = fopen("C.in","r");
FILE *out = fopen("C.out","w");
fscanf(in,"%d",&t);

for (int ca=0;ca<t;ca++)
    {
         cout<<ca<<endl<<endl;
  
    fprintf(out,"Case #%d:\n",ca+1);
    fscanf(in,"%d",&n);

    int a[n];
    long long sum;
    for (int i=0;i<n;i++)
        {
        fscanf(in,"%d",&a[i]);
        sum+=a[i];
        }

    sort(&a[0], &a[n]);

    

    sum=47;    
    for (int i=0;i<n+1;i++)
            znamienko[i]=0;
    znamienko[0]=1;
    while((sum!=0)&&(znamienko[n]==0))
        {
        znamienka_plus(0);
        sum=0;
        for (int i=0;i<n;i++)
               sum+=znamienko[i]*a[i];

        }


          if (znamienko[n]!=0)fprintf(out,"Impossible\n");
          else
              { 
                for (int i=0;i<n;i++)
                    if (znamienko[i]==1) 
                    fprintf(out," %d",a[i]);
                    
                    fprintf(out,"\n");
                for (int i=0;i<n;i++)
                    if (znamienko[i]==-1) 
                    fprintf(out," %d",a[i]);
                    
                    fprintf(out,"\n");
                }
    }

fclose(out);
             
return 0;
}
