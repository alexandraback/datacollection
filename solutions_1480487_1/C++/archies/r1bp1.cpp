#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#define SSD(x) (scanf("%d",&x))
#define SSL(x) (scanf("%lld",&x))
#define SSF(x) (scanf("%f",&x))
#define SSS(x) (scanf("%s",x))
#define ABS(x) (x>0?x:-x)
using namespace std;
#define MOD 1000000007
int main()
{
     int t,i,j,n;
     freopen("in.in","r",stdin);
     freopen("output.txt","w+",stdout);
     scanf("%d",&t);
     int a[10000];
     float ans;
     for(int t1=1;t1<=t;t1++)
     {     
         SSD(n);
         int sum=0;
         for(i=0;i<n;i++)
         {
             SSD(a[i]);
             sum+=a[i];
         }
         ans=2.0*sum/n;
         int count=n;
         int m=0;
         int sum1=sum;
         while(m!=count)
         {
             m=count;
             count=0;
             sum=0;
             for(i=0;i<n;i++)
             {
                 
                 if((ans-a[i])<0 || a[i]==-1) a[i]=-1;
                 else {sum+=a[i];count++;}
             }
             //cout<<sum<<'*';
             ans=1.0*(sum1+sum)/count;
         }    
         printf("Case #%d: ",t1);   
         if(sum!=0) 
         {
              for(i=0;i<n;i++)
              {
                 float temp=100.0*(ans-a[i])/sum1;
                 if(a[i]!=-1 ) printf("%f ",temp);
                 else printf("0.000000 ");
              }
              cout<<endl;
              
         }
         else
         {
               for(i=0;i<n;i++)
              {
                 float temp=100.0/count;
                 if(a[i]!=-1 ) printf("%f ",temp);
                 else printf("0.000000 ");
              }  
          cout<<endl;    
         }    
                      
          
     }
     return 0;
}

