#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>
#include <bitset>
#include <string>
#include <vector>
#include <sstream>
#define zero(a) (abs(a)<eps)
#define lowbit(a) ((a)&(-(a)))
#define abs(a) ((a)>0?(a):(-(a)))
#define dj(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define cj(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define dis(x1,y1,x2,y2) (((x2)-(x1))*((x2)-(x1))+((y2)-(y1))*((y2)-(y1)))
const double eps = 1e-9;
const double pi = acos(-1);
const int oo = 1000000000;
const int mod = 1000000007;
const double E = 2.7182818284590452353602874713527;
using namespace std;

int v[205],v2[205],rec[205],num[205],tmp[205][405],stack[205];
bool hash[205],h2[205],visit[205];
vector<int> e[205];
int o,n;

bool dfs(int st,int now)
{
   visit[now]=1;
   for (int i=0;i<e[now].size();i++)
      if (e[now][i]==st||!visit[e[now][i]]&&!hash[e[now][i]]&&dfs(st,e[now][i]))
      {
         stack[++o]=now;
         return 1;
      }
   return 0;
}

int check()
{
   bool flag=true;
   int ans=0;
   while (flag)
   {
      flag=false;
      for (int i=1;i<=n;i++)
         if (!hash[i]&&v[rec[i]])
         {
            memset(visit,0,sizeof(int)*(n+1));
            o=0;
            if (dfs(i,i))
            {
               while (o)
               {
                  hash[stack[o]]=1;
                  v[rec[stack[o]]]--;
                  for (int j=1;j<=num[stack[o]];j++)
                     v[tmp[stack[o]][j]]++;
                  o--;
                  ans++;
               }
               flag=true;
            }
         }
   }
   flag=true;
   while (flag)
   {
      flag=false;
      for (int i=1;i<=n;i++)
         if (!hash[i]&&v[rec[i]])
         {
            flag=true;
            hash[i]=1;
            v[rec[i]]--;
            for (int j=1;j<=num[i];j++)
               v[tmp[i][j]]++;
            ans++;
         }
   }
   return ans;
}

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int q;
   cin>>q;
   for (int tt=1;tt<=q;tt++)
   {
      int k;
      cin>>k>>n;
      memset(v2,0,sizeof(v2));
      memset(h2,0,sizeof(h2));
      for (int i=1;i<=200;i++)
         e[i].clear();
      for (int i=1;i<=k;i++)
      {
         int a;
         cin>>a;
         v2[a]++;
      }
      for (int i=1;i<=n;i++)
      {
         cin>>rec[i]>>num[i];
         for (int j=1;j<=num[i];j++)
            cin>>tmp[i][j];
      }
      for (int i=1;i<=n;i++)
         for (int j=1;j<=num[i];j++)
            for (int k=1;k<=n;k++)
               if (rec[k]==tmp[i][j])
                  e[i].push_back(k);
      printf("Case #%d:",tt);
      memset(hash,0,sizeof(hash));
      for (int i=1;i<=200;i++)
         v[i]=v2[i];
      if (check()!=n)
         printf(" IMPOSSIBLE");
      else
      {
         for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
               if (!h2[j]&&v2[rec[j]])
               {
                  for (int k=1;k<=n;k++)
                     hash[k]=h2[k];
                  for (int k=1;k<=200;k++)
                     v[k]=v2[k];
                  hash[j]=1;
                  v[rec[j]]--;
                  for (int k=1;k<=num[j];k++)
                     v[tmp[j][k]]++;
                  if (check()==n-i)
                  {
                     printf(" %d",j);
                     h2[j]=1;
                     v2[rec[j]]--;
                     for (int k=1;k<=num[j];k++)
                        v2[tmp[j][k]]++;
                     break;
                  }
               }
      }
      puts("");
   }
   return 0;
}
