#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int a[20][20];

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void full(int n, int m, bool show) {
  bool ch = true;
  while (ch) {
    ch = false;
    for (int i = 0; i<n;i++){
      for (int j = 0; j<m;j++){
        if (show) {
          cerr << i << " " << j << " " << a[i][j] << endl;
        }
        if (a[i][j] != 0){
          continue;
        }
        if (i == 0 || i == n-1 || j == 0 || j == m-1) {
          a[i][j] = 2;
          ch = true;
          continue;
        }
        for (int d = 0;d<4;d++) {
          if (a[i+dx[d]][j+dy[d]] == 2){
            a[i][j] = 2;
            if (show) {
              cerr << i << " " << j << " fill " << a[i][j] << endl;
            }
            ch = true;
          }
        }
      }
    }
  }
}

int main(){
  freopen("in.in", "r", stdin);
  freopen("res.txt", "w", stdout);
  int T;
  cin >> T;
  for (int t=0;t<T;t++){
    cerr << t << endl;
    int n,m,k;
    cin >> n >> m >> k;
    int res = k;
    for (int mask = 1; mask < (1<<(n*m)); mask++) {
      if (mask % 100000 == 0){
        cerr << t << " " << mask << " " << (1<<(n*m)) << endl;
      }
      memset(a,0,sizeof a);
      int S = 0;
      for (int i = 0; i<n;i++){
        for (int j = 0; j<m;j++){
          int v = i*m+j;
          a[i][j] = !!(mask & (1<<v));
          S += a[i][j];
        }
      }
      /*
      if (mask % 1 == 0 && mask >= 2210){
        cerr << t << " " << mask << " " << (1<<(n*m)) << "start full" << endl;
      }
      */
      full(n,m,false);
      /*
      if (mask % 1 == 0 && mask >= 2210){
        cerr << t << " " << mask << " " << (1<<(n*m)) << "fulled" << endl;
      }*/
      int K = 0;
      for (int i = 0; i<n;i++){
        for (int j = 0; j<m;j++){
          if (a[i][j] != 2){
            K++;
          }
        }
      }
      if (K >= k) {
        res = min(res, S);
      }
    }
    cout << "Case #" << t+1 << ": " << res << endl;
  }
  return 0;
}