#include <cstdio>
#include <iostream>

using namespace std;

int ntests, x, r, c;

int main() {
  freopen("D-large.in", "r", stdin);
  freopen("D-large.out", "w", stdout);
  cin >> ntests;
  for (int test = 1; test <= ntests; ++test) {
    cin >> x >> r >> c;
    cout << "Case #" << test << ": " << "GABRIEL" << endl;
  }
  return 0;
}

