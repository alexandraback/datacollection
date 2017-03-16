#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;
using namespace std::tr1;

typedef long long llong;
typedef pair<int, int> int2;
typedef pair<llong, llong> llong2;
#define foreach(v,c) for (typeof((c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define rep(i,n) for (int i = 0; i < (n); ++i)

int K, N;
const int maxn = 20;
int knum[1<<maxn][201];
bool valid[1<<maxn];
int keytoopen[maxn];
vector<int> keysinside[maxn];
int pred[1<<maxn];
int last[1<<maxn];
char order[1<<maxn][25];

void solve() {
  char thisorder[25];
  for (int m = 1; m < (1<<N); ++m) {
    int popcnt = 0;
    for (int j = 0; j < N; ++j)
      popcnt += !!(m&(1<<j));
    for (int j = 0; j < N; ++j) {
      if (!(m & (1<<j))) continue;
      int without = m & ~(1<<j);
      //cout << "without " << j << " = " << without << endl;
      if (valid[without] && knum[without][keytoopen[j]] > 0) {
        memcpy(thisorder, order[without], popcnt);
        thisorder[popcnt-1] = j;
        //if (j > 0) {
          //cout << "thisorder = ";
          //for (int i = 0; i < popcnt; ++i) cout << (int)thisorder[i] << " ";
          //cout << endl;
        //}
        if (valid[m] && !lexicographical_compare(thisorder, thisorder+popcnt,
                                                 order[m], order[m]+popcnt))
          continue;
        memcpy(order[m], thisorder, popcnt);
        //cout << "Found!" << endl;
        pred[m] = without;
        last[m] = j;
        valid[m] = 1;
        memcpy(knum[m], knum[without], sizeof(int)*201);
        knum[m][keytoopen[j]]--;
        foreach(it, keysinside[j])
          knum[m][*it]++;
      }
    }
  }
  int all = (1<<N)-1;
  if (!valid[all]) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  for (int i = 0; i < N; ++i) {
    if (i > 0) cout << " ";
    cout << (int)(order[all][i] + 1);
  }
  cout << endl;
  //stack<int> res;
  //for (int m = all; m; m = pred[m]) {
    //res.push(last[m]);
  //}
  //bool first = true;
  //while (!res.empty()) {
    //if (!first) cout << " ";
    //first = false;
    //cout << (res.top() + 1);
    //res.pop();
  //}
  //cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  for (int t_ = 1; t_ <= T; ++t_) {
    cout << "Case #" << t_ << ": ";
    cin >> K >> N;
    memset(knum, 0, sizeof knum);
    memset(valid, 0, sizeof valid);
    for (int i = 0; i < K; ++i) {
      int x; cin >> x;
      knum[0][x]++;
    }
    valid[0] = 1;
    last[0] = pred[0] = -1;
    for (int i = 0; i < N; ++i) {
      cin >> keytoopen[i];
      int ni; cin >> ni;
      keysinside[i].clear();
      for (int j = 0; j < ni; ++j) {
        int x; cin >> x;
        keysinside[i].push_back(x);
      }
    }
    solve();
  }
}
