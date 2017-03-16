#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class obj {
 public:
   int a, b;
   bool operator < (const obj& o) const {
      return a > o.a;
   }
};

int main() {
   int total;
   cin >> total;
   for (int totalCount = 0; totalCount < total; ++totalCount) {
      int N;
      cin >> N;
      int haha = 2 * N;
      int** stage = new int*[N];
      bool** done = new bool*[N];
      vector<obj> o;
      bool bad = false;
      for (int i = 0; i < N; ++i) {
         stage[i] = new int[2];
         done[i] = new bool[2];
         done[i][0] = done[i][1] = stage[i][0] = stage[i][1] = 0;
         cin >> stage[i][0] >> stage[i][1];
         if (stage[i][0] > haha || stage[i][1] > haha) {
            bad = true;
         }
         obj tmp;
         tmp.a = stage[i][1];
         tmp.b = i;
         o.push_back(tmp);
      }
      sort(o.begin(), o.end());
/*
      for (int i = 0; i < N; ++i) {
         cout << o[i].a << " ";
      }
      cout << endl;
*/
      int need = 0;
      int hold = 0;
      for (int i = 0;; ++i) {
         if (bad) {
            break;
         }
         int min;
         bool finish = true;
         do {
            min = haha;
            for (int j = 0; j < N; ++j) {
               if (hold >= stage[j][1] && !done[j][1]) {
                  if (done[j][0]) {
                     hold += 1;
                  } else {
                     hold += 2;
                  }
                  need += 1;
                  done[j][0] = true;
                  done[j][1] = true;
               } else if (hold < stage[j][1] && !done[j][1] && stage[j][1] < min) {
                  min = stage[j][1];
               }
            }
            finish = true;
            for (int j = 0; j < N; ++j) {
               finish &= done[j][1];
            }
         } while (hold >= min && !finish);
         if (finish) {
            break;
         }
//         cout << min << endl;
//         cout << need << " " << hold << endl;
         do {
            int count = 0;
            for (int j = 0; j < N; ++j) {
               if (hold == min) {
                  break;
               }
               int idx = o[j].b;
               if (!done[idx][0] && hold >= stage[idx][0]) {
                  ++need;
                  ++hold;
                  done[idx][0] = true;
                  ++count;
               }
            }
            if (count == 0) {
               break;
            }
         } while (hold < min);
         if(hold < min) {
            bad = true;
         }
      }
      if (bad) {
         printf("Case #%d: Too Bad\n", totalCount + 1);
      } else {
         printf("Case #%d: %d\n", totalCount + 1, need);
      }
      for (int i = 0; i < N; ++i) {
         delete[] done[i];
         delete[] stage[i];
      }
      delete[] done;
      delete[] stage;
   }
}
