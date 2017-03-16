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

int a[1111], b[1111];
bool ac[1111], bc[1111];

int main()
{
  int T;
  cin >> T;
  REP(ncase, T) {
    int N;
    cin >> N;
    REP(i, N) {
      cin >> a[i] >> b[i];
      ac[i] = false; bc[i] = false;
    }
    
    int stars = 0, res = 0;
    while(true) {
      bool updated = false;
      REP(i, N) {
        if(!bc[i] && b[i] <= stars) {
          if(!ac[i]) stars += 2;
          else stars++;
          res++;
          ac[i] = bc[i] = updated = true;
          break;
        }
      }

      if(!updated) {
        int max2stars = -1, cand = -1;
        REP(i, N) {
          if(!ac[i] && a[i] <= stars) {
            if(max2stars < b[i]) {
              cand = i;
              max2stars = b[i];
            }
          }
        }
        if(cand != -1) {
          ac[cand] = true;
          stars++;
          res++;
          updated = true;
        }
      }

      if(!updated) break;
    }

    // check
    bool ok = true;
    REP(i, N) {
      if(!ac[i] || !bc[i]) { ok = false; break; }
    }

    printf("Case #%d: ", ncase+1);
    if(ok) printf("%d\n", res);
    else printf("Too Bad\n");
  }
  
  return 0;
}
