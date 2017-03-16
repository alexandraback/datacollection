#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;


const int N = 1000;
const int C = 500;
int board[N][N];
int X0, Y0;
int X1, Y1;


struct SNode
{
  int x, y;
  int step;
  string mv;
};
inline bool ok(int x, int y) 
{
   x = x + C;
   y = y + C;
  if(x < 0 || x>= N || y < 0 || y >= N) {
    return false;
  }
  if(board[x][y])return false;
  return true;
}
void solve()
{
  for (int i = 0;i < N;i++) for (int j = 0;j < N;++j) board[i][j] = 0;
  X0 = 0, Y0 = 0;
  cin>>X1>>Y1;

  queue<SNode> q;
  SNode v0;
  v0.x = X0, v0.y = Y0, v0.step = 0;
  board[0 + C][0 + C] = 1;
  q.push(v0);
  while( !q.empty()) {
    SNode &v1 = q.front();
    if(v1.x==X1 && v1.y == Y1) {
      cout<<v1.mv<<endl;
      return;
    }
    int inc = v1.step + 1;
    if(ok(v1.x + inc, v1.y)) {
      SNode v2;
      v2.x = v1.x + inc;
      v2.y = v1.y;
      v2.step = v1.step + 1;
      v2.mv = v1.mv + string("E");
      q.push(v2);
      board[v1.x + inc + C][v1.y + C] = 1;
    }
    if(ok(v1.x - inc, v1.y)) {
      SNode v2;
      v2.x = v1.x - inc;
      v2.y = v1.y;
      v2.step = v1.step + 1;
      v2.mv = v1.mv + string("W");
      q.push(v2);
      board[v1.x - inc + C][v1.y + C] = 1;
    }

    if(ok(v1.x , v1.y+ inc)) {
      SNode v2;
      v2.x = v1.x;
      v2.y = v1.y + inc;
      v2.step = v1.step + 1;
      v2.mv = v1.mv + string("N");
      q.push(v2);
      board[v1.x + C][v1.y + C + inc] = 1;
    }
    if(ok(v1.x , v1.y- inc)) {
      SNode v2;
      v2.x = v1.x;
      v2.y = v1.y - inc;
      v2.step = v1.step + 1;
      v2.mv = v1.mv + string("S");
      q.push(v2);
      board[v1.x + C][v1.y + C - inc] = 1;
    }
    q.pop();
  }
  //cout<<"can not"<<endl;

}
int main()
{
  //freopen("data.txt", "r", stdin);
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);
  //freopen("B-large-practice.in", "r", stdin);
  //freopen("B-large-practice.out", "w", stdout);
  int t;
  cin>>t;
  for (int i = 1;i <= t;++i) {
    //int n;
    //cin>>n;
    cout<<"Case #"<<i<<": ";
    solve();
  }
  return 0;
}
