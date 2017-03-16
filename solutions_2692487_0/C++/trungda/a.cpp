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

ifstream fi("asmall.in");
//ifstream fi("A-large.in");
//ifstream fi("A-small-practice.in");
//ifstream fi("sample.in");
ofstream fo("sample.out");

int test;
long long a, n;
long long p2[30];
long long res;
vector<long long> v;

void input();
void solve();
void output();

int main() {
  int ntest;
  fi >> ntest;
  p2[0] = 1;
  for (int i = 1; i < 21; i ++) {
    p2[i] = 2 * p2[i - 1];
  }
  for (test = 1; test <= ntest; test ++) {
    input();
    solve();
    output();
  }
  fi.close();
  fo.close();
  return 0;
}

void input() {
  //start code here
  v.clear();
  fi >> a >> n;
  for (int i = 0; i < n; i ++) {
    long long x;
    fi >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
}

void solve() {
  res = n;
  if (a == 1) return;
  long long cur = 0;
  for (int i = 0; i < n; i ++) {
    if (a <= v[i]) {
      long long aa = a;
      for (int c = 1; c < 21; c ++) {
	a = a + (aa - 1) * p2[c - 1];
	if (a > v[i]) {
	  cur = cur + c;
	  break;
	}
      }
    }
    //    cout << a << " " << v[i] << " " << cur << endl;
    a = a + v[i];
    res = min(res, cur + n - i - 1);
  }
}

void output() {
  fo << "Case #" << test << ": " << res << endl;
}
