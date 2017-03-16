#include<iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <cmath>
#include <list>
#include <sstream>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;
typedef long long LL;
typedef vector<int> VI;
typedef pair<LL,LL> PLL;
typedef vector<pair<int,int> > VPII;
typedef vector<LL> VLL;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef long double LD;

#define PI 3.14159265358979323
#define EE 2.71828182845
#define EPS 10e-10
#define INF 10000000

inline LL MAX(LL a, LL b){ return a < b ? b : a;}
inline LL MIN(LL a, LL b){ return a < b ? a : b;}

#define FOR(i,n)      for(int i=0;i<(n);i++)
#define FORD(i,n)     for(int i=(n)-1;i>=0;i--)

#define MP make_pair
#define PB push_back

#define MX 1000001

int N,A;
int S[105];
int DP[105][1000500];

int kolko(int w, int sz){
  if (w >= N) return 0;
  if (DP[w][sz] != -1) return DP[w][sz];
  int vratim = -1;
  if (S[w] < sz) vratim = kolko(w+1, min(sz + S[w], MX));
  else{
    vratim = kolko(w+1,sz) + 1;
    if (sz > 1) vratim = min(vratim, 1+ kolko(w, min(2*sz - 1, MX)));
  }
  DP[w][sz] = vratim;
  return vratim;
}

void solve(int tt){
  memset(DP,-1,sizeof(DP));
  scanf("%d %d ",&A,&N);
  FOR(i,N) scanf("%d ", &S[i]);
  sort(S,S+N);
  printf("Case #%d: %d\n", tt+1, kolko(0,A));
}

int main(){
  int TT;
  scanf("%d ", &TT);
  FOR(tt,TT) solve(tt);
}

