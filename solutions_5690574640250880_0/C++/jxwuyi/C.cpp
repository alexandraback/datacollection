#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<random>
#include<numeric>
#include<deque>
using namespace std;
#define LL long long

int N, M, K;

char G[60][60];

bool go(int N, int M, int K) {
  if(K == N * M - 1 || min(N, M) == 1) {
    for(int i=0;i<N;++i)
      for(int j=0;j<M;++j)
      {
        if(K) G[i][j]='*';
        else G[i][j]='.';
      }
    G[N-1][M-1]='c';
    return true;
  }
  if(K >= N * M - 3) return false;
  int R=min(N,M);
  if(K >= R) {
    if(R == N) {
      for(int i=0;i<R;++i)
        G[i][M - 1] = '*';
      return go(N, M - 1, K - R);
    } else {
      for(int i=0;i<R;++i)
        G[N-1][i] = '*';
      return go(N - 1, M, K - R);
    }
  }
  if(R == 2 && K == 1) return false;
  if(R == 3 && M + N - R == 3 && K == 2) return false;
  
  
  //cerr << "N = "<<N<<" M = "<<M<<" K = "<<K<<"  res = true!"<<endl;
  
  if(N > M) {
    for(int i = N - 1; i > 1; -- i)
      if(K) {
        -- K;
        G[i][M -1 ] = '*';
      }
    for(int i = M - 2; i > 1; -- i)
      if(K) {
        -- K;
        G[N - 1][i] = '*';
      }
  }
  else {
    for(int i = M - 1; i > 1; -- i)
      if(K) {
        -- K;
        G[N - 1][i] = '*';
      }
    for(int i = N - 2; i > 1; -- i)
      if(K) {
        -- K;
        G[i][M -1 ] = '*';
      }
  }
  
  G[0][0] = 'c';
  for(int i=0;i<N;++i)
    for(int j=0;j<M;++j)
      if(!G[i][j])
        G[i][j] = '.';
  return true;
}

int main() {
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  
  ofstream fout("log.txt");
  
  int test;cin >> test;
  for(int no = 1; no <= test; ++ no) {
      printf("Case #%d:\n", no);
      cin >> N >> M >> K;
      memset(G,0,sizeof(G));
      if(!go(N,M,K)) {
        
        fout << N << " " << M << " " << K << endl;
        puts("Impossible");
        continue;
      }
      for(int i=0;i<N;++i)
        puts(G[i]);
  }
}

