#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int t,tt,n,i,j,x;
map<int,int> a;
vector<int> v;
cin>>tt;
for(t=1;t<=tt;t++)
{
cin>>n;
v.clear();
a.clear();
for(i=1;i<=2*n-1;i++)
{
for(j=1;j<=n;j++)
{
cin>>x;
v.push_back(x);
a[x]++;
}
}
sort(v.begin(),v.end());
cout<<"Case #"<<t<<": ";
for(i=0;i<v.size();i++)
{	
if(a[v[i]]%2) cout<<v[i]<<" ",a[v[i]]=0;
}
cout<<endl;
}
return 0;
}