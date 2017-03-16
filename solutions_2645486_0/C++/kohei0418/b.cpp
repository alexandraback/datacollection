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

using namespace std;

#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); k++)
#define FORE(k,a,b) for(typeof(a) k=(a); k <= (b); k++)
#define REP(k,a) for(int k=0; k < (a); k++)

#define SZ(x) ((int)((x).size()))
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

const int INF = 1e+9;
const double EPS = 1e-10;
const double PI = acos(-1.0);

int dfs(int idx, int curr, int E, int R, int N, int v[]) {
  if(idx == N) return 0;
  
  int mv = 0;
  for(int spend = 0; spend <= curr; spend++) {
    mv = max(mv, spend * v[idx] + dfs(idx+1, min(E, curr-spend+R), E, R, N, v));
  }

  return mv;
}

int main()
{
  int T;
  cin >> T;
  REP(casenum, T) {
    int E, R, N;
    cin >> E >> R >> N;
    int v[N];
    REP(i, N) cin >> v[i];
    
    int res = dfs(0, E, E, R, N, v);
    printf("Case #%d: %d\n", casenum + 1, res);
  }
  
  return 0;
}
