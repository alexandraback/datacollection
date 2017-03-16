#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int m[10000001];
string s;
int main()
{
//cout<<"1"<<endl;
int t,b;
freopen("C:\\Users\\Gaurav\\Desktop\\A-large (1).in","r",stdin);
freopen("C:\\Users\\Gaurav\\Desktop\\output.txt","w",stdout);
cin>>b;
//scanf("%d",&b);
//cout<<" X won"<<endl;
//int k=0;
int i1=0;
while(b--)
{
i1++;
cin>>s;
int n;
cin>>n;
memset(m,0,sizeof(m));
int i;
for(i=0;i<s.length();i++)
{
if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
m[i]=0;
else
{
if(i==0)
m[i]=1;
else
m[i]=m[i-1]+1;
}
}
long long int ans=0;int last=0;
for(i=0;i<s.length();i++)
{
if(m[i]>=n)
{
ans+=((s.length()-i)*(i-n-last+2));
last=i-n+2;
//last=i-m[i]+2;
//cout<<ans<<endl;
//ans+=;
}
//else
//if(m[i]>n)
{

}
}
cout<<"Case #"<<i1<<": "<<ans<<endl;
}
return 0;
}
