#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main() {
   int total;
   cin >> total;
   for (int totalCount = 0; totalCount < total; ++totalCount) {
      int A, B;
      cin >> A >> B;
      float* acc = new float[A];
      float* exp = new float[A + 2];
      float min = 2 * B;
      for (int i = 0; i < A; ++i) {
         cin >> acc[i];
      }
      for (int i = 0; i < A + 1; ++i) {
         exp[i] = 0;
         // can save
         int key = (B - A + 1 + i * 2);
         float r = 0;
         for (int j = 0; j < A - i; ++j) {
            if (j == 0) {
               r = 1;
            }
            r *= acc[j];
         }
         //cerr << "save r:" << r << endl;
         exp[i] = r * key;
         // can not save
         key += B + 1;
         r = 1 - r;
         exp[i] += r * key;
         if (exp[i] < min) {
            min = exp[i];
         }
         //cerr << i << " " << exp[i] << endl;
      }
      int key = B + 2;
      if (B + 2 < min) {
         min = B + 2;
      }
      printf("Case #%d: %.6f\n", totalCount + 1, min);
      delete[] acc;
      delete[] exp;
   }
}
