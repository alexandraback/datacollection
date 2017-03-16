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
int64 a[1000000];
void upd(int64 vl,int64 bg, int64 en)
{
int64 i;
for(i=bg;i<=en;i++)a[i]=max(a[i],vl);
}
int at(int64 vl,int64 bg, int64 en)
{
int64 i;
for(i=bg;i<=en;i++)if(a[i]<vl)return 1;
return 0;
}
int main()
{
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
int64 i,j,k,m,n,t,tr[100][8],d[20][20],ca,cnt,ans,cmin,vl;
cin>>t;
for(cnt=1;cnt<=t;cnt++)
{
cin>>n;for(i=0;i<n;i++)for(j=0;j<8;j++)cin>>tr[i][j];ans=0;memset(a,0,sizeof(a));
vector < vector <int64> > v(n,vector<int64>());
for(i=0;i<n;i++){tr[i][2]+=50000;tr[i][3]+=50000;}
for(i=0;i<n;i++)
   {
   ca = tr[i][0];
   for(j=0;j<tr[i][1];j++)
      {v[i].push_back(ca);
      ca = ca + tr[i][5];
      }
   } 
//for(i=0;i<n;i++){for(j=0;j<v[i].size();j++)cout<<v[i][j]<<" ";cout<<endl;}
while(1){
cmin=10000000;
for(i=0;i<n;i++)for(j=0;j<v[i].size();j++)if(v[i][j]<cmin)cmin=v[i][j];
//cout<<"day = "<<cmin<<endl;
if(cmin==10000000)break;
for(i=0;i<n;i++)for(j=0;j<v[i].size();j++)if(v[i][j]==cmin)
   {
   if(at(tr[i][4],tr[i][2],tr[i][3]-1)==1){ans++;}
   }     //attack
for(i=0;i<n;i++)for(j=0;j<v[i].size();j++)if(v[i][j]==cmin)
   {
   if(at(tr[i][4],tr[i][2],tr[i][3]-1)==1)upd(tr[i][4],tr[i][2],tr[i][3]-1);
  // for(k=0;k<=10;k++)cout<<a[k]<<" ";cout<<endl;
   tr[i][2]+=tr[i][6];
   tr[i][3]+=tr[i][6];
   tr[i][4]+=tr[i][7];
   v[i][j]=10000000;
   }      //update
}
printf("Case #%lld: %lld\n",cnt,ans);
}
return 0;
}


