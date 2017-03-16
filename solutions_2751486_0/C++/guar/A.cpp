#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

#define FOR(i,a,b) for(int i(a); i <= b; ++i)
#define FORD(i,a,b) for(int i(a); i >= b; --i)
#define REP0(i,n) FOR(i,0,n-1)
#define REP1(i,n) FOR(i,1,n)
#define PU push_back
#define PO pop_back
#define MP make_pair
#define A first
#define B second
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define SZ(s) (int)((s).size())
#define CL(a) memset((a),0,sizeof(a))
#define MAX(X,Y) X = max((X),(Y))
#define MIN(X,Y) X = min((X),(Y))
#define FORIT(X,Y) for(typeof((Y).begin()) X=(Y).begin(); X!=(Y).end(); ++X)
#define VI vector <int>
#define ll long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define INF 1000000000

using namespace std;

bool isCon(char c) {
  return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

void onecase(int t) {
  string name;
  int n;
  cin >> name >> n;
  map<int, map<int, bool> > ls;
  int s = SZ(name);
  FOR(i,0,s-n) {
    bool found = true;
    FOR(p,i,i+n-1) {
      if(!isCon(name[p])) {
        found = false;
        break;
      }
    }
    if (found) {
      FOR(j,0,i) {
        FOR(k,i+n-1,s-1) {
          ls[j][k] = true;
        }
      }
    }
  }
  int count = 0;
  FORIT(it,ls) {
    count += SZ(it->B);
  }
  cout << "Case #" << t << ": " << count << endl;
}

int main() {
//  freopen("test.in", "r", stdin);
  int ntc;
  cin >> ntc;
  REP1(t,ntc) onecase(t);
}
