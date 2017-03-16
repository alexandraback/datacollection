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
    ans=c;
  else
   {
     if(c%w==0)
      ans=c/w-1;
     else ans=c/w;
     ans+=w;
   }
   cout<<"Case #"<<j<<": "<<ans<<"\n";
  }
 }
