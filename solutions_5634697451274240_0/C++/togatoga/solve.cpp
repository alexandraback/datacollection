#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <functional>
#include <limits.h>
#include <bitset>

#include <tuple>
#include <unordered_map>

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int INF = 1 << 29;
const double EPS = 1e-9;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int T;
int main() {
  cin >> T;
  for (int case_id = 1; case_id <= T; case_id++) {
    string tmp;
    cin >> tmp;
    int res = 0;
    while (true) {
      bool minus = false;
      int target_index = -1;
      int mins_index = -1;
      for (int j = tmp.size() - 1; j >= 0; j--) {
        if (tmp[j] == '-') {
          minus = true;
          if (mins_index == -1) {
            mins_index = j;
          }
        } else {
          if (minus) {
            target_index = j;
            break;
          }
        }
      }
      if (not minus and target_index == -1)
        break;
      res++;
      if (target_index != -1) {
        for (int j = 0; j <= target_index; j++) {
          tmp[j] = tmp[j] == '-' ? '+' : '-';
        }
      } else {
        for (int j = 0; j <= mins_index; j++) {
          tmp[j] = tmp[j] == '-' ? '+' : '-';
        }
      }
    }
    printf("Case #%d: %d\n", case_id, res);
  }
  return 0;
}