#include <cstdio>
#include <vector>

bool solve()
{
  int N;
  scanf("%d", &N);
  std::vector<std::vector<int> > inher(N);
  std::vector<std::vector<int> > outgoing(N);
  std::vector<int> edges(N);
  std::vector<std::vector<bool> > score(N, std::vector<bool>(N));
  std::vector<int> order;
  for(int i=0; i<N; ++i) {
    int M;
    scanf("%d", &M);
    edges[i] = M;
    if(!M)
      score[i][i] = true;
    for(int j=0; j<M; ++j) {
      int x;
      scanf("%d", &x);
      inher[i].push_back(x-1);
      outgoing[x-1].push_back(i);
    }
  }
  for(;;) {
    int i;
    for(i=0; i<N; ++i) {
      if(edges[i] == 0) {
	order.push_back(i);
	for(int j=0; j<(int)outgoing[i].size(); ++j)
	  --edges[outgoing[i][j]];
	edges[i] = -1;
	break;
      }
    }
    if(i==N)
      break;
  }
  for(int i=0; i<N; ++i) {
    const int o = order[i];
    for(int j=0; j<(int)inher[o].size(); ++j) {
      for(int k=0; k<N; ++k) {
	if(score[o][k] && score[inher[o][j]][k])
	  return true;
	if(score[inher[o][j]][k])
	  score[o][k] = true;
      }
    }
  }
  return false;
}

int main()
{
  int T;
  scanf("%d", &T);
  for(int cases=1; cases<=T; ++cases) {
    printf("Case #%d: %s\n", cases, solve() ? "Yes" : "No");
  }
  return 0;
}
