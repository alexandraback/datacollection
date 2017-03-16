#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;

int main() {
  int TC; cin >> TC;
  for (int tc = 1; tc <= TC; tc++) {
    long long t, r; cin >> r >> t;
    long long rings = 0;
    long long prev = r*r;
    long long next = (r+1)*(r+1);
    while ((r+1)*(r+1) - prev <= t) {
      t -= (r+1)*(r+1) - prev;

      r+=2;
      prev = r*r;
      rings++;
    }
    printf("Case #%d: %lld\n", tc, rings);
  }


  return 0;
}
