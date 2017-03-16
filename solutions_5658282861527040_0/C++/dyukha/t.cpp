#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <algorithm>
#include <string>
//#include <>

#define fori(i,b,e) for (int i = (b); i < (e); i++)
#define mp make_pair
#define pb push_back
#define add insert
#define all(a) (a).begin(), (a).end()
#define elsif else if
#define sz(a) ((int)(a).size())

using namespace std;

inline int getInt() { int res;  scanf("%d", &res);  return res; }
inline double getDbl() { double res;  scanf("%lf", &res);  return res; }

int A, B, C;
int a[32], b[32], c[32];

//    pos  c  a  b
//int64 dp[32][2][2][2]

void read() {
  A = getInt();
  B = getInt();
  C = getInt();
  /*fori(i,0,32) {
    a[i] = A & 1;
    b[i] = B & 1;
    c[i] = C & 1;
    A >>= 1;
    B >>= 1;
    C >>= 1;
  }*/
}

void solve() {
  /*fori(i,0,2)
    fori(j,0,2)
      dp[31][0][i][j] = 0;
  fori(i,0,2)
    fori(j,0,2)
      dp[31][1][i][j] = 1;
  for(int p = 30; p >= 0; p--) {
    if (c[p]) {
      dp[p][1][0][0] = dp[p+1][1][0][0]; // +
      dp[p][1][0][1] = b[p] == 0 ? 0 : dp[p+1][1][0][1]; // +
      dp[p][1][1][0] = a[p] == 0 ? 0 : dp[p+1][1][1][0]; // +
      dp[p][1][1][1] = a[p] && b[p] ? dp[p+1][1][1][1] : 0; // +
      dp[p][0][0][0] = dp[p+1][1][0][0] + dp[p+1][0][0][0] * 4;
      if (a[p] == 1)
        dp[p][0][0][0] += dp[p+1][0][1][0] * 2;
      if (b[p] == 1)
        dp[p][0][0][0] += dp[p+1][0][0][1] * 2;
      if (a[p] == 1 && b[p] == 1)
        dp[p][0][0][0] += dp[p+1][0][1][1];  // +
      dp[p][0][0][1] = dp[p+1][1][0][1];
      if (!b[p]) {
        dp[p][0][0][1] += dp[p+1][1][0][1];
      }
      dp[p][0][1][0] = a[p] == 0 ? dp[p+1][1][1][0] * 2 : dp[p+1][1][1][0];
      dp[p][0][1][1] = dp[p+1][0][1][1] * 2;
      if (a[p] == 0 && b[p] == 0)
        dp[p][0][1][1] += dp[p][1][1][1];
    } else {
      dp[p][1][0][0] = dp[p+1][1][0][0];
      dp[p][1][0][1] = 
      dp[p][1][1][0] =
      dp[p][1][1][1] =
      dp[p][0][0][0] = 0;
      dp[p][0][0][1] = 0;
      dp[p][0][1][0] = 0;
      dp[p][0][1][1] = 0;
    }
  }
  //int64 mul = 1;
  int64 res = 0;
  fori(i,0,2)
    fori(j,0,2)
      fori(k,0,2)
        res += dp[0][i][j][k];
  cout << res << "\n";*/
  int res = 0;
  fori(i,0,A)
    fori(j,0,B)
      if ((i & j) < C)
        res++;
  cout << res << "\n";
}

int main() {
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  srand(time(0));
  int N = getInt();
  fori(T,1,N+1) {
    read();
    printf("Case #%d: ", T);
    solve();
  }
}
