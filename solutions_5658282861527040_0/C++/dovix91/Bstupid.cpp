#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
using namespace std;

void solve(int test) {
  unsigned int i, j, k;
  
  unsigned int a, b, c;
  cin >> a >> b >> c;
  
  int cont = 0;
  for(i=0; i<a; i++) {
    for(j=0; j<b; j++) {
      for(k=0; k<c; k++) {
        // cout << i << " " << j << " " << (i&j) << " " << k << endl;
        if((i&j) == k) {
          // cout << i << " " << j << " " << k << endl;
          cont++;
        }
      }
    }
  }

  cout << "Case #" << (test+1) << ": " << cont << endl;
}


int main() {
  int t, T;
  cin >> T;
  for(t=0; t<T; t++) solve(t);
  return 0;
}

