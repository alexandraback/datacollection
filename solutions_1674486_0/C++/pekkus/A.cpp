#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int nm[1000][1000];

int main()
{
  ofstream fout("A-small-attempt0.out");
  ifstream fin("A-small-attempt0.in");

  int T; fin >> T;
  for(int t = 1; t <= T; t++)
  {
    memset(nm, 0, sizeof(nm));
    int N; fin >> N;
    for(int i = 0; i < N; i++)
    {
      int M; fin >> M;
      for(int j = 0; j < M; j++)
      {
        int m; fin >> m;
        nm[m-1][i] = 1;
      }
    }
    
    bool ans = false;
    
    for(int i = 0; i < N && !ans; i++)
    {
      vector<int> c(N, 0);
      vector<int> vis(N, 0);
      queue<int> q;
      q.push(i);
      vis[i] = 1;
      while(q.size() && !ans)
      {
        int now = q.front();
        q.pop();
        for(int j = 0; j < N && !ans; j++)
        {
          if (nm[now][j] && !vis[j])
          {
            q.push(j);
            vis[j] = 1;
          } 
          if (nm[now][j])
          {
            c[j]++;
            if (c[j] >= 2)
              ans = true;
          }
        }
      }
    }

    fout << "Case #" << t << ": " << (ans ? "Yes" : "No") << endl;
  }

  return 0;
}
