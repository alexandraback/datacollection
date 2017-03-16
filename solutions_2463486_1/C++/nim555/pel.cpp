#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool pel(long long int a)
{
long long int dummy=a;
long long int rev=0;
while(dummy)
            {
             int ad=dummy%10;
             dummy=dummy/10;
             rev=rev*10+ad;
             
            }
if(rev==a)
return 1;
return 0;

}
vector<int> sie;
int main()
{sie.push_back(0);
for(long long int i=1;i<=10000010;i++)
        {long long int mul=i*i;
        int pus=sie[i-1];
         if(pel(i) && pel(mul))
                   {
                   pus++;
                   }
                    sie.push_back(pus);
                   
        }
int t;
//cout<<sie[8];
//cout<<sie[10000000];
scanf("%d",&t);
int count=0;

while(t--)
          {count++;
          
           long long int low,high;
           scanf("%lld %lld",&low,&high);
           //cin>>t;
          if(low>high)
                      {
                       long long int temp=low;
                       low=high;
                       high=temp;
                      }
                      
                      
                          //cout<<sie[high];
                          
                            int h=sqrt(high);
                            int l=sqrt(low-1); 
                           // cout<<h<<l;               
          long long int answer=sie[h]-sie[l];
          printf("Case #%d: %lld\n",count,answer);
          }

}
