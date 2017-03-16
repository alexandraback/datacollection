#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
typedef long long int int64;
int64 e,r,n,a[100],ans=-1,tb[15][15][15];
void fn(int ce,int st,int vl)
{
int i,j;
if(st==n){if(vl>ans)ans=vl;return;}
for(i=0;i<=ce;i++)
   {
   j = ce-i+r;
   if(j>e)j=e;
  //  cout<<ce<<" "<<st<<" "<<vl<<" calling "<<j<<" "<<st+1<<" "<<vl+(i*a[i])<<endl;
   fn(j,st+1,vl+(i*a[st]));
   }
}
int main()
{
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
int64 i,j,k,m,t,cnt=1;
cin>>t;
while(t--)
{
cin>>e>>r>>n;
for(i=0;i<n;i++)cin>>a[i]; 
ans=-1;
fn(e,0,0);
printf("Case #%lld: %lld\n",cnt,ans);
cnt++;
}
return 0;
}
