#include <iostream>
#include <queue>
#include <vector>

const int N = 1000000;

int Reverse(int x) {
  int y = 0;
  while (x > 0) {
    y = y * 10 + x % 10;
    x /= 10;
  }
  return y;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::vector<int> steps(N + 1);
  std::queue<int> Q;
  steps[1] = 1;
  Q.push(1);
  while (Q.size()) {
    int x = Q.front();
    Q.pop();
    int y = x + 1;
    if (y <= N && steps[y] == 0) {
      steps[y] = steps[x] + 1;
      Q.push(y);
    }
    int z = Reverse(x);
    if (z <= N && steps[z] == 0) {
      steps[z] = steps[x] + 1;
      Q.push(z);
    }
  }
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    std::cin >> n;
    std::cout << "Case #" << i + 1 << ": " << steps[n] << std::endl;
  }
}
