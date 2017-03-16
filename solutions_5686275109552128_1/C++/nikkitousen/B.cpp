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

int D;
int p[1001];
int dcount[1001];

int main()
{
  int T;
  cin >> T;
  REP(caso, T) {
    cout << "Case #" << caso+1 << ": ";

    memset(dcount, 0, sizeof(dcount));

    cin >> D;
    REP(i, D) {
      cin >> p[i];
      dcount[p[i]]++;
    }

    int res = 1000;
    FOR(tr, 1, 1001) {
      int sm = 0;
      FOR(i, tr, 1001) {
        if(dcount[i] != 0) {
          int q = i/tr;
          if(i%tr == 0) sm += dcount[i]*(q-1);
          else sm += dcount[i]*q;
        }
      }
      res = min(res, sm+tr);
    }



    cout << res << endl;
  }
}
