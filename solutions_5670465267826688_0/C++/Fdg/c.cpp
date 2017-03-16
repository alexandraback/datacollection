/* 
  2014.03.26 15:10
  http://codeforces.ru/gym/100289/
*/


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
#include <cmath>
#include <string> 
#include <ctime>

using namespace std;

#undef Fdg_Home

int what[255];
int mat[5][5] = {{1, 2, 3, 4},
                 {2, -1, 4, -3},
                 {3, -4, -1, 2},
                 {4, 3, -2, -1}};

char str[10002];

void solveTest(int CS) {
  printf("Case #%d: ", CS);
  what['i'] = 2; what['j'] = 3; what['k'] = 4;
  long long l, x;
  cin >> l >> x >> str;
  int res = 1;
  for (int i = 0; i < l; ++i) {
    res = mat[abs(res) - 1][what[str[i]] - 1] * (res < 0 ? -1 : 1);
  }
  int mult = res; res = 1;
  for (int i = 0; i < x % 4; ++i) {
    res = mat[abs(res) - 1][abs(mult) - 1];
  }
  if (x % 2 == 1 && mult < 0) res = -res;
  // cout << res << endl;
  long long p1 = 0, p2 = x * l - 1, it1 = 0, it2 = l - 1;
  int pref = 1;
  for (int i = 0; i < 1000000; ++i) {
    pref = mat[abs(pref) - 1][what[str[it1]] - 1] * (pref < 0 ? -1 : 1);
    // cout << pref << endl;
    if (pref == 2) break;
    p1++; it1++;
    if (it1 == l) it1 = 0;
  }
  int suf = 1;
  for (int i = 0; i < 1000000; ++i) {
    suf = mat[what[str[it2]] - 1][abs(suf) - 1] * (suf < 0 ? -1 : 1);
    // cout << suf << endl;
    if (suf == 4) break;
    p2--; it2--;
    if (it2 == -1) it2 = l - 1;
  }
  // cout << res << endl;
  if (pref == 2 && suf == 4 && res == -1 && p1 < p2) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
#ifndef Fdg_Home
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  scanf("%d\n", &T);
  for (int test = 1; test <= T; ++test) {
    solveTest(test);
  }
  return 0;
}