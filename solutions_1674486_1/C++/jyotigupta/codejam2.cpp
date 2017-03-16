#include<iostream>
#include<vector>
#define size1 2000
using namespace std;
int n;
vector<int> edg[size1];
int start=0;
int visited[size1];
bool top=false;
void dfs( int node )
{
     
     
     visited[node]++;
     int len=edg[node].size();
     for(int i=0;i<len;i++)
     {
     //cout<<node<<":"<<edg[node][i]<<"\n";
     //system("pause");
     if( visited[edg[node][i]]<=1)
         {
     
     dfs(edg[node][i]);
     
          }
     
     
     }
     
     
     
     }


int main()
{
    
int t;
cin>>t;
int m=1;
while(t--)
{
          
          cin>>n;
          
          top=false;
          for(int i=0;i<n;i++)
          {
          
          edg[i+1].clear();
          visited[i+1]=0;
          int tot;
          cin>>tot;
          if(tot==0)
          start=i+1;
          for(int j=0;j<tot;j++)
          {
                  int node;
                  cin>>node;
                  edg[i+1].push_back(node);
                  
                  }        
                  
          }
          
          //input
          
          for(int i=0;i<n;i++)
          {
           for(int k=0;k<n;k++)
           visited[k+1]=0;       
           dfs(i+1);
          for(int k=0;k<n && !top;k++)
          if(k+1 != i+1 && visited[k+1]>=2)
          top=true;
          
          
          
          
          }
          if(!top)
          printf("Case #%d: No\n",m++);
          else
          printf("Case #%d: Yes\n",m++);

          
          
          }    
    
    }
