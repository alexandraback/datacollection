#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
  freopen("../Console/B-large.in", "rb", stdin);
  freopen("../Console/B-large.out", "wb", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    int D;
    cin >> D;

    vector<int> A(D);
    for (int& a : A) {
      cin >> a;
    }

    int mx = *max_element(A.begin(), A.end());
    int answer = mx;
    for (int reper = 1; reper <= mx; ++reper) {
      int sum = 0;
      for (int a : A) {
        if (a <= reper) {
          continue;
        }

        int turns = (a + reper - 1) / reper - 1;
        sum += turns;
      }

      answer = min(answer, reper + sum);
    }

    cout << "Case #" << tc + 1 << ": " << answer << endl;
  }

  return 0;
}
