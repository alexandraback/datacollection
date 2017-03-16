#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <functional>
#include <string>

// Encoded solution of the 64 cases :P
unsigned long sol = 0x2033517337;

using namespace std;

int main() {
   int x, r, c, ans, T;

   scanf("%d", &T);
   for (int t = 1; t <= T; t++) {
      scanf("%d%d%d", &x, &r, &c);
      if (r > c) swap(r, c);
      ans = sol & (1 << ((r-1 + (c-1)*c/2)*4 + (4-x)));
      printf("Case #%d: %s\n", t, (!ans) ? "GABRIEL" : "RICHARD");
   }
	return 0;
}

/*
----------------
1x1:
   1: G
   2: R
   3: R
   4: R
1x2:
   1: G
   2: G
   3: R
   4: R
2x2:
   1: G
   2: G
   3: R
   4: R
1x3:
   1: G
   2: R
   3: R
   4: R
2x3:
   1: G
   2: G
   3: G
   4: R
3x3:
   1: G
   2: R
   3: G
   4: R
1x4:
   1: G
   2: G
   3: R
   4: R
2x4:
   1: G
   2: G
   3: R
   4: R
3x4
   1: G
   2: G
   3: G
   4: G
4x4:
   1: G
   2: G
   3: R
   4: G
---------
 */
