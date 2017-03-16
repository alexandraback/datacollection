#include <iostream>
using namespace std;
typedef long long LL;

//*******************
//*******************

LL rev(LL N) {
   LL res = 0;
   while(N > 0) {
      res = res * 10 + N % 10;
      N /= 10;
   } 
   return res;
}

LL solve(LL N) {
   LL result = 1;
   while(N > 1) {
      cerr << N << endl;
      LL k = N % 10;
      if(k > 1) {
         result += k - 1;
         N -= k - 1;
      }
      else if(k == 0){
         result += 9;
         N -= 9;
      }
      if(N > rev(N)) {
         N = rev(N);
         ++result;
         if(N % 10 == 1) {
            --N;
            ++result;
         }
      }
      else if(N != 1){
         N -= 10;
         result += 10;
      }
   }
   return result;
}

int main() {
   ios::sync_with_stdio(false);
   int T;
   cin >> T;
   for(int i = 1; i <= T; ++i) {
      LL N;
      cin >> N;
      cout << "Case #" << i << ": " << solve(N) << endl;
   }
   return 0;
}