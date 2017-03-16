#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;
int n;

bool f(int start,vector<int> adj[])
{
  vector<int> visited(n+1);
  
  stack<int> st;
  st.push(start);
  while(!st.empty())
    {
      int x=st.top();
      st.pop();
      int neigh=adj[x].size();
      for(int i=0;i<neigh;i++)
	{
	  int y=adj[x][i];
	  if(visited[y])
	    return true;
	  visited[y]=1;
	  st.push(y);
	}
    }
  return false;
}

int main()
{
  int T;
  cin>>T;
  for(int t=1;t<=T;t++)
    {
      cin>>n;
      
      vector<int> adj[n+1];
      
      for(int i=1;i<=n;i++)
	{
	  int s;
	  cin>>s;
	  for(int j=0;j<s;j++)
	    {
	      int x;
	      cin>>x;
	      
	      adj[i].push_back(x);
	    }
	}

      bool resp=false;
      
      for(int i=1;i<=n;i++)
	{
	  resp=f(i,adj);
	  if(resp)break;
	}

      cout<<"Case #"<<t<<": "<<(resp?"Yes":"No")<<endl;
    }
  return 0;
}
