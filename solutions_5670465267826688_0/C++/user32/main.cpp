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

const int kMulTable[][4] = {
    {1, 2, 3, 4},
    {2, -1, 4, -3},
    {3, -4, -1, 2},
    {4, 3, -2, -1},
};

inline int Mul(int a, int b) {
  if (a < 0 && b < 0) {
    return Mul(-a, -b);
  }
  if (a < 0) {
    return -Mul(-a, b);
  }
  if (b < 0) {
    return -Mul(a, -b);
  }

  return kMulTable[a - 1][b - 1];
}

int SegmentMul(int i, int j, const vector<int>* P) {
  if (i == 0) {
    return P[5][j];
  }

  for (int k = 0; k <= 8; ++k) {
    if (k == 4) {
      continue;
    }

    if (P[k][i - 1] == 1) {
      return P[k][j];
    }
  }

  assert(false);
  return -1;
}

int main() {
//  freopen("../Console/1.txt", "rb", stdin);
    freopen("../Console/C-small-attempt0.in", "rb", stdin);
    freopen("../Console/C-small-attempt0.out", "wb", stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int tc = 0; tc < T; ++tc) {
    int L;
    int64_t X;
    cin >> L >> X;

    string line;
    cin >> line;

    vector<int> A(L);
    for (int i = 0; i < L; ++i) {
      switch (line[i]) {
        case 'i':
          A[i] = 2;
          break;
        case 'j':
          A[i] = 3;
          break;
        case 'k':
          A[i] = 4;
          break;
        default:
          assert(false);
      }
    }

    vector<int> B;
    B.reserve(L * X);
    for (int i = 0; i < X; ++i) {
      copy(A.begin(), A.end(), back_inserter(B));
    }
    int N = B.size();

    vector<int> P[9];
    for (int i = 0; i <= 8; ++i) {
      if (i == 4) {
        continue;
      }

      P[i].resize(N);
      P[i][0] = Mul(i - 4, B[0]);
      for (int j = 1; j < N; ++j) {
        P[i][j] = Mul(P[i][j - 1], B[j]);
      }
    }

    const char* result = "NO";

    deque<int> cand[9];
    for (int i = 1; i < N; ++i) {
      if (SegmentMul(i, N - 1, P) == 4) {
        cand[4 + SegmentMul(0, i - 1, P)].push_back(i - 1);
      }
    }

    for (int i = 0; i < N; ++i) {
      for (deque<int>& c : cand) {
        while (!c.empty() && c.front() <= i) {
          c.pop_front();
        }
      }

      if (SegmentMul(0, i, P) != 2) {
        continue;
      }

      bool found = false;
      for (const deque<int>& c : cand) {
        if (c.empty()) {
          continue;
        }

        assert(c.front() > i);
        if (SegmentMul(i + 1, c.front(), P) == 3) {
          found = true;
          break;
        }
      }

      if (found) {
        result = "YES";
        break;
      }
    }

    cout << "Case #" << tc + 1 << ": " << result << endl;
  }

  return 0;
}
