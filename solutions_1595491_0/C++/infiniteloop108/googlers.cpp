#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{

ifstream fin("s.in");
ofstream fout("s.out");
int t;
fin>>t;
for(int i=1;i<=t;++i)
{
int n,su,p;
fin>>n>>su>>p;
int ans=0;
int used=0;
for(int x=0;x<n;++x)
{

int ns,s;
int a;
fin>>a;
if(a==0)
{
ns=0;
s=0;
}else if(a%3==0)
{ns=a/3;
s=ns+1;}
else if(a%3==1)
{ns=((a/3)+1);
s=((a/3)+1);
}
else if(a%3==2)
{ns=((a/3)+1);
s=((a/3)+2);
}


if(ns>=p)ans++;
else
{
if(s>=p)
{
if(used<su)
{
ans++;
used++;
}
}
}
}

fout<<"Case #"<<i<<": "<<ans<<endl;
}
return 0;
}
