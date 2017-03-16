//gskhirtladze

#include <iostream>
#include <stdio.h>

using namespace std;

int t,t1,now,ans,i,n;
string s;

main()
 {
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
  cin>>t1;
  for (t=1;t<=t1;t++)
   {
    cin>>n>>s;
    now=0; ans=0;
    for (i=0;i<=n;i++)
     {
      if (i > now) { ans+=i-now; now=i; }
      now+=s[i]-'0';
     }
    cout<<"Case #"<<t<<": "<<ans<<endl;
   }
 }
