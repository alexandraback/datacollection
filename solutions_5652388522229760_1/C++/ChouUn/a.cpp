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
 *  Name : a.cpp
 *  Date : 2016年4月9日 下午1:12:59
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

//#define M 1000010
const int P = (1 << 10) - 1;
//int a[M];

int solve(int x) {
  int res = 0;
  while (x) res|=(1<<(x%10)), x/=10;
  return res;
}

//@ Main Function
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ": ";
    int n; cin >> n;
    if (!n) { cout << "INSOMNIA" << endl; continue; }
    int c = n;
    for (int b = solve(c); b != P; c += n, b |= solve(c));
    cout << c << endl;
  }
  return 0;
}
