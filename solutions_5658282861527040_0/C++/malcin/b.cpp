#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

unsigned long long licz(unsigned ma, int ia, unsigned mb, int ib, unsigned k){
  if ((ma & mb) > k)
    return 0ULL;
  if (ia < ib){ swap(ia,ib); swap(ma,mb); }
  if (k >= ((ma & mb) + (1u << ia)))
    return (1ULL << (ia + ib));
  unsigned long long r = 0ULL;
  unsigned long long mult = 1ULL;
  FORD(i, ia-1, 0){
    if (i >= ib){
      if (k & (1u << i)){
        if (mb & (1u << i))
          r += mult * (1ULL << (ib + i));
        else{
          r += mult * 2ULL * (1ULL << (ib + i));
          return r;
        }
      } else {
        if (!(mb & (1u << i)))
         mult *= 2ULL;
      }
    } else {
      if (k & (1u << i)){
        r += mult * 3ULL * (1ULL << (i + i));
      } else {
        mult *= 3ULL;
      }
    }
  }
  r += mult;
  return r;
}

unsigned long long rob(unsigned a, unsigned b, unsigned k){
  unsigned long long r = 0u;
  unsigned ma = 0u;
  FORD(ia, 30, 0)
    if ((ma + (1u << ia)) <= a){
      unsigned mb = 0u;
      FORD(ib, 30, 0){
        if ((mb + (1u << ib)) <= b){
          r += licz(ma, ia, mb, ib, k);
          mb += (1u << ib);
        }
      }
      ma += (1u << ia);
    }
  return r;
}


int main(){
  int te; scanf("%d", &te);
  FOR(ii,1,te){
    unsigned a, b, k;
    scanf("%u%u%u", &a, &b, &k); --k;
    unsigned long long r = rob(a,b,k);
    printf("Case #%d: %llu\n", ii, r);
  }
	return 0;
}
