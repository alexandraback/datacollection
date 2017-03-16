#include <iostream>
#include <vector>

using namespace std;

int T, B;
long long M;
vector<long long> ways;

long long getWays(int i) {
  if (ways[i] == -1) {
    ways[i] = 0;
    for (int j = i + 1; j < B; j++) {
      ways[i] += getWays(j);
    }
  }
  return ways[i];
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> B >> M;
    ways.assign(B, -1);
    ways[B - 1] = 1;
    cout << "Case #" << t << ": ";
    if (getWays(0) < M) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      long long T = getWays(0);
      vector<int> res;
      for (int i = 0; i < B; i++) {
        if (i == B - 1)
          res.push_back(0);
        else
          res.push_back(((1 << B) - 1) - ((1 << (i + 1)) - 1));
      }
      for (int i = 1; i < B && T > M; i++) {
        if (T - getWays(i) >= M) {
          T -= getWays(i);
          res[0] = res[0] & ~(1 << i);
        }
      }
      cout << "POSSIBLE" << endl;
      for (int i = 0; i < B; i++) {
        for (int j = 0; j < B; j++) {
          if (res[i] & (1 << j))
            cout << 1;
          else
            cout << 0;
        }
        cout << endl;
      }
    }
  }
  return 0;
}
