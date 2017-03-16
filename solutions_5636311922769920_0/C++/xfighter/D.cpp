#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int64_t K, C, S;
    cin >> K >> C >> S;
    cout << "Case #" << t + 1 << ":";
    for (int i = 1; i <= K; ++i) {
      cout << " " << i;
    }
    cout << endl;
  }
}
