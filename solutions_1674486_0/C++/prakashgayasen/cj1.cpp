#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;
typedef long long int int64;
int main()
{
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
int64 i,j,k,n,m,t,a[1001][101],cnt=1,ref[1001],d[1001],nn,fl;
cin>>t;
while(t--)
{
scanf("%lld",&n);fl = 0;
vector <int> v;
queue <int> q;
v.clear();
memset(ref,0,sizeof(ref));
for(i=1;i<=n;i++){scanf("%lld",&a[i][0]);for(j=1;j<=a[i][0];j++){scanf("%lld",&a[i][j]);ref[a[i][j]]=1;}}
for(i=1;i<=n;i++){if(ref[i]==0)v.push_back(i);}
for(i=0;i<v.size();i++)
   {
   while(!q.empty())q.pop();
   memset(d,0,sizeof(d));
   q.push(v[i]);
   d[v[i]]=1;
   while(!q.empty())
      {
    //  cout<<n<<" : ";
      n = q.front();q.pop();
      for(j=1;j<=a[n][0];j++)
         {
         nn = a[n][j];//cout<<nn<<" ";
         if(d[nn]==1){fl=1;break;}
         else {d[nn] = 1;q.push(nn);}
         }
     // cout<<endl;
      if(fl==1)break;
      }
   if(fl==1)break;
   }
if(fl==1)printf("Case #%lld: Yes\n",cnt);
else printf("Case #%lld: No\n",cnt);
cnt++;
}
return 0;
}

