#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<cstdio>
using namespace std;
int adj[1010][1010],vis[1010];
 vector<int> arr[1010];
bool cn;

void DFS_visit(int w)
     {
     int i;

     for(i=0;i<arr[w].size();i++)
     {

     if(vis[arr[w][i]]==0)
        cn=true;
    else
    {
        vis[arr[w][i]]=0;
        DFS_visit(arr[w][i]);
    }
     }

     }
 bool check(int N,int kk,int w)
 {
     int i;
     bool cn;
     if(w==kk)
       return true;
     vis[w]=0;
     for(i=1;i<=N;i++)
     if(adj[w][i]==1&&vis[i]==1)
        return check(N,kk,i)||false;
     return false;
 }
int main()
{

 int t,N,k,jj,l;
 freopen("inp.in","r",stdin);
 freopen("out.in","w",stdout);
 cin>>t;
 vector<int>vv;
 int cs=0;
 while(t--)
  {
      scanf("%d",&N);
      cs ++;
      for(int i=1;i<=N;i++)
       {
           scanf("%d",&k);
           arr[i].clear();
           for(int j=1;j<=k;j++)
            {
                scanf("%d",&jj);
                arr[i].push_back(jj);
            }
       }

      for(int kk=1;kk<=N;kk++)
         {
             memset(vis,1,sizeof(vis));
             cn=false;
             vis[kk]=0;
            DFS_visit(kk);

            if(cn)
              {cout<<"Case #"<<cs<<": Yes\n";break;}

         }
     if(!cn)
         cout<<"Case #"<<cs<<": No\n";;
  }
 return 0;
}
