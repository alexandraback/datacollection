/*
 * b_brute.cpp
 *
 *  Created on: Apr 30, 2016
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

bool matches(int v, const string& s) {
  for (int i = (int)s.size() - 1; i >= 0; --i) {
    if (s[i] != '?' && s[i] - '0' != v % 10) {
      return false;
    }
    v /= 10;
  }
  return v == 0;
}

int main() {
  freopen((PROGRAM_NAME + "2.in").c_str(), "r", stdin);
  freopen((PROGRAM_NAME + "2.out").c_str(), "w", stdout);
  int nt;
  cin >> nt;
  for (int it = 1; it <= nt; it++) {
    string c, j;
    cin >> c >> j;
    int best = -1;
    int ba, bb;
    for (int a = 0; a < 1000; ++a) {
      for (int b =0; b < 1000; ++b) {
        if (matches(a, c) && matches(b, j)) {
          if (best == -1 || abs(a - b) < best) {
            best = abs(a - b);
            ba = a;
            bb = b;
          }
        }
      }
    }
    char b1[20], b2[20];
    sprintf(b1, "%0*d", (int)c.size(), ba);
    sprintf(b2, "%0*d", (int)c.size(), bb);
    cout << "Case #" << it << ": " << b1 << " " << b2 << endl;
  }
  return 0;
}


