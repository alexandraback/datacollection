#include<iostream>
#include<cstdio>

#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ld long double
using namespace std;
 
int e,r,n,max1;
int v[100];
int dp[11][11];
 
void doit(int pos,int en,int gain)
{
       if(pos==n)
       {
              max1=max(max1,gain);
              return ;          
       }
       for(int i=0;i<=en;i++)
       {
              if((en-i+r)<=e)
              doit(pos+1,(en-i)+r,gain+v[pos]*i);        
              else
              doit(pos+1,e,gain+v[pos]*i);
       }       
       return ;
}

int main()
{
       int t,p;
       scanf("%d",&t);
       for(p=1;p<=t;p++)
       {   
          cin>>e>>r>>n;
          for(int i=0;i<n;i++)
              cin>>v[i];
          max1=0;   
          doit(0,e,0);    
          cout<<"Case #"<<p<<": "<<max1<<"\n";
        }
        return 0;    
}