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

//ifstream fi("B-small-attempt1.in");
ifstream fi("B-large.in");
//ifstream fi("B-small-practice.in");
//ifstream fi("sample.in");
ofstream fo("sample.out");

int test;

int n;
int a[1001], b[1001];
int ia[1001], ib[1001];

void solve();
void qsorta(int, int);
void qsortb(int, int);

int main() {
  int ntest;
  fi >> ntest;
  for (test = 1; test <= ntest; test ++) {
    solve();
  }
  fi.close();
  fo.close();
  return 0;
}

void solve() {
  //start code here
  fi >> n;
  bool done[1001];
  for (int i = 1; i <= n; i ++) {
    fi >> a[i] >> b[i];
    ia[i] = ib[i] = i;
    done[i] = false;
  }
  qsortb(1, n);
  //for (int i = 1; i <= n; i ++) cout << a[i] << " " << b[i] << endl;
  int sb = 1;
  int star = 0;
  int res = 0;
  while (sb <= n) {
    while (sb <= n && star >= b[sb]) {
      res ++;
      if (done[sb]) star ++;
      else 
	star += 2;
      done[sb] = true;
      sb ++;
    }
    if (sb > n) break;
    bool ok = false;
    for (int i = n; i >= 1; i --) 
      if (!done[i] && star >= a[i]) {
	res ++;
	star ++;
	ok = true;
	done[i] = true;
	break;
      }
    if (!ok) {
      fo << "Case #" << test << ": Too Bad" << endl;
      return;
    }
  }
  fo << "Case #" << test << ": " << res << endl;
}

void qsorta(int l, int r) {
  if (l >= r) return;
  int i = l;
  int j = r;
  int mid = a[(l + r) / 2];
  while (i < j) {
    while (a[i] < mid) i++;
    while (mid < a[j]) j--;
    if (i <= j) {
      swap(a[i], a[j]);
      swap(ia[i], ia[j]);
      i ++;
      j --;
    }
  }
  qsorta(i, r);
  qsorta(l, j);
}

void qsortb(int l, int r) {
  if (l >= r) return;
  int i = l;
  int j = r;
  int mid = b[(l + r) / 2];
  while (i < j) {
    while (b[i] < mid) i++;
    while (mid < b[j]) j--;
    if (i <= j) {
      swap(b[i], b[j]);
      swap(a[i], a[j]);
      i ++;
      j --;
    }
  }
  qsortb(i, r);
  qsortb(l, j);
}
