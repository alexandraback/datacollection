#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

bool BFS(vector<vector<int> >& adj, vector<int>& parent, int i, int j)
{
  if(i==j)
  {
    parent.push_back(i);
    return true;
  }
  for(int k=0; k<(int)adj[i].size(); k++)
  {
    if(adj[i][k] == 1 && !visited[k])
    {
      visited[k] = true;
      if(BFS(adj, parent, k, j))
      {
        parent.push_back(i);
        return true;
      }
    }
  }
  return false;
}

int main(){
  int cases;
  cin >> cases;
  for(int ic=0; ic<cases; ++ic)
  {
    cout << "Case #" << ic+1 << ":";
    int N; cin >> N;
    vector<vector<int> > adj = vector<vector<int> >(N, vector<int>(N,-1));
    for(int i=0; i<N; ++i)
    {
      int M; cin >> M;
      for(int j=0; j<M; ++j)
      {
        int node; cin >> node;
        adj[i][node-1] = 1;
      }
    }
    bool possible = false;
    for(int i=0; i<N; ++i)
    {
      for(int j=0; j<N; ++j)
      {
        vector<int> parent;
        visited = vector<bool>(N,false);
        visited[i] = true;
        if(i!=j && BFS(adj, parent, i, j))
        {
          adj[parent[parent.size()-1]][parent[parent.size()-2]] = 0;
          
          vector<int> parent2;
          visited = vector<bool>(N,false);
          visited[i] = true;
          if(BFS(adj,parent2,i,j))
          {
            possible = true;
            goto done;
          }
          adj[parent[parent.size()-1]][parent[parent.size()-2]] = 1;
        }
      }
    }
done:
    if(possible)
    {
      cout << " Yes\n";
    }
    else
    {
      cout << " No\n";
    }
  }
  return 0;
}