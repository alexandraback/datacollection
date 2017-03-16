/*
 * d.cpp
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


int get_war(const vector<double>& a, const vector<double>& b) {
  set<double> bs(all(b));
  int score = 0;
  for (int i = a.size() - 1; i >= 0; --i) {
    set<double>::iterator it = bs.upper_bound(a[i]);
    if (it == bs.end()) {
      score++;
      bs.erase(bs.begin());
    } else {
      bs.erase(*it);
    }
  }
  return score;
}

int get_dec(const vector<double>& a, const vector<double>& b, int lied) {
  set<double> bs(b.begin(), b.begin() + b.size() - lied);
  set<double> as(a.begin() + lied, a.end());
  int score = 0;
  while (!as.empty()) {
    set<double>::iterator it = as.upper_bound(*bs.begin());
    if (it == as.end()) {
      break;
    }
    score++;
    as.erase(*it);
    bs.erase(*bs.begin());
  }
  return score;
}

int get_deceipt(const vector<double>& a, const vector<double>& b) {
  int n = (int)a.size();
  int ans = 0;
  for (int lied = 0; lied <= n; ++lied) {
    ans = max(ans, get_dec(a, b, lied));
  }
  return ans;
}

int main() {
  freopen("google.in", "r", stdin);
  freopen("google.out", "w", stdout);
  int nt;
  cin >> nt;
  for (int it = 1; it <= nt; it++) {
    int n;
    cin >> n;
    vector<double> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    sort(all(a));
    sort(all(b));
    cout << "Case #" << it << ": " << get_deceipt(a, b) << " "<< get_war(a, b) << endl;
  }
  return 0;
}



