#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int R, N, M, K;

int main() {
  int T;
  cin >> T;
  cout << "Case #1:" << endl;
  cin >> R >> N >> M >> K;
  for (int r = 1; r <= R; ++r) {
    int cnt_3 = 0, cnt_5 = 0;

    for (int a = 1; a <= 7; ++a) {
      int x;
      cin >> x;
      int c_3 = 0;
      while (x % 3 == 0) {
        x /= 3;
        ++c_3;
      }
      cnt_3 = max(cnt_3, c_3);
      int c_5 = 0;
      while (x % 5 == 0) {
        x /= 5;
        ++c_5;
      }
      cnt_5 = max(cnt_5, c_5);
    }
    for (int i = 1; i <= cnt_3; ++i) {
      printf("3");
    }
    for (int i = 1; i <= cnt_5; ++i) {
      printf("5");
    }
    for (int i = 1; i <= 3 - cnt_3 - cnt_5; ++i) {
      printf("2");
    }
    printf("\n");
  }
  return 0;
}
