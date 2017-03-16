#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <map>
#include <set>

#define double long double

using namespace std;

vector< vector<int> > gr;
vector< vector<int> > matr;

long long calc(int vert) {
  if (gr[vert].empty()) {
    return 1;
  }
  long long cur = 0;
  for (int i = 0; i < gr[vert].size(); ++i) {
    cur += calc(gr[vert][i]);
  }
  return cur;
}

int main() {
  ios::sync_with_stdio(false);
  freopen("test.in", "r", stdin);
  freopen("output.txt", "w", stdout);

  int cnt_tests;
  cin >> cnt_tests;

  for (int test = 1; test <= cnt_tests; ++test) {
    long long n, m;
    cin >> n >> m;
    gr.clear();
    gr.resize(n + 1);
    matr.clear();
    matr.resize(n + 1, vector<int>(n + 1));
    for (int i = 1; i < n; ++i) {
      gr[i].push_back(i + 1);
      matr[i][i + 1] = 1;
    }

    long long ways = calc(1);

    while (ways < m) {
      int from, to;
      long long ws = -1;
      for (int i = n; i > 0; --i) {
        for (int k = n; k > i; --k) {
          if (matr[i][k]) {
            continue;
          }
          gr[i].push_back(k);
          long long cur = calc(1);
          gr[i].pop_back();
          if (cur <= m && ws < cur) {
            ws = cur;
            from = i;
            to = k;
          }
        }
      }

      if (ws == -1) {
        break;
      }
      else {
        gr[from].push_back(to);
        matr[from][to] = 1;
        ways = ws;
      }
    }

    printf("Case #%d: ", test);
    if (ways == m) {
      cout << "POSSIBLE\n";
      for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= n; ++k) {
          cout << matr[i][k];
        }
        cout << endl;
      }
    }
    else {
      cout << "IMPOSSIBLE\n";
    }

  }

  return 0;
}