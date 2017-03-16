#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<time.h>

using namespace std;

int a[201][201],c[201],b[201],ans,i,j,n,m,t,tT;

main()
 {
  freopen("input.in","r",stdin);
  freopen("output.out","w",stdout);
  cin>>tT;
  for (t=1;t<=tT;t++)
   {
    cin>>n>>m;
    for (i=1;i<=n;i++)
     for (j=1;j<=m;j++)
      cin>>a[i][j];
    for (i=1;i<=n;i++) b[i]=-1;
    for (j=1;j<=m;j++) c[j]=-1;
    for (i=1;i<=n;i++)
     for (j=1;j<=m;j++)
      b[i]=max(b[i],a[i][j]),
      c[j]=max(c[j],a[i][j]);
    ans=true;
    for (i=1;i<=n;i++)
     for (j=1;j<=m;j++)
      if (a[i][j] < b[i] && a[i][j] < c[j]) ans=false;
    cout<<"Case #"<<t<<": ";
    if (ans) cout<<"YES"<<endl; else 
             cout<<"NO"<<endl;
   }
 }
