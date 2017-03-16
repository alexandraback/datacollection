//@ Including Header
// Name : ChouUn's Standard Library 纸农の标准库
// Copyright : fateud.com
#ifndef CSL_STD_H_
#define CSL_STD_H_ 20151122L
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<pii> vpii;

#define rep(i,a,b) for(auto i=a,i##_n=b;i<i##_n;++i)
#define rrep(i,a,b) for(auto i=b,i##_n=a;i-->i##_n;)

#endif /* CSL_STD_H_ */


/**
 *  Name : d.cpp
 *  Date : 2016年4月9日 下午3:39:14
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ":";
    ll k, c, s; cin >> k >> c >> s;
    if ((k + c - 1) / c > s) { cout << " IMPOSSIBLE" << endl; continue; }
    ll m = (k + c - 1) / c, i = 0;
    while (m--) {
      ll ans = 0;
      rep(j, 0ll, c) ans = ans * k + (i == k - 1 ? i : i++);
      cout << " " << ans + 1;
    }
    cout << endl;
  }
  return 0;
}

