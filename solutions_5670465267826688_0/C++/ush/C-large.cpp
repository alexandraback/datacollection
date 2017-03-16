
#include <cassert>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
using namespace std;
typedef long long ll;

int vs[1010];

inline int calc(int x, int y) {
  if(x < 0)
    return -calc(-x, y);
  if(y < 0)
    return -calc(x, -y);
  if(x == '1')
    return y;
  if(y == '1')
    return x;
  if(x == y)
    return -'1';
  if(x == 'i'){
    if(y == 'j'){
      return 'k';
    }else if(y == 'k'){
      return -'j';
    }else{
      assert(false);
    }
  }
  if(x == 'j'){
    if(y == 'k'){
      return 'i';
    }else if(y == 'i'){
      return -'k';
    }else{
      assert(false);
    }
  }
  if(x == 'k'){
    if(y == 'i'){
      return 'j';
    }else if(y == 'j'){
      return -'i';
    }else{
      assert(false);
    }
  }
  assert(false);
}

inline int POW(int x, ll n) {
  int res = '1';
  while(n > 0){
    if(n & 1)
      res = calc(res, x);
    x = calc(x, x);
    n /= 2;
  }
  return res;
}

int csum[10005];
int rsum[10005];
char buf[10005];

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase){
    int n;
    ll rep;
    scanf("%d%lld", &n, &rep);
    scanf("%s", buf);
    printf("Case #%d: ", iCase+1);
    
    csum[0] = '1';
    REP(i, n){
      csum[i+1] = calc(csum[i], buf[i]);
    }
    rsum[n] = '1';
    for(int i = n-1; i >= 0; --i){
      rsum[i] = calc(buf[i], rsum[i+1]);
    }
    
    ll k = rep*2;
    int i1 = -1;
    REP(i, 9*n){
      int v1 = calc(POW(csum[n], i/n), csum[i%n]);
      if(v1 == 'i'){
	k -= i/n*2 + (i%n ? 1 : 0);
	i1 = i;
	break;
      }
    }
    if(i1 < 0 || i1 >= n*rep){
      puts("NO");
      continue;
    }

    int i3 = -1;
    REP(i, 9*n){
      int v3 = calc(rsum[n-i%n], POW(csum[n], i/n));
      if(v3 == 'k'){
	k -= i/n*2 + (i%n ? 1 : 0);
	i3 = i;
	break;
      }
    }
    
    if(i3 < 0 || i3 >= n*rep || i1 + i3 >= n*rep){
      puts("NO");
      continue;
    }
    
    int v2 = '1';
    if(k/2 == 0){
      int bg = i1%n;
      int ed = n - i3%n;
      for(int i = bg; i < ed; ++i){
	v2 = calc(v2, buf[i]);
      }
      
    }else{
      if(i1%n != 0){
	v2 = rsum[i1%n];
      }
      
      v2 = calc(v2, POW(csum[n], k/2));
      
      if(i3%n != 0){
	v2 = calc(v2, csum[n-i3%n]);
      }
    }

    
    
    
    puts(v2 == 'j'? "YES" : "NO");
  }
  return 0;
}
