#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<iterator>
#include<set>
#include<cstdlib>
#include<cassert>
#define gc getchar_unlocked
using namespace std;
typedef long long int int64;
int64 md=1000000007;
void scanint(int64 &x)
{
    register int64 c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int64 ne(int64 n, int64 a)
{
int64 ans;
if(a==0)return 1;
if(a%2==0){ans = ne(n,a/2);return (ans*ans)%md;}
else {ans = ne(n,a-1);return (ans*n)%md;}
}
int chk(char c)
{
if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')return 0;
else return 1;
}
char a[1000007];int ep[1000007],nep[1000007];
int main()
{
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
int64 i,j,k,m,n,t,cnt=1,ans,cn,cnep=-1,len;
cin>>t;
for(cnt=1;cnt<=t;cnt++)
{
memset(ep,0,sizeof(ep));memset(nep,-1,sizeof(nep));
scanf("%s %lld",a,&n);cn=0;cnep=-1;ans=0;
len = strlen(a);
for(i=0;i<len;i++)
  {
  if(chk(a[i])){cn++;if(cn>=n)ep[i]=1;}
  else {cn=0;ep[i]=0;}
  }
for(i=len-n;i>=0;i--)
  {
  if(ep[i+n-1]==1){nep[i]=i+n-1;cnep=i+n-1;}
  else nep[i]=cnep;
  }
//for(i=0;i<len;i++)cout<<ep[i]<<" ";cout<<endl;
//for(i=0;i<len;i++)cout<<nep[i]<<" ";cout<<endl;
for(i=0;i<=len-n;i++)
if(nep[i]!=-1){ans+=len-nep[i];}
printf("Case #%lld: %lld\n",cnt,ans);
}
return 0;
}


