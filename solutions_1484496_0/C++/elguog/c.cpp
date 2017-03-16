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
i64 a[510];

map<i64, int> mp;

void show(int S) {
  int fst=1;
  REP(i, N) if(S&(1<<i)) {
    if (!fst) cout<<" ";
    fst=0;
    cout<<a[i];
  }
  cout<<endl;
}

void play() {
  REP(S, (1<<N)) {
    i64 s=0;
    REP(i, N) if(S&(1<<i)) s+=a[i];
    if(mp.find(s)!=mp.end()) {
      show(S);
      show(mp[s]);
      return;
    }
    mp[s]=S;
  }
  cout<<"Impossible"<<endl;
}

int main() {
  int Ts;
  cin>>Ts;
  FOR(cs, 1, Ts) {
    mp.clear();
    cin>>N;
    REP(i,N) cin>>a[i];
    cout << "Case #" << cs << ":" << endl;
    play();
  }
  return 0;
}
