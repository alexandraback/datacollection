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

vector<int> digs(ll a) {
  vector<int> res;
  while (a) {
    res.push_back(a % 10);
    a /= 10;
  }

  reverse(all(res));
  return res;
}

const int size = 1010;
vector<int> vis(size, -1);
vector<int> dad(size);

void pc() {
  vis.clear();
  vis.resize(size, -1);
  dad.clear();
  dad.resize(size);
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
}

ll solve(ll a) {
  if (a <= 1000) {
    return vis[(int)a];
  }
  vector<int> d = digs(a);

  int num = (int)d.size();
  vector<int> temp = d;
  for (int i = num / 2; i < num; ++i) {
    temp[i] = 0;
  }
  temp[num - 1] = 1;
  ll par = 0;
  for (int i = 0; i < (int)temp.size(); ++i) {
    par = par * 10LL + temp[i];
  }

  if (par == a) {
    ll next = 0;
    ll opar = par;
    while (par) {
      next = next * 10LL + par % 10LL;
      par /= 10LL;
    }

    if (next == opar) {
      return 1 + solve(a - 1);
    } else {
      return 1 + solve(next);
    }
  }

  if (par > a) {
    for (int i = num / 2 - 1; i >= 0; --i) {
      if ((i > 0 && temp[i] > 0) || (i == 0 && temp[i] > 1)) {
        temp[i]--;
        for (int j = i + 1; j < num/2; ++j) {
          temp[j] = 9;
        }
        par = 0;
        for (int it = 0; it < (int)temp.size(); ++it) {
          par = par * 10LL + temp[it];
        }
        break;
      }
    }

    if (par > a) {
      par = 0;
      for (int i = 0; i < num - 1; ++i) {
        par = par * 10LL + 9LL;
      }
      return solve(par) + a - par;
    }
  }

  ll ans = a - par;
  ll next = 0;
  ll opar = par;
  while (par) {
    next = next * 10LL + par % 10LL;
    par /= 10LL;
  }

  if (next != opar) {
    return ans + 1 + solve(next);
  } else {
    return ans + solve(next);
  }
}

int main() {
//
//
//  for (int i = 1; i < size; ++i) {
//// printf("%d: %d dad: %d\n", i, vis[i], dad[i]);
//    if (dad[i] != i - 1) {
//      fprintf(stderr, "%d: %d dad: %d\n", i, vis[i], dad[i]);
//    }
//  }

  pc();
  freopen((PROGRAM_NAME + ".in").c_str(), "r", stdin);
  freopen((PROGRAM_NAME + ".out").c_str(), "w", stdout);
  int nt;
  cin >> nt;
  for (int it = 1; it <= nt; it++) {
    ll n;
    cin >> n;
    cout << "Case #" << it << ": " << solve(n) << endl;
  }

  return 0;
}
