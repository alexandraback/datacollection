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

int R,N,M,K;
int x[20];
int a[20];

void play() {
  FOR(a, 2, M) FOR(b, 2, M) FOR(c, 2, M) {
    set<int> S;
    S.insert(1);
    S.insert(a);
    S.insert(b);
    S.insert(c);
    S.insert(a*b);
    S.insert(a*c);
    S.insert(b*c);
    S.insert(a*b*c);
    int i;
    for (i=0;i<K;i++) if (S.find(x[i]) == S.end()) i =10000;
    if (i < 5000) {
      cout << a<<b<<c<<endl;
      return;
    }
  }
}

int main() {
  int Ts;
  cin>>Ts;
  FOR(cs, 1, Ts) {
    cin>>R>>N>>M>>K;
    cout << "Case #" << cs << ":" << endl;
    REP(z, R) {
      REP(i,K) cin>>x[i];
      play();
    }
  }
  return 0;
}
