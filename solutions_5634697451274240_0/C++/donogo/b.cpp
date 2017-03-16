#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <cstdio>

using namespace std;

int count(string s) {
  vector <int> t;
  int i, n;
  int chg;
  int num;
  
  n = s.length();
  for (i = 0; i < n; i++) {
    chg = ((i == 0) || (s[i-1] != s[i]));
    if (chg) {
      t.push_back(s[i]);
    }
  }

  num = t.size();
  if (num % 2 == 0 && t[0] == '-') {
    num--;
  }
  if (num % 2 == 1 && t[0] == '+') {
    num--;
  }
  return num;  
  
}


int main(void) {
  int T, t;
  int num;
  cin >> T;

  for (t = 1; t <= T; t++) {
    string s;
    cin >> s;
    num = count(s);
    cout << "Case #" << t << ": " << num << endl;

  }
  return 0;
}
