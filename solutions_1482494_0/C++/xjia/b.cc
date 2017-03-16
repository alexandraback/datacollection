#include <iostream>
#include <cstdio>
using namespace std;

int a[1010], b[1010];
int earned_stars[1010];

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
      cin >> a[i] >> b[i];
      earned_stars[i] = 0;
    }
    int star = 0, play = 0, full = 0;
    while (true) {
    next:
      for (int i = 1; i <= N; i++) {
        if (earned_stars[i] == 0 && star >= b[i]) {
          // cout << "play level " << i << " star 2 (+2)" << endl;
          play++;
          star += 2;
          earned_stars[i] = 2;
          full++;
          goto next;
        }
      }
      for (int i = 1; i <= N; i++) {
        if (earned_stars[i] == 1 && star >= b[i]) {
          // cout << "play level " << i << " star 2 (+1)" << endl;
          play++;
          star += 1;
          earned_stars[i] = 2;
          full++;
          goto next;
        }
      }
      int j = -1;
      for (int i = 1; i <= N; i++) {
        if (earned_stars[i] == 0 && star >= a[i]) {
          if (j == -1 || b[i] > b[j]) {
            j = i;
          }
        }
      }
      if (j != -1) {
        // cout << "play level " << j << " star 1" << endl;
        play++;
        star += 1;
        earned_stars[j] = 1;
        goto next;
      }
      // for (int i = 1; i <= N; i++) {
      //   if (earned_stars[i] == 0 && star >= a[i]) {
      //     cout << "play level " << i << " star 1" << endl;
      //     play++;
      //     star += 1;
      //     earned_stars[i] = 1;
      //     goto next;
      //   }
      // }
      break;
    }
    // cout << "[star=" << star << ",play=" << play << "]" << endl;
    cout << "Case #" << t << ": ";
    if (full < N) {
      cout << "Too Bad" << endl;
    } else {
      cout << play << endl;
    }
  }
  return 0;
}
