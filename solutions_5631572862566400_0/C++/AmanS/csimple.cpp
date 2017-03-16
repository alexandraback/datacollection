#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int t,tt,n,i,a[1005],b[1005],k,l[1005],r[1005];
cin>>tt;
for(t=1;t<=tt;t++)
{
cin>>n;
k=1;
for(i=1;i<=n;i++) cin>>a[i],b[i]=i;
do{
for(i=1;i<=n;i++)
{
l[i]=r[i]=0;
if(i>1 && a[b[i]]==b[i-1]) l[i]=1;
if(i<n && a[b[i]]==b[i+1]) r[i]=1;
}
for(i=2;i<=n;i++)
{
if(i>2 && l[i-1]==0 && r[i-1]==0) break;
if((a[b[1]]==b[2] || a[b[1]]==b[i]) && (a[b[i]]==b[1] || a[b[i]]==b[i-1])) k=max(k,i);
}
}while(next_permutation(b+1,b+n+1));
cout<<"Case #"<<t<<": "<<k<<endl;
}
return 0;
}