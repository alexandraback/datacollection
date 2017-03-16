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
  int n;
  string s;
  cin >> n >> s;
  
  int curr = 0;
  int added = 0;
  for (int i = 0; i <= n; i++) {
    while (curr < i) {
      curr++;
      added++;
    }
    curr += s.at(i) - '0';
  }

  cout << "Case #" << (test+1) << ": " << added << endl;
}


int main() {
  int t, T;
  cin >> T;
  for(t=0; t<T; t++) solve(t);
  return 0;
}

