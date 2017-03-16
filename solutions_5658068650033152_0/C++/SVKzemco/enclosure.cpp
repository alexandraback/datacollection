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
typedef vector<char> VC;

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

int sol[20][20];
int bol[20][20];
int N, M;

//TODO da sa memoizovat
bool dfs(int wx, int wy){
  if (sol[wx][wy] == 1) return false;
  if (wx == 0 || wx == N - 1 || wy == 0 || wy == M - 1) return true;
  if (bol[wx][wy] == 1) return false;
  bol[wx][wy] = 1;
  int dx[4] = {-1,1,0,0};
  int dy[4] = {0,0,-1,1};
  FOR(i, 4) if (dfs(wx + dx[i], wy + dy[i])) return true;
  return false;
}

void solve(int tc){
  int K;
  cin >> N >> M >> K;
  int best = K;
  FOR(i, (1 << N*M)){
    int count = 0;
    FOR(j, N*M) if ((1 << j) & i){
      sol[j / M][j % M] = 1;
      count++;
    }else sol[j / M][j % M] = 0;

    if (count >= best) continue;
    
    int zavrete = 0;
    FOR(i, N) FOR(j, M){
      memset(bol, 0, sizeof(bol));
      if (!dfs(i,j)) zavrete++;
    }
    if (zavrete >= K) best = count;
  }
  cout << "Case #" << tc << ": " << best << endl;
}

int main(){
  int TT;
  cin >> TT;
  FOR(tt, TT) solve(tt + 1);
  return 0;
}
