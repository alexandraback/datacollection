#include <iostream>
#include <vector>

using namespace std;

struct Block {
  bool first;
  double value;

  bool operator<(const Block& b) const {
    return value > b.value;
  }
};

int main(int argc, char* argv[]) {
  int T;
  cin >> T;
  for (int c = 1; c <= T; c++) {
    int N;
    cin >> N;
    vector<Block> B;
    for (int i = 0; i < N; i++) {
      double v;
      cin >> v;
      B.push_back({true, v});
    }
    for (int i = 0; i < N; i++) {
      double v;
      cin >> v;
      B.push_back({false, v});
    }
    sort(B.begin(), B.end());
    int ans1 = 0;
    int cover = 0;
    for (const auto& b : B) {
      //cout << b.first << " " << b.value << endl;
      if (b.first) {
        if (cover > 0)
          cover--;
        else
          ans1++;
      } else {
        cover++;
      }
    }

    int ans2 = 0;
    int below = 0;
    for (int i = B.size() - 1; i >= 0; i--) {
      if (B[i].first) {
        if (below > 0) {
          ans2++;
          below--;
        }
      } else {
        below++;
      }
    }
    
    printf("Case #%d: %d %d\n", c, ans2, ans1);
  }
}
