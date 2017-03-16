#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <set>
#include <map>
#include <iomanip>

#define fr(i,n) for(i=0;i<(int)(n);i++)
#define fit(a,b) for(typeof(b.begin()) a = b.begin(); a != b.end(); a++)
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define SZ(u) ((int)u.size())
#define WT(x) cout << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int,int> p2;
typedef vector<int> vi;
typedef long double ld;

int E, R, N;
vector<ll> V;
ll proc() {
  ll res = 0;
  if (R >= E) {
    int i;
    for (i = N - 1; i >= 1; i--) res += V[i] * E;
    return res;
  }

  int x = E / R;
  ll adv = E - x * R;
  ll low = R - adv;
  map<ll, int> counter;
  int i;
  for (i = N - 1; i >= 1; i--) {
    if (counter.find(V[i]) == counter.end()) counter[V[i]] = 0;
    counter[V[i]]++;
    ll cri = counter.rbegin()->F;
    res += cri * adv;
    
    if (i + x < SZ(V)) {
      counter[V[i + x]]--;
      if (counter[V[i+x]] == 0) counter.erase(V[i+x]);
    }
    cri = counter.rbegin()->F;
    res += cri * low;
  }

  return res;
}
int main() {
  int tc, cn = 0;
  scanf("%d", &tc);
  while (cn++ < tc) {
    V.clear();
    scanf("%d%d%d", &E, &R, &N);
    int i, x;
    fr (i, N) {
      scanf("%d", &x);
      V.pb(x);
    }
    
    ll res = proc();
    ll start, end = E, cri = 0;
    fr (i, N) {
      start = max(0LL, end - R);
      cri = max(V[i], cri);
      res += (end - start) * cri;
      if (start == 0) break;

      end = start;
    }
    res += start * cri;
    cout << "Case #" << cn << ": " << res << endl;
  }
  return 0;
}
