#include <bits/stdc++.h>

using namespace std;

map < string , bool > f1,f2;
bool f;
int ans,i,j,tt,t,n;
string s1[17],s2[17];

int main()
 {
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  cin>>t;
  for (tt=1;tt<=t;tt++)
   {
    cin>>n;
    for (i=0;i<n;i++)
     cin>>s1[i]>>s2[i];
    ans=0;
    for (j=0;j<(1<<n);j++)
     {
      f1.clear(); f2.clear(); f=1;
      for (i=0;i<n;i++)
       if (!((1<<i)&j)) f1[s1[i]]=f2[s2[i]]=1;
      for (i=0;i<n;i++)
       if ((1<<i)&j)
        if (!f1[s1[i]] || !f2[s2[i]]) f=0;
      if (f) ans=max(ans,__builtin_popcount(j));
     }
    cout<<"Case #"<<tt<<": "<<ans<<endl;
   }
 }
