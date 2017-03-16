#include <iostream>
#include <stdio.h>
#include <sstream>
#include <cassert>
#include <string>
using namespace std;

long long conver(const string& s) {
  long long out;
  stringstream ss(s);
  ss >> out;
  return out;
}

long long abs(long long x) {
  if (x < 0)
    return -x;
  return x;
}

string replace(string s, char x, char y) {
  string out(s);
  for(int i = 0; i < s.size(); ++i) {
    if (s[i] == x)
      out[i] = y;
  }
  return out;
}

void solve(string c, string j, int index, long long& diff, string &oc, string &oj) {
  if (index == c.size()) {
      long long new_diff = abs(conver(c) - conver(j));
      if (new_diff < diff) {
        diff = new_diff;
        oc = c;
        oj = j;
      }
    return;
  }
  if (c[index] == '?' && j[index] == '?') {
    c[index] = '0';
    j[index] = '0';
    solve(c, j, index + 1, diff, oc, oj);
    c[index] = '0';
    j[index] = '1';
    solve(c, j, index, diff, oc, oj);
    c[index] = '1';
    j[index] = '0';
    solve(c, j, index, diff, oc, oj);
  } else if (c[index] == '?') {
    if (j[index] != '0') {
      c[index] = j[index] - 1;
      solve(c, j, index, diff, oc, oj);
    }
    c[index] = j[index];
    solve(c, j, index+1, diff, oc, oj);
    if (j[index] != '9') {
      c[index] = j[index] + 1;
      solve(c, j, index, diff, oc, oj);
    }
  } else if (j[index] == '?') {
    if (c[index] != '0') {
      j[index] = c[index] - 1;
      solve(c, j, index, diff, oc, oj);
    }
    j[index] = c[index];
    solve(c, j, index + 1, diff, oc, oj);
    if (c[index] != '9'){
      j[index] = c[index] + 1;
      solve(c, j, index, diff, oc, oj);
    }
  } else  {
    if (c[index] > j[index]) {
      string tc = replace(c, '?', '0');
      string tj = replace(j, '?', '9');
      solve(tc, tj, tc.size(), diff, oc, oj);
    } else if (c[index] == j[index]) {
      solve(c, j, index + 1, diff, oc, oj);
    } else {
      string tc = replace(c, '?', '9');
      string tj = replace(j, '?', '0');
      solve(tc, tj, tc.size(), diff, oc, oj);
    }
  }
}

int main() {
  int T;
  cin>>T;
  string c, j, oc, oj;
  int cnt = 0;
  while (T--) {
    cnt++;
    cin>>c>>j;
    long long diff = 999999999999999999L;
    solve(c, j, 0, diff, oc, oj);
    printf("Case #%d: %s %s\n", cnt, oc.c_str(), oj.c_str());
    //cout << "Case #" << i << ": " << oc << " " << oj << endl;
  }
  return 0;
}
