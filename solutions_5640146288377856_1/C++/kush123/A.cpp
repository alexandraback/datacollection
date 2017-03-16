#include<iostream>
using namespace std;

int main()
 {
 int t;
 cin>>t;
 for(int j=1;j<=t;j++)
  {
  int r,c,w,ans=0;
  cin>>r>>c>>w;
  if(w==1)
   ans=r*c;
  else if(w==c)
    ans=r-1+c;
  else
   {
     if(c%w==0)
      ans=r*(c/w)-1;
     else ans=r*(c/w);
     ans+=w;
   }
   cout<<"Case #"<<j<<": "<<ans<<"\n";
  }
 }
