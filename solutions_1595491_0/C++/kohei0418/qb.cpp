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

int T;
int N;
int S;
int p;
int t[100];

// a, a, a
// a, a, a+1
// a, a, a+2
// a, a+1, a+1
// a, a+1, a+2
// a, a+2, a+2 => a+1, a+1, a+2

int main()
{
  cin >> T;
  REP(ncase, T) {
    cin >> N >> S >> p;

    int res = 0, surpr = 0;
    REP(i, N) {
      int score;
      cin >> score;
      if(score/3 >= p) res++;
      else if(score%3 >= 1 && score/3 + 1 >= p) res++; // a, a, a+1|a, a+1, a+1: not surprising
      else if(score%3 == 2 && score/3 + 2 >= p) surpr++; // a, a, a+2: surprising
      else if(score >= 3 && score%3 == 0 && (score-3)/3 + 2 >= p) surpr++; // a, a+1, a+2: surprising
      // cerr << i << ": " << res << ", " << surpr << endl;
    }

    printf("Case #%d: %d\n", ncase+1, res + min(S, surpr));
  }
  
  return 0;
}
