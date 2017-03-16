#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define LL long long

long long L, X;
string s;

vector< vector<int> > quart;

int getval(char c) {
  if(c == 'i') return 2;
  if(c == 'j') return 3;
  return 4; // k
}

int qprod(int a, int b) {
  int fact = 1;
  if(a < 0) a = -a, fact *= -1;
  if(b < 0) b = -b, fact *= -1;
  return quart[a][b] * fact;
}


long long pre[10010];
long long suf[10010];

int main()
{

  quart.PB({0,  0,  0,  0,  0});
  quart.PB({0,  1,  2,  3,  4});
  quart.PB({0,  2, -1,  4, -3});
  quart.PB({0,  3, -4, -1,  2});
  quart.PB({0,  4,  3, -2, -1});


  int T;
  cin >> T;
  REP(caso, T) {
    cout << "Case #" << caso+1 << ": ";

    cin >> L >> X;
    cin >> s;

    pre[0] = 1;
    REP(i, L) {
      pre[i+1] = qprod(pre[i], getval(s[i]));
      // cout << pre[i+1] << " ";
    }
    // cout << endl;
    suf[0] = 1;
    REP(i, L) {
      suf[i+1] = qprod(getval(s[L-1-i]), suf[i]);
      // cout << suf[i+1] << " ";
    }
    // cout << endl;

    long long shortest_pre[4];
    long long shortest_suf[4];
    long long fact = 1;

    REP(rep, 4) {
      shortest_pre[rep] = -1;
      REP(i, L) { // do not consider the complete prefix
        if(qprod(fact, pre[i]) == 2) {
          shortest_pre[rep] = i;
          break;
        }
      }
      // cout << shortest_pre[rep] << " | ";
      fact = qprod(fact, pre[L]);
    }
    // cout << endl;


    fact = 1;

    REP(rep, 4) {
      shortest_suf[rep] = -1;
      REP(i, L) { // do not consider the complete suffix
        if(qprod(suf[i], fact) == 4) {
          shortest_suf[rep] = i;
          break;
        }
      }
      // cout << shortest_suf[rep] << " | ";
      fact = qprod(suf[L], fact);
    }
    // cout << endl;

    bool found = false;
    REP(ri, 4) {
      if(found) break;
      REP(rk, 4) {
        if(found) break;
        if(shortest_pre[ri] < 0) continue;
        if(shortest_suf[rk] < 0) continue;
        if(ri+rk >= X) continue;
        if(ri+rk == X-1) {
          // cout << ri << " " << rk << endl;
          int mid = 1;
          FOR(i, shortest_pre[ri], L-shortest_suf[rk]) mid = qprod(mid, getval(s[i]));
          if(mid == 3) found = true;
        } else {
          int mid = suf[L-shortest_pre[ri]];
          int block_times = (X-ri-rk-2)%4;
          REP(i, block_times) mid = qprod(mid, pre[L]);
          mid = qprod(mid, pre[L-shortest_suf[rk]]);
          // cout << "mid=" << mid << endl;
          if(mid == 3) found = true;
        }
      }
    }

    if(found) cout << "YES\n";
    else cout << "NO\n";



  }
}
