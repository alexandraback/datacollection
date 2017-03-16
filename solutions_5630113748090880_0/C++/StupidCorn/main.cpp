#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;


int main(int, char**) {
   unsigned T = 0;
   cin >> T;

   for (unsigned t = 0; t < T; ++t) {
      unsigned N = 0;
      cin >> N;
      vector<unsigned> result;

      vector<unsigned> heights(2500);
      for (unsigned i = 0; i < 2 * N - 1; ++i) {
         for (unsigned j = 0; j < N; ++j) {
            unsigned h = 0;
            cin >> h;
            ++heights[h-1];
         }
      }

      for (unsigned i = 0; i < 2500; ++i) {
         if (heights[i] & 0x1) {
            result.push_back(i);
         }
      }

      if (result.size() != N) {
         cerr << "Something is very wrong!" << endl;
         exit(1);
      }

      sort(result.begin(), result.end());


      cout << "Case #" << t + 1 << ":";
      for (unsigned i = 0; i < result.size(); ++i) {
         cout << " " << result[i] + 1;
      }
      cout << endl;
   }

   return 0;
}

