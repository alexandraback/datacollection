#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <list>

using namespace std;

int canfill( int X, int R, int C) {
  if (X == 1) {
    return 1;
  } else if (X == 2) {
    return (R * C % 2 == 0);
  } else if (X == 3) {
    if (R * C % 3 != 0) {
      return 0;
    }
    if (R * C == 3) {
      return 0;
    }
    // 6, 9, 12
    return 1;
  } else if (X == 4) {
    if (R * C % 4 != 0) {
      return 0;
    }
    if (R * C == 4) {
      return 0;
    } else if (R * C == 8) {
      return 0;
    } else { // 12, 16
      return 1;
    }
  }
  return 0;
  
}


int main(void) {
  int T, t;
  int X, R, C;
  int s;
  int res;

  cin >> T;

  for (t = 1; t <= T; t++) {
    string popstr;
    vector <int> popu;
    int numfriend;
    cin >> X;
    cin >> R;
    cin >> C;

    res = canfill(X, R, C);

    
    cout << "Case #" << t << ": " << ( (res == 1) ?  "GABRIEL" : "RICHARD")
				       << endl;

  }
  return 0;
}
