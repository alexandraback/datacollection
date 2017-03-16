/*
ID: ahri1
PROG: C
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define sz(X) ((int)(X).size())
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }

struct attack{
  int d, s, w, e;
  const bool operator<(const attack &drugi) const {
    if (d!=drugi.d) return d<drugi.d;
    if (s!=drugi.s) return s<drugi.s;
    if (e!=drugi.e) return e<drugi.e;
    return w<drugi.w;  
  }
};

#define WALLN 2500

int WALL[WALLN+WALLN+1];

int getW(int X) {
  return WALL[WALLN+X];
}
void updateW(int X, int val) {
  WALL[WALLN+X]=max(WALL[WALLN+X], val);
}


void solve(){
  int N;
  cin >> N;
  set<int> badDays;
  attack tempA;
  map<int, vector<attack> > ATT;
  int di, ni, wi, ei, si, ddi, dpi, dsi;
  memset(WALL, 0, sizeof(WALL));
  for(int i=0;i<N;++i) {
    cin >> di >> ni >> wi >> ei >> si >> ddi >> dpi >> dsi;
    for(int j=0;j<ni;++j) {
      tempA.d = di+ddi*j;
      tempA.w = wi+dpi*j;
      tempA.e = ei+dpi*j;
      tempA.s = si+dsi*j;
      ATT[tempA.d].push_back(tempA);
      badDays.insert(tempA.d);
    }
  }
  int ret=0;
  FOREACH(day, ATT){
    FOREACH(att, day->second) {
      for(int i=(att->w)*2;i<=(att->e)*2;i++) {
        if (getW(i)<att->s) {
          ret++;
//          cout << att->d << " " << att->s << " " << att->w << " " << att->e << " SUCCESFUL" << endl;
          break;
        }
      }
    }
    FOREACH(att, day->second) {
      for(int i=(att->w)*2;i<=(att->e)*2;i++)  {
        updateW(i, att->s);
      }
    }
  }
  cout << ret << endl;
}

int main() {

  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}
