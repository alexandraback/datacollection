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

ifstream fi("B-small-attempt0.in");
//ifstream fi("A-large.in");
//ifstream fi("A-small-practice.in");
//ifstream fi("sample.in");
ofstream fo("sample.out");

int test;

void input();
void solve();
void output();

long long a, b, k;
long long res = 0;

int main() {
  int ntest;
  fi >> ntest;
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
  fi >> a >> b >> k;
  a --;
  b --;
  k --;
}

void solve() {
  res = 0;
  for (unsigned int i = 0; i <= a; i ++)
    for (unsigned int j = 0; j <= b; j ++) {
      //      cout << i << " " << j << " " << i & j << endl;
      if ((i & j) <= k) {
	res ++;
      }
    }
}

void output() {
  fo << "Case #" << test << ": " << res << endl;
}
