#include<iostream>
#include<algorithm>
using namespace std;

int n, arr[10], e;
int max_sum =0,sum=0;

void recur(int energy, int r, int d)
{
     if(d<=0)
     {
             if(sum>max_sum)
                            max_sum = sum;
             return;
            // cout<<"ac";
     }
     else
     {
         for(int i=0;i<=energy;i++)
         {
                 sum += i*arr[n-d];
                 recur(min(energy-i+r,e),r,d-1);
                 sum -= i*arr[n-d];
         }
     }
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,x=1;
    scanf("%d",&t);
    
    while(t--)
    {
              max_sum=0; sum=0;
              int r;
              scanf("%d %d %d",&e,&r,&n);
              
              for(int i=0;i<n;i++)
                      scanf("%d",&arr[i]);
                      
              recur(e,r,n);
              printf("Case #%d: %d\n",x++,max_sum);
    }
}                   
