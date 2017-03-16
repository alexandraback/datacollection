#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

fstream in, out;

int T;
int X;
int R;
int C;

string ans;

int min(int i, int j) {
  if (i < j) {
    return i;
  }
  return j;
}

int max(int i, int j) {
  if (i < j) {
    return j;
  }
  return i;
}

int main() {
  in.open("D-large.in", fstream::in);
  out.open("probd-large.out", fstream::out);

  in >> T;
  for (int i = 0; i < T; i++) {
    in >> X >> R >> C;

    if (R * C % X != 0 ||
	X >= 8 ||
	(X + 1) / 2 > min(R, C) ||
	X > max(R, C)) {
      ans = "RICHARD";
    } else if (X == 7) {
      if (min(R, C) >= 5) {
	ans = "GABRIEL";
      } else if (min(R, C) < 4) {
	ans = "RICHARD";
      } else {
	if (max(R, C) >= 9) {
	  ans = "GABRIEL";
	} else {
	  ans = "RICHARD";
	}
      }
    } else if (X == 6) {
      if (min(R, C) >= 4) {
	ans = "GABRIEL";
      } else {
	ans = "RICHARD";
      }
    } else if (X == 5) {
      if (min(R, C) >= 4) {
	ans = "GABRIEL";
      } else {
	if (max(R, C) >= 6) {
	  ans = "GABRIEL";
	} else {
	  ans = "RICHARD";
	}
      }
    } else if (X == 4) {
      if (min(R, C) >= 3) {
	ans = "GABRIEL";
      } else {
	ans = "RICHARD";
      }
    } else if (X == 3) {
      if (min(R, C) >= 2) {
	ans = "GABRIEL";
      } else {
	ans = "RICHARD";
      }
    } else if (X == 2) {
      ans = "GABRIEL";
    } else {
      ans = "GABRIEL";
    }
    out << "Case #" << i + 1 << ": " << ans << endl;
  }
    
  in.close();
  out.close();
  return 0;
}
