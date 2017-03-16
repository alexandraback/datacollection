#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define ma1 2000000000
long long int v,r;
int eval(long long int k)
{
 long long int dum= (2*k*k) +(( 2*r)-1)*k;
 if(dum>v)
          return 0;
 return 1;
}

long long int binar(long long int low,long long int high)
{
 long long int k= high- (high-low)/2;
 long long int po=pow(10,18);
 if(k<ma1 && k<(3*po)/r)
 {if(eval(k) && !eval(k+1))
            return k;
 
 if(eval(k))
            {
             return  binar(k+1,high);    
            }           
 else
     {
     return binar(low,k-1);
     }
     }
 
 else
     return binar(low,k-1);
     
}

using namespace std;
int main()
{
int t;
scanf("%d",&t);
for(int cas=1;cas<=t;cas++)
        {
        
        scanf("%lld %lld",&r,&v);
long long int high;
       
        
        long long int answer=binar(1,high);
        
        //long long int k;
        
                
        printf("Case #%d: %lld\n",cas,answer);
        
        }
}
