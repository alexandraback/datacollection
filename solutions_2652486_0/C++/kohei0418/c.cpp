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

bool satisfy(int K, int p[], int N, int nums[]) {
  REP(i, K) {
    int prod = p[i];
    
    REP(j, N) {
      if(prod % nums[j] == 0) {
        prod /= nums[j];
      }
    }
    
    if(prod != 1) return false;
  }

  return true;
}

int main()
{
  int T;
  cin >> T;
  
  int R, N, M, K;
  cin >> R >> N >> M >> K;

  vector<string> res;

  srand(time(NULL));  
  REP(i, R) {
    int p[K];
    REP(k, K) cin >> p[k];

    int nums[N];
    do {
      REP(j, N) nums[j] = rand() % (M-1) + 2;
    } while(!satisfy(K, p, N, nums));

    stringstream ss;
    REP(j, N) ss << nums[j];
    res.push_back(ss.str());
  }

  printf("Case #1:\n");
  REP(i, res.size()) cout << res[i] << endl;
  
  return 0;
}
