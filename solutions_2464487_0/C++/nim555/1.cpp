#include<stdio.h>
#include<iostream>
#include<vector>
#define ma 1000000000000000000
long long int v,r;
bool eval(long long int k)
{
 long long int dum= (2*k*k) +(( 2*r)-1)*k;
 if(dum>v)
          return 0;
 return 1;
}
using namespace std;
int main()
{
int t;
scanf("%d",&t);
for(int cas=1;cas<=t;cas++)
        {
        
        scanf("%lld %lld",&r,&v);
        
        //long long int k=ma/(r*10);
        long long int k;
        for(k=1; ;k++)
                {
                 if(!eval(k))
                            {
                             break;
                            }
                }
                
        printf("Case #%d: %lld\n",cas,k-1);
        
        }
}
