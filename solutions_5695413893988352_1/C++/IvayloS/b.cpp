/*
 * b.cpp
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

ll mabs(ll x) {
  return x >= 0 ? x : -x;
}

void solve_greedy(string& c, string& j) {
  for (int i = 0; i < (int)c.size(); ++i) {
    ll cval = 0, jval = 0;
    for (int l = 0; l < i; ++l) {
      cval = cval * 10LL + (c[l] - '0');
      jval = jval * 10LL + (j[l] - '0');
    }

    ll best = -1;
    char bc = 0;
    char bj = 0;

    for (int u = 0; u < 10; ++u) {
      for (int v = 0; v < 10; ++v) {
        ll tcval = cval, tjval = jval;
        char tc, tj;
        if (c[i] != '?') {
          tcval = tcval * 10LL + c[i] - '0';
          tc = c[i];
        } else {
          tcval = tcval * 10LL + u;
          tc = u + '0';
        }

        if (j[i] != '?') {
          tjval = tjval * 10LL + j[i] - '0';
          tj = j[i];
        } else {
          tjval = tjval * 10LL + v;
          tj = v + '0';
        }

        if (best == -1 || mabs(tjval - tcval) < best) {
          best = mabs(tjval - tcval);
          bc = tc;
          bj = tj;
        }
      }
    }
    c[i] = bc;
    j[i] = bj;
  }
}


bool better(const pair<string, string>& a, const pair<string, string>& b) {
  ll x1 = 0, x2 = 0, y1 = 0, y2 = 0;

  for (int i = 0; i < (int)a.first.size(); ++i) {
    x1 = x1 * 10 + a.first[i] - '0';
    x2 = x2 * 10 + b.first[i] - '0';
    y1 = y1 * 10 + a.second[i] - '0';
    y2 = y2 * 10 + b.second[i] - '0';
  }

  ll r1 = mabs(x1 - y1);
  ll r2 = mabs(x2 - y2);
  if (r1 != r2) {
    return r1 < r2;
  }

  return a < b;
}

pair<string, string> fill_after(bool maximize, int index, const string& a, const string& b) {
  string resa = a;
  string resb = b;
  for (int i = index; i < (int)a.size(); ++i) {
    if (a[i] == '?') {
      resa[i] = maximize ? '9' : '0';
    }
    if (b[i] == '?') {
      resb[i] = maximize ? '0' : '9';
    }
  }

  return make_pair(resa, resb);
}

int main() {
  freopen((PROGRAM_NAME + ".in").c_str(), "r", stdin);
  freopen((PROGRAM_NAME + ".out").c_str(), "w", stdout);
  int nt;
  cin >> nt;

  for (int it = 1; it <= nt; it++) {
    string c, j;
    cin >> c >> j;

    bool maximize = false;
    int index = (int)c.size();

    string original_c = c;
    string original_j = j;
    for (int i = 0; i < (int)c.size(); ++i) {
      if (c[i] == '?') {
        if (j[i] == '?') {
          c[i] = j[i] = '0';
        } else {
          c[i] = j[i];
        }
      } else if (j[i] == '?' ){
        j[i] = c[i];
      } else if (c[i] != j[i]) {
        index = i;
        if (c[i] < j[i]) {
          maximize = true;
        } else {
          maximize = false;
        }
        break;
      }
    }

    pair<string, string> best = fill_after(maximize, index, c, j);
    for (int i = index - 1; i >= 0; --i) {
      if (original_c[i] == '?') {
        if (maximize && c[i] != '9') {
          string tempc = c, tempj = j;
          tempc[i] = c[i] + 1;
          for (int l = i + 1; l < (int)c.size();++l) {
            if (original_j[l] == '?') {
              tempj[l] = '?';
            }

            if (original_c[l] == '?') {
              tempc[l] = '?';
            }
          }
          pair<string, string> temp = fill_after(false, i, tempc, tempj);
          if (better(temp, best)) {
            best = temp;
          }
        }

        if (!maximize && c[i] != '0') {
          string tempc = c, tempj = j;
          tempc[i] = c[i] - 1;
          for (int l = i + 1; l < (int)c.size();++l) {
            if (original_j[l] == '?') {
              tempj[l] = '?';
            }

            if (original_c[l] == '?') {
              tempc[l] = '?';
            }
          }
          pair<string, string> temp = fill_after(true, i, tempc, tempj);
          if (better(temp, best)) {
            best = temp;
          }
        }
      }
      if (original_j[i] == '?') {
        if (!maximize && j[i] != '9') {
          string tempc = c, tempj = j;
          tempj[i] = j[i] + 1;
          for (int l = i + 1; l < (int)c.size();++l) {
            if (original_j[l] == '?') {
              tempj[l] = '?';
            }

            if (original_c[l] == '?') {
              tempc[l] = '?';
            }
          }
          pair<string, string> temp = fill_after(true, i, tempc, tempj);
          if (better(temp, best)) {
            best = temp;
          }
        }

        if (maximize && j[i] != '0') {
          string tempc = c, tempj = j;
          tempj[i] = j[i] - 1;
          for (int l = i + 1; l < (int)c.size();++l) {
            if (original_j[l] == '?') {
              tempj[l] = '?';
            }

            if (original_c[l] == '?') {
              tempc[l] = '?';
            }
          }
          pair<string, string> temp = fill_after(false, i, tempc, tempj);
          if (better(temp, best)) {
            best = temp;
          }
        }
      }
    }

    cout << "Case #" << it << ": " << best.first << " " << best.second << endl;
  }
  return 0;
}

