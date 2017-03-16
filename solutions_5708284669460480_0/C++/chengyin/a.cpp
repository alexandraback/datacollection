#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

string cur;
int numOfAppear;
int maxOfAppear;

void enumerate(string keys, string target, int S, int index) {
   if (index == S) {
      //cout << "index = " << index << ", S = " << S << ", str = " << cur << endl;
      // numOfAppear the number of 'target' in cur
      int k = target.size(), appear = 0;
      for (int start = 0, end = S - k, j; start <= end; ++start) {
         j = 0; for (int i = start; j < k; ++i, ++j) if (target[j] != cur[i]) break;
         if (j == k) ++appear;
      }
      if (maxOfAppear < appear) maxOfAppear = appear;
      numOfAppear += appear;
   }
   else {
      for (int i = 0; i < keys.size(); ++i) {
         cur[index] = keys[i];
         enumerate(keys, target, S, 1 + index);
      }
   }
}

double solve(string keys, string target, int S) {
   // enumerate-based
   cur = string(' ', S);
   numOfAppear = 0; maxOfAppear = 0;
   enumerate(keys, target, S, 0);
   //cout << "numOfAppear = " << numOfAppear << endl;
   //cout << "maxOfAppear = " << maxOfAppear << endl;
   return (double)(maxOfAppear) - ((double)(numOfAppear) / (double)(pow((double)(keys.size()), (double)(S))));
}

int main() {
   int T; cin >> T;
   for (int i = 1; i <= T; ++i) {
      int K, L, S; cin >> K >> L >> S;
      string keys; cin >> keys;
      string target; cin >> target;
      cout << "Case #" << i << ": " << setprecision(7) << fixed << solve(keys, target, S) << endl;
   }
   return 0;
}

