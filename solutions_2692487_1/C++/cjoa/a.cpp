#include <iostream>

#include <algorithm>

using namespace std;

int A, N;
int B[104];

#define INF 1000000000LL

long long eat(int K) {
   long long res = 0;
   long long a = A;
   for (int k = 0; k < K; ++k) {
      // try to eat B[k]
      while (B[k] >= a) {
         a += (a-1);
         ++res;
      }
      a += B[k];
   }
   return res;
}

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      cin >> A >> N;
      for (int i = 0; i < N; ++i)
         cin >> B[i];
      long long res = N;
      if (A > 1) {
         sort(B, B+N);
         for (int K = 1; K <= N; ++K) {
            long long cur = eat(K) + N - K;
            if (res > cur) {
               res = cur;
            // cerr << "K = " << K << endl;
            }
         }
      }
      cout << "Case #" << tc << ": " << res << endl;
   }

   return 0;
}
