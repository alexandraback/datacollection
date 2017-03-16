#include <cstdio>
#include <cassert>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;


unsigned int a, b, k;

typedef long long int int64;


char sa[33], sb[33], sk[33];

int64 count(int ta, int va, int tb, int vb, int tk, int vk) {
  int64 cnt = 0;
  for (int x = 0; x <= 1; x++) {
    if ((ta == 0) && (va != x))
      continue;
    for (int y = 0; y <= 1; y++) {
      if ((tb == 0) && (vb != y))
        continue;
      for (int z = 0; z <= 1; z++) {
        if ((tk == 0) && (vk != z))
          continue;
        if ((x & y) == z)
          cnt++;
      }
    }
  }
  return cnt;
}


int main() {
  
  int tests;
  assert(scanf("%d", &tests) == 1);
  for (int test = 0; test < tests; test++) {
    printf("Case #%d: ", test + 1);
    assert(scanf("%u %u %u", &a, &b, &k) == 3);     
    for (int i = 0; i <= 31; i++) {
      sa[31 - i] = '0' + ((a & (1u << i)) >> i);
      sb[31 - i] = '0' + ((b & (1u << i)) >> i);
      sk[31 - i] = '0' + ((k & (1u << i)) >> i);
    }
    sa[32] = sb[32] = sk[32] = 0;
    //printf("%s\n%s\n%s\n", sa, sb, sk);
    int64 ans = 0;
    for (int ia = 0; ia < 32; ia++) {
      if (sa[ia] == '0')
        continue;
      for (int ib = 0; ib < 32; ib++) {
        if (sb[ib] == '0')
          continue;
        for (int ik = 0; ik < 32; ik++) {
           if (sk[ik] == '0')
             continue;
           int64 p = 1;
           for (int j = 0; j < 32; j++) {
             int ta, tb, tk; //0 - const, 1 - variable
             int va = 0, vb = 0, vk = 0;
             
             if (j < ia) {
               ta = 0;
               va = sa[j] - '0';
             }
             else if (j == ia) {
               ta = 0;
               va = 0;
             }
             else {
               ta = 1;
             }
             
             if (j < ib) {
               tb = 0;
               vb = sb[j] - '0';
             }
             else if (j == ib) {
               tb = 0;
               vb = 0;
             }
             else
               tb = 1;
             
             if (j < ik) {
               tk = 0;
               vk = sk[j] - '0';
             }
             else if (j == ik) {
               tk = 0;
               vk = 0;
             }
             else
               tk = 1;
             p = p * count(ta, va, tb, vb, tk, vk);
           }
           ans += p;
        }
      }      
    }
    printf("%lld\n", ans);
  }
  
  return 0;
}