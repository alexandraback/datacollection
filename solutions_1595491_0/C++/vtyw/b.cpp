#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

int main() {
  int T;
  cin >> T;
  
  for (int t = 0; t < T; t++) {
    int n, s, p;
    cin >> n; // number of contestants
    cin >> s; // surprising results allowable
    cin >> p; // this score or better
    int count = 0; // answer
    int couldbe = 0;
    for (int i = 0; i < n; i++) {
      int totalscore;
      cin >> totalscore;
      int rem = totalscore % 3;
      int j = (totalscore - rem) / 3;
      if (rem == 0) {
        if (j == 0) {
          if (j >= p)
            count++;
        }
        else if (j == 10) {
          if (j >= p)
            count++;
        }
        else {
          if (j >= p)
            count++;
          else if (j + 1 >= p)
            couldbe++;
        }
      }
      else if (rem == 1) {
        if (j + 1 >= p)
          count++;
      }
      else if (rem == 2) {
        if (j >= 9) {
          if (j + 1 >= p)
            count++;
        }
        else {
          if (j + 1 >= p)
            count++;
          else if (j + 2 >= p) {
            couldbe++;
          }
        }
      }
      
    }

    printf("aCase #%d: %d\n", t + 1, count + min(s, couldbe));
  }
}