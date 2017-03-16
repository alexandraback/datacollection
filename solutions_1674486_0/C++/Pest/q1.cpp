using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

# define PI 3.14159265
int vis[10000];
vector<int>v[10000];
map<int,int>mp;
int cnt,flag;

void dfs(int n)
{
     int temp,len,v1;
     stack<int>s;
     vis[n]=1;
     s.push(n);
     mp[n]=1;
     cnt++;
     while(!s.empty())
     {
         temp=s.top();
         s.pop();
         len=v[temp].size();
         for(int i=0;i<len;i++)
         {
              v1=v[temp][i];
              //cout<<"v1"<<v1<<endl;
              if(!vis[v1])
              {
                 vis[v1]=1;
                 s.push(v1);
                 mp[v1]=1;
                 cnt++;
              }
              else if(vis[v1])
              {
                   flag=1;
                   //cout<<v1<<endl;
                   return;      
              }
         }
     }
     
}

int main()
{
    int n,m,l,v1,v2,k,t,i,cs=1,j;
    scanf("%d",&t);
    while(t--)
    {
              mp.clear();
              flag=0;
              scanf("%d",&n);
              for(i=1;i<=n;i++)
                vis[i]=0;
              cnt=0;  
              for(i=1;i<=n;i++)
              {
                 scanf("%d",&m);
                 //cout<<"bhaK";
                 for(j=0;j<m;j++)
                 {
                     scanf("%d",&v1);
                     v[i].push_back(v1);
                 }
              }
              //cout<<"hi";
              /*for(i=1;i<=n;i++)
              {
                 for(j=0;j<v[i].size();j++)
                 {
                    cout<<v[i][j]<<" ";
                 }
                 cout<<endl;
              }*/
              for(i=1;i<=n;i++)
              {
                 if(mp.find(i)==mp.end())
                 {
                     dfs(i);
                     if(flag)
                     {
                             //cout<<"i"<<i<<endl;
                             printf("Case #%d: Yes\n",cs++);
                             break;
                     }
                 }
                 for(j=1;j<=n;j++)
                    vis[j]=0;
                     
              }
              if(!flag)
                  printf("Case #%d: No\n",cs++);
              for(i=1;i<=n;i++)
                 v[i].clear();
    }
    //system("pause");
    return 0;
}
