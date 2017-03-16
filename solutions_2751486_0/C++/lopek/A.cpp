#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <functional>
#include <bitset>
#include <list>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, p, k) for(int i = (p); i <= (k); ++i)
#define FORD(i, p, k) for(int i = (p); i >= (k); --i)
#define FOREACH(x,Z) for(__typeof((Z).begin()) x=(Z).begin();x!=(Z).end();++x)

#define mp make_pair
#define pb push_back
#define st first
#define nd second

int n;
char S[1000009];
bool isv[10000];

int v[10000009];
long long solve() {
  int l = strlen(S);
  v[0] = 0;
  REP(i, l) {
    if (isv[S[i]]) break;
    v[0] = i + 1;
  }
  
  REP(i, l) {
    if (i == 0) continue;
    v[i] = v[i - 1] - 1;
    if (v[i] == -1) {
      v[i] = 0;
      FOR(j, i, l - 1) {
        if (isv[S[j]]) break;
        v[i] = j - i + 1;
      }
    }
  }
  
  long long res = 0;
  int k = 0;
  
  REP(p, l) {
    while (k < p || (k < l && v[k] < n)) k++;
    if (k == l) break;
    int kk = k + n - 1;
    res += l - kk;
  }
  return res;
}

int main() {
  isv['a'] = isv['e'] = isv['i'] = isv['o'] = isv['u'] = true;
  
  int Z; scanf("%d", &Z);
  FOR(t, 1, Z) {
    scanf("%s %d", S, &n);
    printf("Case #%d: %lld\n", t, solve());
  }
  return 0;
}
