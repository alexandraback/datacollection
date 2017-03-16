#include<iostream>
#include<vector>
using namespace std;
int n,b[1005];
vector<int> c[1005];
int func(int x)
{
int d=1;
for(int i=0;i<c[x].size();i++)
{
if(b[c[x][i]]==0)
{
b[c[x][i]]=1;
d=max(d,1+func(c[x][i]));
}
}
return d;
}
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int t,tt,i,j,l,a[1005],k,p,z=0,o;

cin>>tt;
for(t=1;t<=tt;t++)
{
o=z=0;
cin>>n;
for(i=1;i<=n;i++) c[i].clear();
for(i=1;i<=n;i++)
{
cin>>a[i];
c[a[i]].push_back(i);
b[i]=0;
}
k=1;
for(i=1;i<=n;i++)
{
if(b[i]==0)
{
j=i;
while(b[j]==0)
{
b[j]=k;
j=a[j];
}
if(k==b[j])
{
p=0;
l=j;
do{
p++;
j=a[j];
}while(j!=l);
z=max(z,p);
}
k++;
}
}
for(i=1;i<=n;i++) b[i]=0;
for(i=1;i<=n;i++)
{
if(a[a[i]]==i && i<a[i])
{
b[i]=b[a[i]]=1;
o+=func(i);
o+=0+func(a[i]);
}
}
cout<<"Case #"<<t<<": "<<max(z,o)<<endl;
}
return 0;
}