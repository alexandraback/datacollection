//A Moolla (6 May 2012)

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

//T is the number of trials
//N is the

int t,n,m;
long long box[101][2];
long long toy[101][2];

long long F(int b, int t)
{
     //cout<<b<<" "<<t;
     long long sum = 0;
   
     if (box[b][1]==toy[t][1])
     {
      if (box[b][0]<toy[t][0]) 
      {
        
         sum+=box[b][0];
                
         if (b==n)
            return sum;
            
         toy[t][0]-=box[b][0];
         sum += F(b+1,t);
         toy[t][0]+=box[b][0];
         return sum;
                   
      }    
      else
      {
          
          sum+=toy[t][0];
                
         if (t==m)
            return sum;
            
         box[b][0]-=toy[t][0];
         sum += F(b,t+1);
         box[b][0]+=toy[t][0];
         return sum;
      }
     } 
     
     long long max = 0; long long max2 = 0;
     if (b!=n)
        max = F(b+1,t);
     if (t!=m)
        max2 = F(b,t+1);
     if (max2>max)   
        max = max2;
        
     return max;
}

int main ()
{
    freopen("C-small.in","r",stdin);   
    freopen("C-small.out","w",stdout);
    
    cin>>t;
    for (int trial=1;trial<=t;trial++)
    {
     cout<<"Case #"<<trial<<": ";
                 
     cin>>n>>m;
     
     for (int i=1;i<=n;++i)
     {
         cin>>box[i][0]>>box[i][1];    
     }
     for (int i=1;i<=m;++i)
     {
        cin>>toy[i][0]>>toy[i][1];    
     }
                 
     cout<<F(1,1)<<"\n";
    }
    return 0;    
}
