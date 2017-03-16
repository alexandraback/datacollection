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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, char> pc;
typedef long long ll;

const int N = 5;

int J, P, S, K;
bool tripleWorn[N][N][N];
int pairWornTimes[N][N][N];

typedef struct comb {
  int a, b, c;
  comb(int aa, int bb, int cc): a(aa), b(bb), c(cc) {}
};

bool isOkayComb(const comb& cur) {
  if (!tripleWorn[cur.a][cur.b][cur.c]
   && pairWornTimes[cur.a][cur.b][N - 1] < K
   && pairWornTimes[cur.a][N - 1][cur.c] < K
   && pairWornTimes[N - 1][cur.b][cur.c] < K
  ) {
    return true;
  }
  return false;
}

void fixCombOcc(const comb& cur, int add, bool val) {
  tripleWorn[cur.a][cur.b][cur.c] = val;
  pairWornTimes[cur.a][cur.b][N - 1] += add;
  pairWornTimes[cur.a][N - 1][cur.c] += add;
  pairWornTimes[N - 1][cur.b][cur.c] += add;
}

vector< comb > solve(const comb& lastComb) {
  vector< comb > ret;
  for (int i = 0; i < J; i++) {
    if (i < lastComb.a) continue;
    for (int j = 0; j < P; j++) {
      if (i == lastComb.a && j < lastComb.b) continue;
      if (pairWornTimes[i][j][N - 1] == K) continue;
      for (int k = 0; k < S; k++) {
        if (i == lastComb.a && j == lastComb.b && k < lastComb.c) continue;
        comb cur = comb(i, j, k);
        if (isOkayComb(cur)) {
          fixCombOcc(cur, 1, true);
          vector< comb > ans = solve(cur);
          if (ans.size() + 1 > ret.size()) {
            ret = ans;
            ret.push_back(cur);
          }
          fixCombOcc(cur, -1, false);
        }
      }
    }
  }
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("in.out", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    cin >> J >> P >> S >> K;
    cout << "Case #" << t << ": ";
    memset(tripleWorn, false, sizeof tripleWorn);
    memset(pairWornTimes, 0, sizeof pairWornTimes);

    if (J == P && P == S && S == 3 && K >= 3) {
      cout << "27\n3 3 3\n3 3 2\n3 3 1\n3 2 3\n3 2 2\n3 2 1\n3 1 3\n3 1 2\n3 1 1\n2 3 3\n2 3 2\n2 3 1\n2 2 3\n2 2 2\n2 2 1\n2 1 3\n2 1 2\n2 1 1\n1 3 3\n1 3 2\n1 3 1\n1 2 3\n1 2 2\n1 2 1\n1 1 3\n1 1 2\n1 1 1\n"  << endl;
    } else {
      vector< comb > ans = solve(comb(-1, -1, -1));
      cout << ans.size() << endl;
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].a + 1 << " " << ans[i].b + 1 << " " << ans[i].c + 1 << endl;
      }
    }
  }

  return 0;
}
