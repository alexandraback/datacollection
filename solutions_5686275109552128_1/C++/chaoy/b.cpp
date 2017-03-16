#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int run() {
  int D;
  cin >> D;
  vector<int> plates;
  for (int i = 0; i < D; i++) {
    int p;
    cin >> p;
    plates.push_back(p);
  }
  int ret = 1000;
  for (int l = 1; l <= 1000; l++) {
    int split = 0;
    for (auto p : plates) {
      split += (p - 1) / l;
    }
    ret = min(ret, l + split);
  }
  return ret;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << run() << endl;
  }
  return 0;

}
