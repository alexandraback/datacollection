/*
 * c.cpp
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
char buf[12000];
char mul[256][256];

char positive[] = {'1', 'i', 'j', 'k'};
char negative[] = {'!', 'I', 'J', 'K'};
char negate_vals[256];

void init_mul() {
  negate_vals['1'] = '!';
  negate_vals['!'] = '1';
  negate_vals['i'] = 'I';
  negate_vals['I'] = 'i';
  negate_vals['j'] = 'J';
  negate_vals['J'] = 'j';
  negate_vals['k'] = 'K';
  negate_vals['K'] = 'k';
  mul['1']['1'] = '1';
  mul['1']['i'] = 'i';
  mul['1']['j'] = 'j';
  mul['1']['k'] = 'k';
  mul['i']['1'] = 'i';
  mul['i']['i'] = '!';
  mul['i']['j'] = 'k';
  mul['i']['k'] = 'J';
  mul['j']['1'] = 'j';
  mul['j']['i'] = 'K';
  mul['j']['j'] = '!';
  mul['j']['k'] = 'i';
  mul['k']['1'] = 'k';
  mul['k']['i'] = 'j';
  mul['k']['j'] = 'I';
  mul['k']['k'] = '!';

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      mul[(int)positive[i]][(int)negative[j]] =
          mul[(int)negative[i]][(int)positive[j]] =
              negate_vals[(int)mul[(int)positive[i]][(int)positive[j]]];
      mul[(int)negative[i]][(int)negative[j]] =
          mul[(int)positive[i]][(int)positive[j]];
    }
  }
}

bool solve(const string& s) {
  int leftmost = -1;
  char cur = '1';
  for (int i = 0; i < (int)s.size(); ++i) {
    cur = mul[cur][s[i]];
    if (cur == 'i') {
      leftmost = i;
      break;
    }
  }
  if (leftmost == -1) {
    return false;
  }
  cur = '1';
  int middle = -1;
  for (int i = leftmost + 1; i < (int)s.size(); ++i) {
    cur = mul[cur][s[i]];
    if (cur == 'j') {
      middle = i;
      break;
    }
  }
  if (middle == -1) {
    return false;
  }
  cur = '1';
  for (int i = middle + 1; i < (int)s.size(); ++i) {
    cur = mul[cur][s[i]];
  }
  return cur == 'k';
}
int main() {
  freopen((PROGRAM_NAME + ".in").c_str(), "r", stdin);
  freopen((PROGRAM_NAME + ".out").c_str(), "w", stdout);
  init_mul();

  int nt;
  cin >> nt;

  for (int it = 1; it <= nt; it++) {
    int l;
    long long X;
    cin >> l >> X;
    if (X > 24) {
      X = X % 12 + 12;
    }
    int x = X;

    scanf("%s", buf);
    string temp(buf), s;
    for (int i = 0; i < x; ++i) {
      s += buf;
    }

    bool can = solve(s);
    string answer;
    if (can) {
      answer = "YES";
    } else {
      answer = "NO";
    }
    cout << "Case #" << it << ": " << answer << endl;
  }
  return 0;
}

