#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<(b)?(a=b,1):0)
#define chmin(a,b) (a>(b)?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

const int MAX_N = 200000;

struct SegSum {
  ll bit[MAX_N+1];               // nの最大+1必要
  int n;
  SegSum(int n) : n(n) {
    memset(bit, 0, sizeof(bit));
  }
  ll sum(int i) {              // [1,i]の和
    ll s = 0;
    while(i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
  ll sum(int a, int b) {      // [a,b]の和
    return sum(b)-sum(a-1);
  }
  void add(int i, ll x) {      // i(>=1)にx足す
    while(i <= n) {
      bit[i] += x;
      i += i & -i;
    }
  }
};

typedef pair<ll,int> pli;
ll sum[10001];

ll func(int tmp, priority_queue<pli> &Q, SegSum &bit, int &left) {
  ll res = 0;
  while(tmp > 0 && !Q.empty()) {
    ll u = Q.top().first;
    int id = Q.top().second;
    if (id < left) {
      Q.pop();
      continue;
    }
    left = id;
    ll num = sum[id] - bit.sum(id+1);
    if (num == 0) {
      Q.pop();
      continue;
    }
    if (tmp > num) {
      bit.add(id+1,num);
      res += num * u;
      tmp -= num;
    } else {
      bit.add(id+1,tmp);
      // cout << tmp << " " << u << endl;
      res += tmp * u;
      tmp = 0;
    }
  }
  return res;
}

ll v[10000];

int main() {
  int T;
  cin >> T;
  REP(cs,T) {
    int E,R,n;
    cin >> E >> R >> n;
    REP(i,n) {
      cin >> v[i];
    }
    sum[0] = E;
    REP(i,n) sum[i+1] = sum[i] + R;
    SegSum bit(n);
    priority_queue<pli> Q;
    ll ans = 0;
    int left = 0;
    REP(i,n) {
      ans += func(min(R,E),Q,bit,left);
      Q.push(pli(v[i],i));
    }
    ans += func(E,Q,bit,left);    
    printf("Case #%d: %lld\n", cs+1, ans);
  }

}
