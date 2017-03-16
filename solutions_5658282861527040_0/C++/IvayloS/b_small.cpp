/*
 * b_small.cpp
 *
 *  Created on: May 3, 2014
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
    int a, b, k;
    cin >> a >> b >> k;
    int ans = 0;
    for (int i = 0; i < a; ++i) {
      for (int j =0 ; j < b; ++j) {
        int temp = (i & j);
        if (temp < k) {
          ans++;
        }
      }
    }
    cout << "Case #" << it << ": " << ans << endl;
  }
  return 0;
}



