#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <set>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int N, M;
ll An[101];
ll Bn[101];
int At[101];
int Bt[101];

ll dfs(int n, int m, int ptype, ll pleft) {
  int type = At[n];
  ll left = An[n];

  if (n == 2) {
    ll curr = 0;
    if (ptype == type) {
      curr += min(pleft, left);
      left -= min(pleft, left);
    }

    for (; m < M && left > 0; m++) {
      if (Bt[m] == type) {
        curr += min(Bn[m], left);
        left -= min(Bn[m], left);
      }
    }
    return curr;
  } else {
    ll ret = dfs(n+1, m, ptype, pleft);
    ll curr = 0;
    if (ptype == type) {
      curr += min(pleft, left);
      left -= min(pleft, left);
    }

    for (; m < M && left > 0; m++) {
      if (Bt[m] == type) {
        ll made = min(Bn[m], left);
        curr += made;
        left -= made;
        if (left == 0) {
          ret = max(ret, curr + dfs(n+1, m+1, Bt[m], Bn[m]-made));
        } else {
          ret = max(ret, curr + dfs(n+1, m+1, 0, 0));
        }
      } else {
        ret = max(ret, curr + dfs(n+1, m, 0, 0));
      }
    }
    return ret;
  }
}

void calc(void) {
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> An[i] >> At[i];
  for (int i = 0; i < M; i++) cin >> Bn[i] >> Bt[i];

  cout << dfs(0, 0, 0, 0);
}

int main(void) {
  ios::sync_with_stdio(false);
  int T; cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    calc();
    cout << endl;
  }
  return 0;
}

