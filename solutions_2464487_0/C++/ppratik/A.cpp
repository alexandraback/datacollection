#include<iostream>
using namespace std;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);
       int arr[2000];
       for(int i=1;i<=1000;i++)
               arr[i] = ((i+1)*(i+1)) - (i*i);
               
       int t,x=1;
       scanf("%d",&t);
       
       while(t--)
       {
                 int r, t;
                 scanf("%d %d",&r,&t);
                 
                 int sum=0,count=0;
                 
                 for(int i=r;sum<=t;i+=2)
                 {
                         sum += arr[i];
                         if(sum<=t)
                                   count++;
                 }
                 
                 printf("Case #%d: %d\n",x++,count);
       }
                                  
}
