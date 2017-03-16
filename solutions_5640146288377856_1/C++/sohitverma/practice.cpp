#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int t;
  cin>>t;
  for(int i = 1; i <= t; i++)
  {
    int r,c,w;
    cin>>r>>c>>w;
    long long int ans = 0;
    ans = r*(c/w);
    ans += w - 1;
    if(c % w != 0)
      ans++;
    cout<<"Case #"<<i<<": "<<ans<<endl;
  }
  return 0;
}   