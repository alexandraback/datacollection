#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <list>

using namespace std;

int canfillL( int X, int R, int C) {
  if (R > C) {
    int tmp;
    tmp = R;
    R = C;
    C = tmp;
  } // R <= C

  if (X == 1) {
    return 1;
  } else if (X == 2) {
    return (R * C % 2 == 0);
  } else if (X == 3) {
    if (R * C % 3 != 0) {
      return 0;
    }
    if (R == 1) {
      return 0;
    }
    return 1;
  } else if (X == 4) {
    if (R * C % 4 != 0) {
      return 0;
    }

    if (R <= 2) {
      return 0;
    }

    return 1;
  } else if (X == 5) {
    if (R * C % 5 != 0) {
      return 0;
    }
    if (R <= 2) {
      return 0;
    }
    if (R == 3) {
      if (C <= 5) {
	return 0;
      }
      return 1;
    }
    return 1;
  } else if (X == 6) {
    if (R <= 2) {
      return 0;
    }
    if (R == 3) {
      return 0;
    }
    return 1;
  } else { 
    return 0;
  }
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

    res = canfillL(X, R, C);

    
    cout << "Case #" << t << ": " << ( (res == 1) ?  "GABRIEL" : "RICHARD")
				       << endl;

  }
  return 0;
}
