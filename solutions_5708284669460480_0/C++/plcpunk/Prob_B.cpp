#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#define int long long
using namespace std;
main()
{
ifstream in("B-small-attempt2.in");
ofstream out("B-small-attempt2.out");
int t;
in>>t;
for(int y=1;y<=t;y++)
{
int dp[8]={0};
long double res=0.0;bool flag=true;
int k,l,s;
in>>k>>l>>s;
string keyboard,target;
int vis[26]={0};int vis2[26]={0};
in>>keyboard>>target;
for(int i=0;i<k;i++)
vis[keyboard[i]-'A']++;
for(int i=0;i<l;i++)
vis2[target[i]-'A']++;
for(int i=0;i<26;i++)
{
if(vis[i]<vis2[i])
flag=false;
}
if(flag)
{
int p=1;
for(int i=0;i<s;i++)
p=p*k;
int ma=0;
for(int i=0;i<p;i++)
{
int g=i,f=0;string temp="";
while(f!=s)
{
temp+=keyboard[g%k];
g=g/k;
f++;
}
int c=0;
for(int j=0;j<=s-l;j++)
{
bool flag=true;
for(int m=j;m<j+l;m++)
{
if(target[m-j]!=temp[m])
{flag=false;break;}
}
if(flag)
c++;
}
ma=max(ma,c);
dp[c]++;
}
int temp=0;
for(int i=0;i<ma;i++)
temp=temp+((ma-i)*dp[i]);
res=(long double)temp/(long double)p;
}
out<<"Case #"<<y<<": ";
out<<fixed<<setprecision(7);
out<<res<<"\n";
}
}
