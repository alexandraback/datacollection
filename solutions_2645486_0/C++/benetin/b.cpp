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

int E, R, N, v[11111], C;
long long ret;

void play() {
  C = E;
  REP(i, N) {
    int j;
    for (j = i+1; j < N; j++) if (v[i] < v[j]) break;
    if (j == N) {
      ret += ((long long)C) * v[i]; C=0;
    } else {
      long long P = (long long)E - ((long long)R) * (j-i);
      if (P < 0) P = 0;
      if (C > (int) P) {
        ret += ((long long)(C - (int)P)) * v[i]; C = (int)P;
      }
    }
    C += R;
    if (C > E) C = E;
  }
}

int main() {
  int Ts;
  cin>>Ts;
  FOR(cs, 1, Ts) {
    cin >> E>>R>>N;
    REP(i,N) cin>>v[i];
    ret = 0;
    play();
    cout << "Case #" << cs << ": " << ret << endl;
  }
  return 0;
}
