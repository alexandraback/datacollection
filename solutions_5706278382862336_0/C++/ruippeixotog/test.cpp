#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define MAXN 100

using namespace std;

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int num, denom;
    scanf("%d/%d", &num, &denom);

    bool possible = !(denom & (denom - 1));

    int gens = 0;
    if(possible && num != denom) {
      gens++;
      while(num < denom / 2) {
        denom /= 2;
        gens++;
      }
    }

    cout << "Case #" << tc << ": ";
    if(!possible) cout << "impossible" << endl;
    else cout << gens << endl;
  }
  return 0;
}
