#pragma comment(linker, "/STACK:256000000")
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

  long long k, n, m, p;
  string s1, s2; 
  long long a[21];
  int M, R, C, P;
  int i, j, ii, jj;
 
int doing() {
    vector<string> s(n);
    int sum_len = 0;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
      sum_len += s[i].size();
    }
    int result = 0;
    vector<int> k(n);
    while (sum_len > 0) {
      char cur = s[0][k[0]];
      vector<int> cur_k(n);
      for (int i = 0; i < n; ++i) {
        if (s[i][k[i]] != cur) {
          return -1;
        }
        while (k[i] + cur_k[i] < s[i].size() && s[i][k[i] + cur_k[i]] == cur) {
          cur_k[i]++;
        }
        k[i] += cur_k[i];
        sum_len -= cur_k[i];
      }
      sort(cur_k.begin(), cur_k.end());
      int mediana = cur_k[n/2];
      for (int i = 0; i < n; ++i) {
        result += abs(cur_k[i] - mediana);
      }
    }
    return result;
}

long long nod(long long a, long long b) {
  if (a == 0 || b == 0) {
    return max(a, b);
  } else {
    nod (b % a, a);
  }
}


int main() {
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) { 
    long long P, Q, Ql = 0;
    string s;
    scanf("%lld/%lld", &P, &Q);
    long long nd = nod(P, Q);
    P = P / nd;
    Q = Q /nd;
    while (Q % 2 == 0) {
      Ql++;
      Q = Q / 2;
    }

    cout << "Case #" << t << ": ";
    if (Q != 1) {
      cout << "impossible";
    } else {
      while (P > 1) {
        Ql--;
        P = P /2;
      }
      cout << Ql;
    }


    cout << "\n";
  }
}
