#include <iostream>
#include <vector>
using namespace std;

int a[1001][1001], degree[1001], visited[1001];
int N;
vector <int> neighbours[1001];

int dfs(int v) {
  int i,j;
  if(visited[v])
    return 1;
  visited[v]=1;
  for(i=0;i<neighbours[v].size();i++) {
    j=dfs(neighbours[v][i]);
    if(j)
      return j;
  }
  return 0;
}

int main () {
  int T,t;
  cin>>T;
  for(t=0;t<T;t++) {
    int i,j,M,x;
    cin>>N;
    for(i=0;i<N;i++) {
      degree[i]=0;
      visited[i]=0;
      neighbours[i].clear();
      for(j=0;j<N;j++)
	a[i][j]=0;
    }
    for(i=0;i<N;i++) {
      cin>>M;
      for(j=0;j<M;j++) {
	cin>>x;
	neighbours[i].push_back(x-1);
	degree[x-1]++;
      }
    }
    x=0;
    for(i=0;i<N;i++) {
      if(degree[i]==0) {
	for(j=0;j<N;j++) 
	  visited[j]=0;
	x = dfs(i);
      }
      if(x)
	break;
    }
    cout<<"Case #"<<t+1<<": ";
    if(x)
      cout<<"Yes";
    else 
      cout<<"No";
    cout<<"\n";
  }
  return 0;
}
