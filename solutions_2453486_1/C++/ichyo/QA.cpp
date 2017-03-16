#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
bool is_draw(string grid[4]){
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      if(grid[i][j] == '.') return false;
    }
  }
  return true;
}
bool is_win(string grid[4], char c){
  for(int i = 0; i < 4; i++){
    bool ok = true;
    for(int j = 0; j < 4; j++) if(grid[i][j] != c && grid[i][j] != 'T') ok = false;
    if(ok) return true;
  }
  for(int j = 0; j < 4; j++){
    bool ok = true;
    for(int i = 0; i < 4; i++) if(grid[i][j] != c && grid[i][j] != 'T') ok = false;
    if(ok) return true;
  }
  {
    bool ok = true;
    for(int i = 0; i < 4; i++){
      if(grid[i][i] != c && grid[i][i] != 'T') ok = false;
    }
    if(ok) return true;
  }
  {
    bool ok = true;
    for(int i = 0; i < 4; i++){
      if(grid[i][3 - i] != c && grid[i][3 - i] != 'T') ok = false;
    }
    if(ok) return true;
  }
  return false;
}

int main(){
  int T;
  cin >> T;
  REP(CASE, T){
    printf("Case #%d: ", CASE + 1);
    string grid[4];
    REP(i, 4) cin >> grid[i];
    if(is_win(grid, 'X')){
      cout << "X won" << endl;
    }else if(is_win(grid, 'O')){
      cout << "O won" << endl;
    }else if(is_draw(grid)){
      cout << "Draw" << endl;
    }else {
      cout << "Game has not completed" << endl;
    }
  }
  return 0;
}
