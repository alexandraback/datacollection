#include<iostream>
#include<vector>
using namespace std;
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
vector<int> v;
int t,T,k,n,i,j;
string s;
long long p;
cin>>T;
for(t=1;t<=T;t++)
{
cin>>s>>k;
n=s.length();
j=0;
v.clear();
v.push_back(-1);
for(i=0;i<n;i++)
{
if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') j=0;
else if(j==k-1) v.push_back(i-j);
else j++;
}
p=0;
for(i=1;i<v.size();i++)
{
p+=(long long)(v[i]-v[i-1])*(n-v[i]-k+1);
}
cout<<"Case #"<<t<<": "<<p<<endl;
}
return 0;
}