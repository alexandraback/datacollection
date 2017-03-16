#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cassert>
using namespace std;

char A[8], B[8];

int main() {
  int T;
  cin >> T;
  
  for (int t = 0; t < T; t++) {
    long a, b;
    cin >> A >> B;
    a = atol(A);
    b = atol(B);
    int len = strlen(A);
    long count = 0;
    for (long i = a + 1; i <= b; i++) {
      char C[8]; // larger of potential recycled pair
      ltoa(i, C, 10);
      int found = 0;
      char seen[8][8]; // keep track of lower numbers to prevent duplicates
      for (int q = 0; q < 8; q++) {
        seen[q][0] = '\0';
      }
      for (int j = 1; j < len; j++) { // warp length

        char D[8] = {0}; // smaller of potential recycled pair
        // copy back
        for (int k = 0; k < j; k++) { // for each warped character
          D[k] = C[len - j + k];
        }
        // copy front
        for (int k = 0; k < len - j; k++) { // for each character from front
          D[k + j] = C[k];
        }
        
        // check D hasn't been seen before
        bool unique = true;
        for (int q = 0; q < found; q++) {
          if (strcmp(D, seen[q]) == 0) { // matches history
            unique = false;
            break;
          }
        }
        if (!unique)
          continue;
        
        // check if C and D form a pair
        if (strcmp(D, A) >= 0 && strcmp(C, D) > 0) {
          count++;
          strcpy(seen[found], D);
          found++;
        }
        assert(found <= 8);
      }
    }

    printf("Case #%d: %d\n", t + 1, count);
  }
}