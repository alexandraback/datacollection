#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<algorithm>

using namespace std;

int vis[1000];
int deg[1000];


void dfs(int **adj, int n, int s) {
  vis[s]++;
  for(int i=0;i<n;i++) {
    if(adj[s][i] == 1) {
      dfs(adj, n, i);
    }
  }
}


int main() {
  ifstream fin("a-small.in");
  ofstream fout("a-small.out");

  int tests; fin >> tests;
  for(int test = 1; test <= tests; test++) {
    int n; fin >> n;
    int **adj;
    adj = (int **)malloc(n * sizeof(int *));
    for(int i=0;i<n;i++) 
      adj[i] = (int*)malloc(n * sizeof(int));

    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        adj[i][j] = 0;

    for(int i=0;i<1000;i++) 
      deg[i] = 0;

    for(int i=0;i<n;i++) {
      int t; fin >> t;
      for(int j=0;j<t;j++) {
        int s; fin >> s;
        adj[i][s-1] = 1;
        deg[i]++;
      }
    }
    bool flag = false;
    for(int i=0;i<n;i++){
      for(int j=0;j<1000;j++) 
        vis[j] = 0;
      dfs(adj, n, i);
      for(int j=0;j<n;j++)
        if(vis[j] > 1)
          flag = true;

      if(flag) break;
    }

    for(int i=0;i<n;i++)
      free(adj[i]);
    free(adj);
    string ret = "No";
    if(flag) ret = "Yes";
    fout << "Case #" << test << ": " << ret << endl;
  }

}