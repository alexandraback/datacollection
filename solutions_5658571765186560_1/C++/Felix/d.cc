#include <iostream>

using namespace std;

// Returns 1 if Richard wins, 0 if Gabriel wins.
int winner(int x, int r, int c) {
  if (r > c) swap(r, c);  // r <= c.
  if (x > r * c) return 1;
  if ((r * c) % x != 0) return 1;

  if (x == 1) return 0; // Can always fill.
  if (x == 2) return 0; // Can always fill.
  if (x > c) return 1;  // Line X-omino doesn't fit in larger dimension.
  if (x > 2 * r) return 1;  // L-shaped X-omino doesn't fit in smaller dimension.
  if (x < r) return 0;  // Can't create regions.
  if (x == r) return 0;  // Can't create bad regions.
  if (r >= 3 && x >= 7) return 1;  // Can create region of size 1.

  // Given that none of the above conditions is satisfied.
  if (x == 3 && r == 2) return 0;  // Can't create regions.
  if (x == 4 && r == 2) return 1;  // T-shaped 4-omino creates 2 regions of bad size.
  if (x == 4 && r == 3) return 0;  // Can't create regions.
  if (x == 5 && r == 3) {  
    // Staircase-shaped 5-omino requires 4 + 3 extra columns, 10 total.
    // The other 5-ominos that create regions do not require more that 7 extra columns.
    if (c < 10) return 1;
    return 0;
  }
  if (x == 5 && r == 4) return 0;  // Can't create regions.
  if (x == 6 && r == 3) return 1;  // h-shaped 6-omino creates bad regions.
  if (x == 6 && r >= 4) return 0;  // Can't create regions.

  return -1;  // Will never be reached if the above conditions are exhaustive.
}

int main() {
  int T;
  cin >> T;
  for (int ca = 1; ca <= T; ++ca) {
    cout << "Case #" << ca << ": ";
    int x, r, c;
    cin >> x >> r >> c;
    int w = winner(x, r, c);
    if (w == 1) {
      cout << "RICHARD" << endl;
    }
    else if (w == 0) {
      cout << "GABRIEL" << endl;
    }
    else {
      cout << "?" << endl;
    }
  }
}

