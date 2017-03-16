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
#include <cstring>

using namespace std;

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
#define REP(i,n) for(int _n=n, i=0;i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define ALL(x)   (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define PB push_back

int N,M;
int bd[111][111];
int r[111], c[111];

int main() {
  int Ts;
  cin>>Ts;
  FOR(cs, 1, Ts) {
    cin>>N>>M;
    memset(r,0,sizeof(r)); 
    memset(c,0,sizeof(c));
    REP(i,N) REP(j,M) {
      cin>>bd[i][j];
      r[i] = max(r[i], bd[i][j]);
      c[j] = max(c[j], bd[i][j]);
    }
    string ans = "YES";
    REP(i,N) REP(j,M) {
      if (bd[i][j]<r[i] && bd[i][j]<c[j]) {ans="NO"; i=j=1000;}
    }
    cout << "Case #" << cs << ": " << ans << endl;
  }
  return 0;
}
