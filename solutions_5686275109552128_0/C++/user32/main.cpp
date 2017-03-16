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
    freopen("../Console/B-small-attempt2.in", "rb", stdin);
    freopen("../Console/B-small-attempt2.out", "wb", stdout);
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
    sort(A.begin(), A.end());

    map<vector<int>, int> H;
    queue<vector<int>> Q;
    H[A] = 0;
    Q.push(move(A));

    while (!Q.empty()) {
      vector<int> v = move(Q.front());
      Q.pop();

      int d = H[v];

      {
        vector<int> u = v;
        for (int& n : u) {
          --n;
        }
        u.erase(remove(u.begin(), u.end(), 0), u.end());
        if (!H.count(u)) {
          H[u] = d + 1;
          Q.push(move(u));
        }
      }

      {
        for (int i = 0; i < v.size(); ++i) {
          for (int mv = 1; mv < v[i]; ++mv) {
            vector<int> u = v;
            u[i] = mv;
            u.push_back(v[i] - mv);
            sort(u.begin(), u.end());
            if (!H.count(u)) {
              H[u] = d + 1;
              Q.push(move(u));
            }
          }
        }
      }
    }

    cout << "Case #" << tc + 1 << ": " << H[vector<int>()] << endl;
  }

  return 0;
}
