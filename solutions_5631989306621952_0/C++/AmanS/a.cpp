#include<iostream>
using namespace std;
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int t,i,j,l,r;
string s;
char a[2005];
cin>>t;
for(i=1;i<=t;i++)
{
cin>>s;
l=r=1000;
a[l]=s[0];
for(j=1;j<s.length();j++)
{
if(s[j]>=a[l]) a[l-1]=s[j],l--;
else a[r+1]=s[j],r++;
}
cout<<"Case #"<<i<<": ";
for(j=l;j<=r;j++) cout<<a[j];
cout<<endl;
}
return 0;
}