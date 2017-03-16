#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

int N,M,K;
bool G[100][100];
bool vis[100][100];

void go(int a, int b) {
  if (G[a][b] || vis[a][b]) return;
  vis[a][b] = true;
  if (a > 0) go(a-1, b);
  if (a < N-1) go(a+1, b);
  if (b > 0) go(a, b-1);
  if (b < M - 1) go(a, b+1);
}

void scase() {
  scanf("%d%d%d",&N,&M,&K);
  
  int A = N * M;
  int best = A;
  REP(m,1<<A) {
    int m2 = m;
    REP(i,N)REP(j,M) {
      G[i][j] = m2 % 2;
      m2 /= 2;
    }
    
    REP(i,N)REP(j,M) vis[i][j] = false;
    REP(i,N) {go(i,0); go(i,M-1);}
    REP(j,M) {go(0,j); go(N-1,j);}
    
    int cnt = 0;
    REP(i,N)REP(j,M) if (!vis[i][j]) ++cnt;
    if (cnt >= K) {
      int res = 0;
      REP(i,A) if (m&(1<<i)) ++res;
      best = min(best, res);
    }
  }
  
  printf("%d\n", best);
}

int main() {
  int Z;
  scanf("%d", &Z);
  REP(z,Z) {
    printf("Case #%d: ", z+1);
    scase();
  }
}    
