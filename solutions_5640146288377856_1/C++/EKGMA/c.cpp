//In the name of God

#include <iostream>
using namespace std;

int main()
{
  int t;
  cin>>t;
  for(int i=1;i<=t;i++)
    {
      int x,y,w;
      cin>>x>>y>>w;
      int p=y/w;
      int ans=p*x;
      ans--;
      ans+=w;
      if(y%w)
	ans++;
      cout<<"Case #"<<i<<": "<<ans<<endl;
    }
  return 0;
}
