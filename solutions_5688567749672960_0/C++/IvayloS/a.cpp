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

int rev(int x) {
  int res = 0;
  while (x) {
    res = res * 10 + x % 10;
    x /= 10;
  }

  return res;
}
int main() {
  // freopen("temp.txt", "w", stdout);
  const int size = 1000010;
  vector<int> vis(size, -1);
  vector<int> dad(size);

  queue<int> q;
  q.push(1);
  dad[1] = 1;
  vis[1] = 1;
  while (!q.empty()) {
    int c = q.front();
    q.pop();
    int v = c + 1;
    if (v < size && vis[v] == -1) {
      vis[v] = vis[c] + 1;
      dad[v] = c;
      q.push(v);
    }

    int t = rev(c);
    if (t < size && vis[t] == -1) {
      vis[t] = vis[c] + 1;
      dad[t] = c;
      q.push(t);
    }
  }

//    for (int i = 1; i < size; ++i) {
//      printf("%d: %d dad: %d\n", i, vis[i], dad[i]);
//    }

  freopen((PROGRAM_NAME + ".in").c_str(), "r", stdin);
  freopen((PROGRAM_NAME + ".out").c_str(), "w", stdout);
  int nt;
  cin >> nt;
  for (int it = 1; it <= nt; it++) {
    int n;
    cin >> n;
    cout << "Case #" << it << ": " << vis[n] << endl;
  }

  return 0;
}
