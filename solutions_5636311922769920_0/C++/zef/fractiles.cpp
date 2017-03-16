#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int t, k, c, s;
  cin >> t;
  for (int caseno = 1; caseno <= t; caseno++) {
    cin >> k >> c >> s;
    printf("Case #%i:", caseno);
    for (int i = 1; i <= s; i++) {
      printf(" %i", i);
    }
    printf("\n");
  }
}
