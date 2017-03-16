#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

bool valid(int x, string s) {
  for (int i = s.length() - 1; i >= 0; i--) {
    int tmp = x % 10;
    x /= 10;
    if (s[i] != '?') {
      if (tmp != s[i] - '0') return false;
    }
  }
  return true;
}

int main() {
  int cases;
  string s1, s2;
  cin >> cases;
  for (int cas = 1; cas <= cases; cas++) {
    cin >> s1 >> s2;
    int le = s1.length();
    int ma = 1;
    for (int i = 0; i < le; i++) ma *= 10;

    int del = ma;
    int val = ma;
    int val2 = ma;
    for (int i = 0; i < ma; i++) {
      for (int j = 0; j < ma; j++) {
	int ndel = abs(i-j);
	if (ndel < del ||
	    (ndel == del && i < val)) {
	  if (valid(i, s1) && valid(j, s2)) {
	    del = ndel;
	    val = i;
	    val2 = j;
	  }
	}
      }
    }
    printf("Case #%d: ", cas);
    if (le == 1) {
      printf("%d %d", val, val2);
    } else if (le == 2) {
      printf("%02d %02d", val, val2);
    } else {
      printf("%03d %03d", val, val2);
    }
    cout << endl;
  }
  return 0;
}
