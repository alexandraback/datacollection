//this is the default for Google code jam only
#include <string>
#include <vector>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

#define pii pair<int, int>

using namespace std;

ifstream fi("B-small-attempt1.in");
//iofstream fi("B-large.in");
//ifstream fi("sample.in");
ofstream fo("sample.out");

int test;
int normal[31];
int s[31];
int res;

void prepare();
void smallsolve();
void solve();

int main() {
  int ntest;
  fi >> ntest;
  prepare();
  for (test = 1; test <= ntest; test ++) {
    //    solve();
    smallsolve();
    fo << "Case #" << test << ": " << res << endl;
  }
  fi.close();
  fo.close();
  return 0;
}

void prepare() {
  normal[0] = 0;
  for (int i = 1; i <= 30; i ++)
    for (int p1 = 0; p1 <= 10; p1 ++)
      for (int p2 = p1; p2 <= 10; p2 ++)
	for (int p3 = p2; p3 <= 10; p3 ++)
	  if (p2 - p1 <= 2 && p3 - p2 <= 2 && p3 - p1 <= 2 && p1 + p2 + p3 == i) {
	    if (p2 - p1 == 2 || p3 - p2 == 2 || p3 - p1 == 2)
	      s[i] = max(s[i], p3);
	    else
	      normal[i] = max(normal[i], p3);
	  }
  for (int i = 0; i <= 30; i ++)
    cout << i << " " << normal[i] << " " << s[i] << endl;
}

void smallsolve() {
  int n, S, p;
  int x[101];
  fi >> n >> S >> p;
  for (int i = 0; i < n; i ++) fi >> x[i];
  
  res = 0;
  if (S == 0) {
    for (int i = 0; i < n; i ++)
      if (normal[x[i]] >= p) res ++;
  }
  else if (S == 1) {
    for (int i = 0; i < n; i ++) {
      int tres = 0;
      if (s[x[i]] >= p) tres ++;
      for (int j = 0; j < n; j ++)
	if (j != i && normal[x[j]] >= p) tres ++;
      res = max(res, tres);
    }
  }
  else if (S == 2) {
    for (int i = 0; i < n; i ++)
      for (int j = i + 1; j < n; j ++) {
	int tres = 0;
	if (s[x[i]] >= p) tres ++;
	if (s[x[j]] >= p) tres ++;
	for (int k = 0; k < n; k ++)
	  if (k != i && k != j && normal[x[k]] >= p) tres ++;
	res = max(res, tres);
      }
  }
  else {
    for (int i = 0; i < n; i ++)
      if (s[x[i]] >= p) res ++;
  }
}

void solve() {
  //start code here
  int n, S, p;
  int x[101];
  fi >> n >> S >> p;
  for (int i = 0; i < n; i ++) fi >> x[i];
  res = 0;
  int ss = 0;
  sort(x, x + n);
  for (int i = 0; i < n; i ++) {
    if (max(normal[x[i]], s[x[i]]) >= p) {
      res ++;
      if (2 <= x[i] && x[i] <= 28) ss ++;
    }
  }
  while (ss > S) {
    for (int i = 0; i < n; i ++)
      if (2 <= x[i] && x[i] <= 28 && normal[x[i]] == s[x[i]]) {
	ss --;
	if (ss == S) return;
      }

    for (int i = 0; i < n; i ++) {
      if (s[x[i]] == normal[x[i]] + 1 && s[x[i]] == p) break;
      if (2 <= x[i] && x[i] <= 28 && s[x[i]] == normal[x[i]] + 1 && s[x[i]] < p) {
	ss --;
	if (ss == S) return;
      }
    }

    for (int i = n - 1; i >= 0; i --) {
      if (s[x[i]] == normal[x[i]] + 1 && s[x[i]] < p) break;
      if (s[x[i]] == normal[x[i]] + 1) {
	if (s[x[i]] >= p && p > normal[x[i]]) res --;
	ss --;
	if (ss == S) return;
      }
    }
  }
}
