#include <algorithm>
#include <assert.h>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <numeric>
#include <limits>
#include <iomanip>
using namespace std;

#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define LL long long
#define LD long double
#define vi vector<int>
#define vl vector<LL>
#define vs vector<string>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>
#define SET(v, i) (v | (1 << i))
#define TEST(v, i) (v & (1 << i))
#define TOGGLE(v, i) (v ^ (1 << i))

bool Valid(const vs& ip, const vi& top) {
  string s;
  for (int i = 0; i < sz(ip); ++i)
    s += ip[top[i]];

  vb visited(26);
  int i = 0;
  while (i < sz(s)) {
    if (visited[s[i] - 'a'])
      return false;

    visited[s[i] - 'a'] = true;

    int j = i + 1;
    for (; j < sz(s) && s[j] == s[i]; ++j) {}

    if (j == sz(s)) break;
//    if (std::find(s.begin() + j, s.end(), s[i]) != s.end())
//      return false;
    i = j;
  }

  return true;
}

int Solve(vs& ip) {
  vi top(sz(ip));
  for (int i = 0; i < sz(ip); ++i)
    top[i] = i;

  int ret = 0;
  do {
    if (Valid(ip, top))
      ++ret;
  } while (next_permutation(all(top)));

  return ret;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
//    cout << i << endl;

    int n;
    cin >> n;
    vs ip(n);
    for (int j = 0; j < n; ++j)
      cin >> ip[j];

    sort(all(ip));
    int ret = Solve(ip);
    printf("Case #%d: %d\n", i, ret);
  }
  return 0;
}
