#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); k++)
#define FORE(k,a,b) for(typeof(a) k=(a); k <= (b); k++)
#define REP(k,a) for(int k=0; k < (a); k++)

#define SZ size()
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define EXIST(s,e) ((s).find(e)!=(s).end())

#define dump(x) cerr << #x << ": " << (x) << endl;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int INF = 1000 * 1000 * 1000;
const double EPS = 1e-10;

double ps[100000];
double ex[111111];

int main()
{
  int T;
  cin >> T;
  REP(ncase, T) {
    int A, B;
    cin >> A >> B;
    REP(i, A) cin >> ps[i];
    
    REP(i, 111111) ex[i] = 0;
    
    for(int mask = 0; mask < (1 << A); mask++) {
      double p = 1;
      REP(i, A) {
        if((mask >> i) & 1) p *= 1 - ps[i];
        else p *= ps[i];
      }
      //cerr << mask << ", prob = " << p << endl;

      // keep typing
      if(mask == 0) ex[0] += p * (B - A + 1);
      else ex[0] += p * (B - A + 1 + B + 1);

      // press bs n times
      REP(i, A) {
        int leftmost = INF;
        REP(j, A) {
          if((mask >> j) & 1) { leftmost = j; break; }
        }

        // cerr << mask << ":" << i << ":" << leftmost << ": ";
        // if(i + 1 >= A - leftmost) cerr << ((i+1)*2 + B - A + 1);
        // else cerr << ((i+1)*2 + B - A + 1 + B + 1);
        // cerr << endl;
        
        if(i + 1 >= A - leftmost) ex[i+1] += p * ((i+1)*2 + B - A + 1);
        else ex[i+1] += p * ((i+1)*2 + B - A + 1 + B + 1);
      }

      // enter right away
      ex[A+1] += p * (1 + B + 1);
    }
    
    double res = INF;
    REP(i, A+2) {
      //cerr << "ex[" << i << "] = " << ex[i] << endl;
      res = min(res, ex[i]);
    }

    //cout << "Case #" << (ncase+1) << ": " << (res) << endl;
    printf("Case #%d: %.6f\n", ncase+1, res);
  }
  
  return 0;
}
