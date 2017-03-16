#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define MAXN 1200
#define INF 200000

int T;
int Pi[MAXN];
int D;

int main() {
  cin >> T;
  REP(zz,T) {
    cin >> D;
    REP(i,D) cin >> Pi[i];
    int bestq = INF;
    for (int q=1;q<=MAXN;q++) {
      int score = q;
      REP(i,D) score+=(Pi[i]-1)/q;
      bestq=min(bestq,score);
    }



    cout << "Case #" << (zz+1) << ": " << bestq << endl;
  }
}
