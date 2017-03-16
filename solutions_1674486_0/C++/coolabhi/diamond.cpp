//Maximum flow using Ford-Fulkerson
#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<cctype>
#include<climits>
template <class datatype> datatype gcd(datatype a,datatype b){ return (b==0)?a:gcd(b,a%b); }
template <class datatype> datatype lcm(datatype a,datatype b){ return a*(b/gcd(a,b)); }
using namespace std;

struct node
{
       int vertex,steps;
       node(int a,int b){ vertex=a;steps=b;}
};
int reset,n;
bool list[51][51];
bool dfs(int a,int b)
{
    bool visited[51]={0};
    int i=0,j;
    stack<node> q;
    q.push(node(a,0));
    visited[a]=1;
    while(!q.empty())
    {
      node temp=q.top();
      q.pop();
      for(j=1;j<=n;j++)
      {
        
        if(!visited[j] && list[temp.vertex][j])
        {
        if(j==b)
        {
         visited[j]=1;
         reset=temp.vertex;
         list[temp.vertex][j]=0;
         break;
        }
        q.push(node(j,temp.steps+1));
        visited[j]=1;
        }
      }
      if(j==b)break;
    }
    return visited[b];   
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,i,j,p,m,s,d,count,x;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
      scanf("%d",&n);
      for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
        list[i][j]=0;
      for(i=1;i<=n;i++)
      {
        scanf("%d",&p);
        for(j=0;j<p;j++)
        {
          scanf("%d",&m);
          list[i][m]=1;
        }
      }
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       count=0;
       if(i!=j)
       {
       s=i;d=j;
       while(dfs(s,d))
      {
       count++;
       if(count>1)
       break;
      }
      if(count>1)break;
      }
      if(count==1)list[reset][j]=1;
       
     }
   if(count>1)break;
   }
    printf("Case #%d: ",x);
    if(count>1)printf("Yes\n");
    else printf("No\n");
}
    return 0;
}
