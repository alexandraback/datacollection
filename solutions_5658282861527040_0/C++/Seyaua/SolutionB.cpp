#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <queue>
#include <ctime>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

void solve(int tcase) {
  printf("Case #%d: ", tcase);

  int a, b, k;
  cin >> a >> b >> k;
  int total = 0;
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      if ((i & j) < k) {
        ++total;
      }
    }
  }
  cout << total << endl;

}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; ++i) {
    solve(i + 1);
    cerr << i + 1 << endl;
  }

  return 0;
}
