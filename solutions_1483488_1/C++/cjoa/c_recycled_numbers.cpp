#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;

int digit_len(int x) {
   int res = 0;
   for (; x; x /= 10) ++res;
   return res;
}

const int p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int check(int n, int len, int B) {
   int m = n;
   vector<int> V;
   for (int t = len-1; t > 0; --t) {
      int d = (m % 10);
      m /= 10;
      m += p10[len-1] * d;
      if (n < m && m <= B && find(V.begin(), V.end(), m) == V.end()) {
      // fprintf(stderr, "%4d %4d\n", n, m);
         V.push_back(m);
      }
   }
   return V.size();
}

int main(int argc, char* argv[]) {
   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      int A, B;
      scanf("%d %d", &A, &B);
      int len = digit_len(A);
      int res = 0;
      for (int n = A; n <= B; ++n) {
         res += check(n, len, B);
      }
      printf("Case #%d: %d\n", tc, res);
   }
   return 0;
}
