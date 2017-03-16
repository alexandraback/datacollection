#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<iostream>
#include<stack>

using namespace std;

int main()
{
    
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   
   long long int r,t;
   int test,j;
   scanf("%d",&test);
   for(j=1;j<=test;j++)
   {
   scanf("%lld%lld",&r,&t);
   
   int i,temp=2*r+1;
   for(i=0;;)
   {
                if(temp<=t) {t=t-temp;i++;temp+=4;}
                else break;
   }
   
   printf("Case #%d: %d\n",j,i);
   } 
   
   
   return 0;
}
