#include <iostream>
#include <vector>

using namespace std;

int main() {
   int T; cin >> T;
   for (int i = 1; i <= T; ++i) {
      int N; cin >> N;
      vector<bool> exist(2501, false);
      for (int j = 0, k = (2 * N) - 1; j < k; ++j) {
         for (int x = 0; x < N; ++x) {
            int value; cin >> value;
            exist[value] = !exist[value];
         }
      }
      cout << "Case #" << i << ":";
      for (int j = 1; j < 2501; ++j)
         if (exist[j]) cout << " " << j;
      cout << endl;
   }
   return 0;
}

