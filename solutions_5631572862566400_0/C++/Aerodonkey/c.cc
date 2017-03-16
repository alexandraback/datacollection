#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Solver {
public:
  Solver(const std::vector<int>& F) : N(F.size()), F(F), V(F.size()), D(F.size()), BF(F.size()) {
    for (int i = 0; i < N; i++) {
      int f = F[i];
      BF[f].push_back(i);
    }
  }

  int Solve() {
    int band = 0;
    int circle = 0;
    for (int i = 0; i < N; i++) {
      if (V[i]) {
        continue;
      }
      V[i] = 1;
      int p = i;
      int number = 0;
      for (;;) {
        int f = F[p];
        if (F[f] == p) {
          // Find a pair
          int x = FindBack(p, f);
          int y = FindBack(f, p);
          band += x + y;
          break;
        }
        if (V[f] == 2) {
          break;
        }
        if (V[f] == 1) {
          int c = number - D[f] + 1;
          circle = std::max(circle, c);
          break;
        }
        D[f] = ++number;
        V[f] = 1;
        p = f;
      }
      for (int j = 0; j < N; j++) {
        if (V[j] == 1) {
          V[j] = 2;
        }
      }
    }
    return std::max(band, circle);
  }
private:
  int N;
  std::vector<int> F;
  std::vector<int> V;
  std::vector<int> D;
  std::vector<std::vector<int>> BF;

  int FindBack(int r, int b) {
    std::queue<int> Q;
    Q.push(r);
    V[r] = 1;
    int L = D[r] = 1;
    while (!Q.empty()) {
      int p = Q.front();
      Q.pop();
      for (int i : BF[p]) {
        if (i == b) {
          continue;
        }
        Q.push(i);
        V[i] = 1;
        L = D[i] = D[p] + 1;
      }
    }
    return L;
  }
};

int main() {
  int T;
  std::cin >> T;
  for (int i = 0; i < T; i++) {
    int N;
    std::cin >> N;
    std::vector<int> F(N);
    for (int j = 0; j < N; j++) {
      std::cin >> F[j];
      --F[j];
    }
    Solver S(F);
    int y = S.Solve();
    std::cout << "Case #" << i + 1 << ": " << y << std::endl;
  }
}
