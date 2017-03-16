/*
 * b.cpp
 *
 *  Created on: Apr 12, 2014
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
int main() {
  freopen("google.in", "r", stdin);
  freopen("google.out", "w", stdout);
  int nt;
  cin >> nt;
  for (int it = 1; it <= nt; it++) {
    double c, f, x;
    cin >> c >> f >> x;
    double ans = x / 2;
    double total = 0.0;
    double v = 2.0;
    while (total < ans - epsylon) {
      total += c / v;
      v += f;
      double temp = total + x / v;
      if (temp < ans) {
        ans = temp;
      }
    }
    cout << "Case #" << it << ": ";
    printf("%.7lf\n", ans);
  }
  return 0;
}



