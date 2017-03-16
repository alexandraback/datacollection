#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
double a[200+10];
double b[200+10];
int main()
{
    freopen("n.txt","w",stdout);
    int t;
    cin>>t;
    int ca=1;
    while(t--)
    {
       int n;
       cin>>n;
       double sum=0;
       double sum2=0;
       for(int i=0;i<n;i++)
       {
         scanf("%lf",a+i);
         b[i]=a[i];
         sum+=a[i];
       }
       sort(b,b+n);
       b[n]=1000000;
       double ans=0;
       //double sum3
       for(int i=0;i<n;i++)
       {
          if((b[i+1]-b[i])*(i+1)+sum2>=sum)
          {
              ans=b[i]+(sum-sum2)/(i+1);
              break;
          }
          else 
              sum2+=(b[i+1]-b[i])*(i+1);
       }
       printf("Case #%d: ",ca++);
       for(int i=0;i<n;i++)
       {
         if(a[i]>=ans)
           printf("0");
         else 
           printf("%.6lf",100*(ans-a[i])/sum);
         if(i<n-1)
          printf(" ");
         else 
           printf("\n");
       }
    }
    return 0;
}

