/*
 * a.cpp
 *
 *  Created on: Apr 11, 2015
 *      Author: istrandjev
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <functional>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;

const string PROGRAM_NAME = "google";

int main() {
  freopen((PROGRAM_NAME + ".in").c_str(), "r", stdin);
  freopen((PROGRAM_NAME + ".out").c_str(), "w", stdout);
  int nt;
  cin >> nt;
  for (int it = 1; it <= nt; it++) {
    int n;
    string s;
    cin >> n >> s;
    int so_far = 0;
    int needed = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] != 0 && i > so_far) {
        needed += i - so_far;
        so_far += i - so_far;
      }
      so_far += s[i] - '0';
    }
    cout << "Case #" << it << ": " << needed << endl;
  }
  return 0;
}


