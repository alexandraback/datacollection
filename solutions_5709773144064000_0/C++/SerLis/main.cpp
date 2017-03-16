#pragma comment(linker, "/STACK:256000000")
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

  long long k, n, m, p;
  string s1, s2; 
  long long a[21];


int main() {
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  cout.precision(20);
  for (int t = 1; t <= T; ++t) {
    double C, F, X, res = 0, cur_res, new_res, per = 2;
    cin >> C >> F >> X;
    cur_res = X / per;
    new_res = C / per + X / (per + F);
    while (cur_res > new_res) { 
      cur_res = new_res;
      res += C / per;
      per += F;
      new_res = res + C / per + X / (per + F);
    }
    cout << "\nCase #" << t << ": ";
    cout << cur_res;
  }
}
