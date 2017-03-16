#include <iostream>
#include <cstring>
#include <sys/stat.h>

using namespace std;

int64_t reverse(int64_t C) {
   int64_t R = 0;
   while (C) {
      R *= 10;
      R += (C % 10);
      C /= 10;
   }
   return R;
}

int64_t solve(int64_t C, int64_t N) {
   int64_t count = 1;
   while (C < N) {
      // find the last jump
      int64_t trial = 0;
      while (true) {
         int64_t R = reverse(C);
         if (R <= C || R > N) break;
         ++trial; ++C;
      }
      if (trial) {
         count += trial;
         C = reverse(--C);
      }
      else { ++C; ++count; }
   }
   return count;
}

int main() {
   int64_t T; cin >> T;
   for (int64_t i = 1; i <= T; ++i) {
      int64_t N; cin >> N;
      cout << "Case #" << i << ": " << solve(1, N) << endl;
   }
   return 0;
}

