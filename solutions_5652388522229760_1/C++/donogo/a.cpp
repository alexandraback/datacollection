#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <list>

using namespace std;

typedef long long int LL;

LL lastnum(LL x) {
  int covered[10];
  int d;
  LL s, y;

  if (x == 0) {
    return 0;
  }

  for (d = 0; d < 10; d++) {
    covered[d] = 0;
  }

  s = 0;
  for (;;) {
    s += x;
    y = s;
    //    cout << y << endl;
    while (y > 0) {
      d = y % 10;
      covered[d] = 1;
      y /= 10;
    }
    for (d = 0; d < 10; d++) {
      if (covered[d] == 0)
	break;
    }
    if (d == 10) {
      //      cout << "Z" << endl;
      return s;
    }
  }
  return 0;
}

int main(void) {
  int T, t;
  LL N;
  LL last;
  cin >> T;

  for (t = 1; t <= T; t++) {
    cin >> N;
    last = lastnum(N); 
    if (last == 0) {
      cout << "Case #" << t << ": " << "INSOMNIA" << endl;
    } else {
      cout << "Case #" << t << ": " << last << endl;
    }
  }
  return 0;
}
