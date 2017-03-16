#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
//#define trace(x) { cerr << #x << " = " << x << endl; }
#define trace(x) {}

using namespace std;

typedef long long ll;

int gao[1600];
int c[800];

double dp[3300][3300];

double recur(int M, int D) {
  if (D == 0) return 1.0;
  if (M == 0) return 0.0;

  double& d = dp[M][D];
  if(d != -1) return d;

  return d = 0.5 * recur(M - 1, D) + 0.5 * recur(M - 1, D - 1);
}

void init() {
  gao[0] = 1;
  int y = 1;
  for(int i = 1; i < 1600; i++) {
    y += 1;
    gao[i] = gao[i-1] + y;
  }

  rep(i, 800) {
    c[i] = gao[i*2];
  }

  rep(i, 10) cerr << c[i] << ", ";
  cerr << endl;
  //int HOGE = 799;
  //cerr << c[HOGE] << endl;
  //cerr << c[HOGE] - c[HOGE-1] << endl;

  rep(i, 3300) rep(j, 3300) dp[i][j] = -1;

  cerr << recur(20, 20) << endl;
}

double solve(int N, int X, int Y) {
  if(X < 0) X = -X;
  if (N == 1) {
    if(X == 0 && Y == 0) return 1.0;
    else 0.0;
  }
  rep(i, 800) {
    if(c[i] < N && c[i+1] >= N) {
      // within i*2 => 1.0
      // over (i*2+2) => 0.0
      // otherwise => calculate!

      if(X + Y <= i*2) return 1.0;
      if(X + Y > i*2+2) return 0.0;
      
      if(X == 0) {
        if(N == c[i+1]) return 1.0;
        else return 0.0;
      }
      else {
        int M = N - c[i];
        int D = Y + 1;
        int MAX = min(M, (c[i+1] - c[i] - 1) / 2);
        trace(M);
        trace(D);
        trace(MAX);
        // flip coin M times and answer is head D>= times??
        // d <= MAX, M - d <= MAX
        // M - MAX <= d <= MAX
        if (D < M - MAX) return 1.0;
        if (D > MAX) return 0.0;

        if (M - MAX > 0) {
          D -= M - MAX;
          M -= (M - MAX) * 2;
        }
        //cerr << "DP" << endl;
        trace(M);
        trace(D);
        // flip coin M times and answer is head D>= times
        return recur(M, D);
      }
      
    }
  }
}

void run() {

  init();

  int T;
  cin >> T;

  rep(i, T) {
    int N, X, Y;
    cin >> N >> X >> Y;

    cout << fixed << setprecision(8);
    cout << "Case #" << (i+1) << ": " << solve(N, X, Y) << endl;
  }

}

#undef int
int main() {
  run();
  return 0;
}
