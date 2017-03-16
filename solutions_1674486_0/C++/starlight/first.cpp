#include<iostream>
using namespace std;
int adj[1010][1010];
int vis[1010];
void dfs(int s,int n)
{
     vis[s]++;
     for(int i=0;i<n;i++)
        if(adj[s][i]==1 && vis[i]<=1)
        {
          dfs(i,n);              
        }
}

int main()
{
    int t,z=1;
    cin>>t;
    while(t--)
    {
        int n,temp,temp1,flag=0;
        cin>>n;
        for(int i=0;i<n+1;i++)
         for(int j=0;j<n+1;j++)
           adj[i][j]=0;
        for(int i=0;i<n;i++)
        {
           cin>>temp;
           for(int j=0;j<temp;j++)
           {
               cin>>temp1;
               adj[i][temp1-1]=1;    
           }     
        }      
        
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<n;j++) vis[j]=0;      
             dfs(i,n);
          for(int j=0;j<n;j++) 
             if(vis[j]>=2 && j!=i)
             {
                flag=1;
                break;
             }
        }
        if(flag)
        printf("Case #%d: Yes\n",z++);
        else 
        printf("Case #%d: No\n",z++);
    }
}
