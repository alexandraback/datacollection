#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <iterator>
#include <queue>
#include <cassert>

using namespace std;

#define MAXSIZE 1000000

int numindices, indices[MAXSIZE];
string L;

bool isvowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void findindices(int n) {
  bool good;
  numindices = 0;
  
  for (int i = 0; i <= L.length() - n; ++i) {
    good = true;
    for (int j = 0; j < n; ++j) {
      if (isvowel(L[i+j])) {
        good = false;
        break;
      }
    }
    if (good) {
      indices[numindices++] = i;
    }
  }
  indices[numindices] = -1;
}

int calcvalue(int n) {
  int minindex = 0, sum = 0;
  for (int i = 0; i < numindices; ++i) {
    sum += (indices[i] - minindex + 1) * (L.length() - indices[i] - n + 1);
    minindex = indices[i] + 1;
  }
  return sum;
}

int main() {
  int T, n;
  
  cin >> T;
  for (int trial = 1; trial <= T; ++trial) {
    cin >> L >> n;
    findindices(n);
    
    cout << "Case #" << trial << ": " << calcvalue(n) << endl;
  }
  
  return 0;
}
