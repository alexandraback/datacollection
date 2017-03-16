#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;

string s1 = "GABRIEL", s2 = "RICHARD"; 

void print (string  s, int tmp) {
  cout << "Case #" << tmp << ": " << s << endl;
}
void solve (int tmp) {
  int x, c, r;
  cin >> x >> c >> r;
  if (x == 1) {
    print (s1, tmp);
    return;
  }
  if (x == 2) {
    if ((c * r) % 2 == 1 ) print (s2, tmp);
    else print (s1, tmp);
    return;
  }

  if (x == 3) {
    if ((c*r) % 3 !=  0) print (s2, tmp);
    else {
      switch (c*r) {
      case 3: 
	print (s2, tmp);
	break;
      case 6:
	print (s1, tmp);
	break;
      case 9:
	print (s1, tmp);
	break;
      case 12:
	print (s1, tmp);
	break;
      }
    }
    return;
  }
  
  if (x == 4) {
    if ((c*r) % 4 !=  0) print (s2, tmp);
    else {
      switch (c*r) {
      case 4: 
	print (s2, tmp);
	break;
      case 8:
	print (s2, tmp);
	break;
      case 12:
	print (s1, tmp);
	break;
      case 16:
	print (s1, tmp);
	break;
      }
    }
    return;
  }

  
}
int main () {
  int t, tmp = 0;
  cin >> t;
  while (t) {
    t--;
    tmp++;
    solve (tmp);
    // cout << "next ---------------------------------" << endl;
  }
}
