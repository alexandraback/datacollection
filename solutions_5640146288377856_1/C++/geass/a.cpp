/* C library */
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
/* Containers */
#include <vector>
/* Input/Output */
#include <iostream>
/* Other */
#include <algorithm>
using namespace std;


int main() {

  int T;
  cin >> T;

  for (int x=1; x<=T; ++x) {

    // Input
    int R, C, W;
    cin >> R >> C >> W;
    int y = ( C / W ) * R  + W - 1;
    if (C%W > 0) y++;

    // Output
    printf("Case #%i: %i\n", x, y);
  }
  return 0;
}
