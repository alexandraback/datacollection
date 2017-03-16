#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    //freopen("cpp.in","r",stdin);
    //freopen("cpp.out","w",stdout);
    int t,s,p,n,ans,score,i,times=0;
    cin>>t;
    while(t--)
    {
         times++;
         cin>>n>>s>>p;
         ans=0;
         for(i=0;i<n;i++)
         {
              cin>>score;
              if(score==0)
              {
                   if(p==0)
                      ans++;
              }   
              else if(score>=(3*p-2))
                  ans++;
              else if(score>=(3*p-4))
              {
                  if(s>0)
                  {    
                       ans++;
                       s--;
                  }
              }
         }
         cout<<"Case #"<<times<<": "<<ans<<endl;    
    }
}
