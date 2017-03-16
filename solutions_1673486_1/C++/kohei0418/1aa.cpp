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

double ps[111111];
double ex[111111];

int main()
{
  int T;
  cin >> T;
  REP(ncase, T) {
    int A, B;
    cin >> A >> B;
    REP(i, A) cin >> ps[i];
    ps[A] = 0;
    
    REP(i, 111111) ex[i] = 0;

    for(int leftmost = 0; leftmost <= A; leftmost++) {
      double p = 1;
      REP(i, leftmost) p *= ps[i];
      p *= 1 - ps[leftmost];

      //cerr << "lm: " << leftmost << ", p: " << p << endl;
      
      // keep typing
      if(leftmost == A) ex[0] += p * (B - A + 1);
      else ex[0] += p * (B - A + 1 + B + 1);

      // press bs i+1 times
      REP(i, A) {
        if(i + 1 >= A - leftmost) ex[i+1] += p * ((i+1)*2 + B - A + 1);
        else ex[i+1] += p * ((i+1)*2 + B - A + 1 + B + 1);
      }

      // enter right away
       ex[A+1] += p * (1 + B + 1);
    }
    
    double res = INF;
    REP(i, A+2) {
      //cerr << "ex[" << i << "]=" << ex[i] << endl;
      res = min(res, ex[i]);
    }

    printf("Case #%d: %.6f\n", ncase+1, res);
  }
  
  return 0;
}
