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

int N;
double v1[1111], v2[1111];
int S1, S2;

int play(double v1[], double v2[]) {
  REP(a,N) {
    int ok=1;
    REP(i,N-a) {
      if (v1[i]>v2[i+a]) {
        ok=0;
        break;
      }
    }
    if(ok) return a;
  }
  return N;
}

int main() {
  int Ts;
  cin>>Ts;
  FOR(cs, 1, Ts) {
    cin>>N;
    REP(i, N) cin>>v1[i];
    REP(i, N) cin>>v2[i];
    sort(v1, v1+N);
    sort(v2, v2+N);
    S1 = N - play(v2, v1);
    S2 = play(v1, v2);
    cout << "Case #" << cs << ": "<<S1<<" "<<S2<<endl;
  }
  return 0;
}
