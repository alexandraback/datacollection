#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char *argv[])
{
  int T;
  cin>>T;
  for(int tm=1;tm<=T;tm++){
    int n,s,p;
    cin>>n>>s>>p;
    int z,t,res=0;
    int a=0;
    for(int i =0;i<n;i++){
      cin>>t;
      z=t/3;
      if(t%3!=0)z++;
      if(z>=p)res++;
      else if(t && t%3!=1 && z+1>=p)
        a++;
    }
    res+=min(a,s);
    cout<<"Case #"<<tm<<": "<<res<<endl;
  }
  return 0;
}
