//gskhirtladze
#include <bits/stdc++.h>

using namespace std;

string ans;
int t,t1,x,r,c;

main()
{
  freopen("4.in","r",stdin);
  freopen("4.out","w",stdout);
  cin>>t1;
  for (t=1;t<=t1;t++)
   {
    cin>>x>>r>>c;
    ans="GABRIEL";
    if (r > c) swap(r,c);
    if (x >= 7 || (r*c)%x != 0) { ans="RICHARD"; goto pr; }
    if (x <= 2) goto pr;
    if (r <= x/2) ans="RICHARD";
    pr : { cout<<"Case #"<<t<<": "<<ans<<endl; }
   }
}
