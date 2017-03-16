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

int main(void) {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int ncase = 1; ncase <= T; ncase++) {
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    cout << "Case #" << ncase << ": " << endl;
    bool found = false;
    for (int i = 1; i <= N && !found; i++) {
      for (int k = 1; i+k <= N && !found; k++) {
        vector<int> enabled(N, 0);
        for (int j = 0; j < k; j++) enabled[N-j-1] = 1;
        for (int j = 0; j < i; j++) enabled[N-k-j-1] = 2;

        do {
          int a = 0;
          int b = 0;
          for (int i = 0; i < N; i++) {
            if (enabled[i] == 1) {
              a += v[i];
            } else if (enabled[i] == 2) {
              b += v[i];
            }
          }

          if (a == b) {
            for (int i = 0; i < N; i++) {
              if (enabled[i] == 1) {
                cout << v[i] << ' ';
              }
            }
            cout << endl;

            for (int i = 0; i < N; i++) {
              if (enabled[i] == 2) {
                cout << v[i] << ' ';
              }
            }
            found = true;
            break;
          }
        } while (next_permutation(enabled.begin(), enabled.end()));
      }
    }
    if (!found) {
      cout << "Impossible";
    }
    cout << endl;
  }
  return 0;
}
