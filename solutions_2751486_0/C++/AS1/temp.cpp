#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxlen = 1000010;
char buf[maxlen];


int stupid_solve (const vector <int> &v, int need) {
  int n = (int)v.size();
  int res =0;
  for (int i = 0; i < n; i++) {
    int cur_d = 0;
    int ok = 0;
    for (int j = i; j < n; j++) {
      if (v[j]) {
        cur_d++;
      } else {
        cur_d = 0;
      }
      if (cur_d >= need) {
        ok = 1;
      }
      res += ok;
    }
  }
  return res;
}

void run() {
  scanf ("%s", buf);
  string s = buf;
  int n;
  scanf ("%d", &n);

  vector <int> v(s.size());
  for (int i = 0; i < (int)v.size(); i++) {
    v[i] = s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u';
  }
  long long res = stupid_solve (v, n);
  cout << res << endl;
}

int main (void) {
  int test_n;
  scanf ("%d", &test_n);
  for (int test_i = 0; test_i < test_n; test_i++) {
    printf ("Case #%d: ", test_i + 1);
    run();
  }

  return 0;
}
