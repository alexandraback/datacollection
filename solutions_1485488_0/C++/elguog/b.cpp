#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
#define REP(i,n) for(int _n=n, i=0;i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define ALL(x)   (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define PB push_back

int H, N, M;
int F[111][111], C[111][111];
int dp[111][111];
int MX = (1<<31)-1;

int mx[4]={1, -1, 0, 0};
int my[4]={0, 0, 1, -1};

double bst(int t, int fh, int ch, int c, int f) {
  if (f+50>c || fh+50>c || f+50>ch) return MX;
  int w = H - t;
  if (w+50>c) {
    w = c-50;
    t = H-w;
  }
  if (w>=fh+20) return t+10;
  return t+100;
}

int valid(int a, int b) {
  return a>=0 && a<N && b>=0 && b<M;
}

double play() {
  REP(i,N) REP(j,M) dp[i][j]=MX;
  dp[0][0]=0;
  int fg=1;

  while(fg) {
    fg=0;
    REP(i,N) REP(j,M) if(dp[i][j]==MX) {
      REP(k, 4) {
        int ii=i+mx[k], jj=j+my[k];
        if(valid(ii,jj) && dp[ii][jj]!=MX) {
          if(H+50<=C[i][j] && F[ii][jj]+50<=C[i][j] &&
             F[i][j]+50<=C[i][j] && F[i][j]+50<=C[ii][jj]) {
            fg=1;
            dp[i][j]=0;
          }
        }
      }
    }
  }

  if (dp[N-1][M-1]!=MX) return 0;

  fg=1;
  while(fg) {
    fg=0;
    REP(i,N) REP(j,M) if(dp[i][j]!=MX) {
      REP(k,4) {
        int ii=i+mx[k], jj=j+my[k];
        if (valid(ii,jj)) {
          int t=bst(dp[i][j], F[i][j], C[i][j], C[ii][jj], F[ii][jj]);
          if(t<dp[ii][jj]) {
            fg=1;
            dp[ii][jj]=t;
          }
        }
      }
    }
  }

  return dp[N-1][M-1] / 10.0;
}

int main() {
  int Ts;
  cin>>Ts;
  FOR(cs, 1, Ts) {
    cin>>H>>N>>M;
    REP(i,N) REP(j,M) cin>>C[i][j];
    REP(i,N) REP(j,M) cin>>F[i][j];
    cout << "Case #" << cs << ": " <<play() << endl;
  }
  return 0;
}
