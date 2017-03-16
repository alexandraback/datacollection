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
int a[1000][1000];char b[1000][1000];
int xb[1000][1000],yb[1000][1000];
char mp(int i)
{
char ch;
if(i==0)ch='W';
else if(i==1)ch='E';
else if(i==2)ch='S';
else if(i==3)ch='N';
return ch;
}
int main()
{
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
int64 i,j,k,m,n,t,x,y,u,v,nx,ny,ary[4][2]={{-1,0},{1,0},{0,-1},{0,1}},cnt;
memset(a,0,sizeof(a[0][0])*1000*1000);
queue < pair<int64,int64> > q;
a[500][500]=1;q.push(make_pair(500,500));b[0][0]='C';
while(!q.empty())
   {
   u = q.front().first;v = q.front().second;q.pop();
   for(i=0;i<4;i++)
   	   {
   	   nx = u+(ary[i][0]*a[u][v]) ; ny = v+(ary[i][1]*a[u][v]);
   	   if(nx>=0&&nx<1000&&ny>=0&&ny<1000)
   	       {
   	       if(a[nx][ny]==0)
   	          {
   	          a[nx][ny]=a[u][v]+1;b[nx][ny]=mp(i);xb[nx][ny]=u;yb[nx][ny]=v;
   	          q.push(make_pair(nx,ny));
   	          }
   	       }
   	   }
   }
//for(i=1400;i<=1600;i++)for(j=1400;j<=1600;j++)if(a[i][j]==0)cout<<i<<" "<<j<<endl;
cin>>t;
for(cnt=1;cnt<=t;cnt++)
{
string ans="";
cin>>x>>y;
x+=500;y+=500;
//for(j=300;j<=305;j++){for(i=300;i<=305;i++)cout<<(char)b[i][j]<<" ";cout<<endl;}
//for(j=300;j<=305;j++){for(i=300;i<=305;i++)cout<<a[i][j]<<" ";cout<<endl;}
//
while(!(x==500&&y==500))
  {
  ans=ans+b[x][y];u=x;v=y;
  x=xb[u][v];y=yb[u][v];
  }
reverse(ans.begin(),ans.end());
printf("Case #%lld: ",cnt);cout<<ans<<endl;
}
return 0;
}


