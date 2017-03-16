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
int A, B;

// 2*10^6*6

int power(int x, int y) {
  int res = 1;
  while(y > 0) { res *= x; y--; }
  return res;
}

int ndigits(int x) {
  int res = 0;
  while(x > 0) {
    x /= 10;
    res++;
  }
  return res;
}

int rotate(int x, int nd) {
  int y = x % 10;
  return x / 10 + y * power(10, nd-1);
}

set<PII> pairs;
bool used[2222222];

int main()
{
  cin >> T;
  REP(ncase, T) {
    cin >> A >> B;
    pairs.clear();
    FORE(i, A, B) used[i] = false;
    
    ll res = 0;
    FORE(i, A, B) {
      if(used[i]) continue;
      //dump(i);
      int nd = ndigits(i);
      set<int> nums;

      nums.insert(i); 
      used[i] = true;
      int n = i;
      REP(j, nd-1) {
        n = rotate(n, nd);
        if(A <= n && n <= B) { 
          nums.insert(n);
          used[n] = true;
        }
      }

      res += nums.size() * (nums.size() - 1) / 2;
    }

    printf("Case #%d: %lld\n", ncase+1, res);
  }
  
  return 0;
}
