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

// Name : Algorithm 算法
// Copyright : fateud.com
#ifndef CSL_ALGO_H_
#define CSL_ALGO_H_ 20150917L
#include <cmath>
#include <vector>
namespace csl {
  static double M_EPS = 1e-8;
  /**
   * the sign of x is positive or nagetive
   * return -1 means less, 0 means equal, 1 means greater
   */
  inline int sgn(double x) {
    return std::fabs(x) < M_EPS ? 0 : (x < 0 ? -1 : 1);
  }
  /**
   * compare between double a and double b
   * return -1 means less, 0 means equal, 1 means greater
   */
  inline int cmp(double a,double b) {
    return sgn(a - b);
  }

  /**
   * return the minimum between double x and y
   */
  template<typename _Tp>
  struct min {
    const _Tp& operator ()(const _Tp& x,const _Tp& y) const {
      return x < y ? x : y;
    }
  };
  /**
   * return the maximum between double x and y
   */
  template<typename _Tp>
  struct max {
    const _Tp& operator ()(const _Tp& x,const _Tp& y) const {
      return x > y ? x : y;
    }
  };

  /**
   * calc the lowest factor of number (with prime & phi & mu)
   */
  namespace prime {
    std::vector<int> mu;
    std::vector<std::size_t> phi, div, prm;
    void build(std::size_t n) {
      mu.assign(n, 0), mu[1] = 1, phi.assign(n, 0), phi[1] = 1;
      div.assign(n, 0), prm.clear(), prm.reserve(n >> 3);
      for(std::size_t i = 2; i < n; ++i) {
        if(!div[i]) mu[i] = -1, phi[i] = i - 1, div[i] = i, prm.push_back(i);
        for(std::size_t j = 0, m = prm.size(), k; j < m; ++j) {
          if((double)i * prm[j] >= n) break;
          div[k = i * prm[j]] = prm[j];
          if(i % prm[j] == 0) {
            phi[k] = phi[i] * prm[j], mu[k] = 0;
            break;
          }
          else mu[k] = -mu[i], phi[k] = phi[i] * (prm[j] - 1);
        }
      }
    }
  } // namespace prime

  /**
   * minimum isomorphic representation of string
   */
  template<typename _Tp,typename _Comp>
  std::size_t isomorph_min(_Tp data[],std::size_t size,_Comp comp) {
    std::size_t i = 0, j = 1;
    for(std::size_t k; i < size && j < size;) {
      for(k = 0; data[i + k] == data[j + k] && k < size; ++k)
        ;
      if(k == size) return i;
      if(comp(data[j + k], data[i + k])) std::swap(i, j);
      j = std::max(j + k + 1, i + 1);
    }
    return i;
  }
  /**
   * maximum isomorphic representation of string
   */
  template<typename _Tp,typename _Comp>
  std::size_t isomorph_max(_Tp data[],std::size_t size,_Comp comp) {
    std::size_t i = 0, j = 1;
    for(std::size_t k, p = -1; i < size && j < size;) {
      for(k = 0; data[i + k] == data[j + k] && k < size; ++k)
        ;
      if(k == size) {
        i = std::max(i, j);
        if(~p) for(p = i - p; i + p < size; i = i + p)
          ;
        j = i + 1, p = i;
      }
      else {
        if(comp(data[j + k], data[i + k])) std::swap(i, j);
        j = std::max(j + k + 1, i + 1);
      }
    }
    return i;
  }

} // namespace csl
#endif /* CSL_ALGO_H_ */

/**
 *  Name : c.cpp
 *  Date : 2016年4月9日 下午2:13:11
 *  Copyright : fateud.com
 *  Anti-Mage : The magic ends here.
 */

typedef unsigned uint;
#define J 510

int n, j;
set<uint> ans;
int fac[9];

bool test(uint m, int base, uint p) {
  uint r = 0;
  rrep(i, 0, n) r = (r * base + ((m >> i) & 1)) % p;
  return r == 0;
}

//@ Main Function
int main() {
  csl::prime::build(10000);
  auto prm = csl::prime::prm;

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _, __ = 1;
  for(std::cin >> _; _; --_, ++__) {
    std::cout << "Case #" << __ << ":" << endl;
    cin >> n >> j;
    ans.clear();
    std::random_device dev;
    std::uniform_int_distribution<uint> ran(0, 1U << (n - 2));
    while (ans.size() != (uint)j) {
      uint m = (1u << (n - 1)) | (ran(dev) << 1) | 1;

      bool flag = true;
      rep(i, 0, 9) {
        uint ok = 0;
        rep(k, 0u, prm.size())
          if (test(m, i + 2, prm[k])) { ok = prm[k]; break; }
        if (!ok) { flag = false; break; }
        fac[i] = ok;
      }
      if (!flag) continue;

      if (ans.insert(m).second == false) continue;
      rrep(i, 0, n) cout << ((m >> i) & 1);
      rep(i, 0, 9) cout << " " << fac[i];
      cout << endl;
    }
  }
  return 0;
}
