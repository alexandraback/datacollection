#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

LL get(LL S, LL N) {  
  LL result = 0;
  while (S * 10 <= N) {
    result += get(S, 10 * S - 1) + 1;
    S = 10 * S;
  }
  
  if (N == S) {
    return result;
  }
  
  if (N % 10 == 0) {
    return result + 1 + get(S, N - 1);
  }
  
  LL right = N - S;
  LL tmp = right;
  LL tmpN = N;
  LL left = 0;
  int D = 0;
  while (tmpN > 0) {
    ++D;
    left = 10 * left + (tmp % 10);
    tmp /= 10;
    tmpN /= 10;
  }
  
  LL p10[17];
  p10[0] = 1;
  FOR(i,1,17) {
    p10[i] = p10[i-1] * 10;
  }
  LL res2 = N - S;
  REP(i,D+1) {
    res2 = min(res2, left % p10[i] + right % p10[D - i] + (i == 0 ? 0 : 1));
  }
  
  return result + res2;
}

void scase() {
  LL N;
  scanf("%lld", &N);
  printf("%lld\n", get(1, N) + 1);
}

int main() {
  int Z;
  scanf("%d", &Z);
  REP(z,Z) {
    printf("Case #%d: ", z+1);
    scase();
  }
}    
