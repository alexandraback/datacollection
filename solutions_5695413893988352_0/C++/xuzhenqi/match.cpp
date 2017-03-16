#include<iostream>
#include<sstream>
#include<cassert>
#include<string>
#include<cstdlib>
using namespace std;

int str2int(const string& s) {
  int out;
  stringstream ss(s);
  ss >> out;
  return out;
}

string replace(string s, char x, char y) {
  string out(s);
  for(int i = 0; i < s.size(); ++i) {
    if (s[i] == x)
      out[i] = y;
  }
  return out;
}

void solve(string c, string j, int index, int& diff, string &oc, string &oj) {
  if (index == c.size()) {
    if (diff == -1) {
      diff = abs(str2int(c) - str2int(j));
      oc = c;
      oj = j;
    }
    else {
      int new_diff = abs(str2int(c) - str2int(j));
      if (new_diff < diff) {
        diff = new_diff;
        oc = c;
        oj = j;
      }
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
  } else if (c[index] == '?' && j[index] != '?') {
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
  } else if (c[index] != '?' && j[index] == '?') {
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
  } else if (c[index] != '?' && j[index] != '?') {
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
  } else {
    assert(false);
  }
}

int main() {
  int T;
  cin >> T;
  string c, j, oc, oj;
  for(int i = 1; i <= T; ++i) {
    cin >> c >> j;
    int diff = -1;
    solve(c, j, 0, diff, oc, oj);
    cout << "Case #" << i << ": " << oc << " " << oj << endl;
  }
  return 0;
}
