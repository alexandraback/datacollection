/*
 * b.cpp
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
    int d;
    cin >> d;
    vector<int> ans(1010, 0);
    int mv = 0;
    for (int i = 0; i < d; ++i) {
      int temp;
      scanf("%d", &temp);
      mv = max(mv, temp);
      for (int j = 1; j < temp; ++j) {
        int tmp = (temp + j - 1) / j - 1;
        ans[j] += tmp;
      }
    }

    int best = ans[1] + 1;
    for (int i = 2; i <= mv; ++i) {
      int cur = ans[i] + i;
      if (cur < best) {
        best = cur;
      }
    }
    cout << "Case #" << it << ": " << best << endl;
  }
  return 0;
}


