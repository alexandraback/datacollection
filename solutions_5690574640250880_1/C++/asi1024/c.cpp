#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define sz size()
#define pb push_back
#define mp make_pair
#define ALL(X) (X).begin(),(X).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void output(int c, vector<string> v) {
  printf ("Case #%d:\n", c);
  REP(i,v.size())
    cout << v[i] << endl;
}
void impossible(int c) {
  printf ("Case #%d:\n", c);
  cout << "Impossible" << endl;
}

int main(void)
{
  int t, r, c, m;
  cin >> t;
  REP(cas,t) {
    cin >> r >> c >> m;
    string s;
    REP(i,c) s += "*";
    vector<string> res;
    REP(i,r) res.pb(s);
    m = r * c - m;
    if (min(r,c) == 1) {
      if (r == 1) REP(i,m) res[0][i] = '.';
      else REP(i,m) res[i][0] = '.';
      res[0][0] = 'c';
    }
    else if (min(r,c) == 2) {
      if (m == 1) res[0][0] = 'c';
      else if (m == 2 || m % 2 == 1) {impossible(cas+1); continue;}
      else if (r == 2) REP(i,2)REP(j,m/2) res[i][j] = '.';
      else REP(i,m/2)REP(j,2) res[i][j] = '.';
      res[0][0] = 'c';
    }
    else if (m == 1) res[0][0] = 'c';
    else if (m <= 3 || m == 5 || m == 7) {impossible(cas+1); continue;}
    else if (m == 4) {
      res[0][0] = 'c';
      res[0][1] = '.';
      res[1][0] = '.';
      res[1][1] = '.';
    }
    else if (m == 6) {
      if (r == 2) REP(i,2)REP(j,3) res[i][j] = '.';
      else REP(i,3)REP(j,2) res[i][j] = '.';
      res[0][0] = 'c';
    }
    else if (m >= 2 * c + 2) {
      REP(i,m) res[i/c][i%c] = '.';
      if (m % c == 1) {
        res[m/c][1] = '.';
        res[m/c-1][c-1] = '*';
      }
      res[0][0] = 'c';
    }
    else {
      REP(i,m) res[i%3][i/3] = '.';
      if (m % 3 == 1) {
        res[1][m/3] = '.';
        res[2][m/3-1] = '*';
      }
      res[0][0] = 'c';
    }
    output(cas+1, res);
  }
  return 0;
}
