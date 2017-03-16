#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

std::vector<int> zip;
int neigh[8][8];
int used[8];
char cur[5*8+1];
char best[5*8+1];

int plan[8];
int N;

void doit(int d, int v)
{
  plan[d] = v;
  sprintf(cur+5*d, "%d", zip[v]);
  if (d == N-1)
  {
    std::vector<int> loc;
    loc.push_back(plan[0]);
    int po = 0;
    while(!loc.empty() && po < N-1)
    {
      int c = loc.back();
      if (neigh[c][plan[po+1]])
        loc.push_back(plan[++po]);
      else
        loc.pop_back();
    }
    if (po < N-1)
      return;
    
    for (int i=0; i<5*N; i++)
    {
      if (cur[i] > best[i])
        return;
      if (cur[i] < best[i])
        break;
    }
    strcpy(best, cur);
    return;
  }
  used[v] = 1;
  for (int i=0; i<N; i++)
    if (!used[i])
      doit(d+1, i);
  used[v] = 0;
}

int main()
{
  int T;
  std::cin >> T;
  for (int t=1; t<=T; t++)
  {
    int M;
    std::cin >> N >> M;
    zip.resize(N);
    for (int i=0; i<N; i++)
      std::cin >> zip[i];
    memset(neigh, 0, sizeof(neigh));
    for (int i=0; i<M; i++)
    {
      int a, b;
      std::cin >> a >> b;
      neigh[a-1][b-1] = 1;
      neigh[b-1][a-1] = 1;
    }
    best[0] = 'A';
    cur[5*N] = 0;
    for (int s=0; s<N; s++)
    {
      memset(used, 0, sizeof(used));
      doit(0, s);
    }
    std::cout << "Case #" << t << ": " << best << std::endl;
  }
  return 0;
}