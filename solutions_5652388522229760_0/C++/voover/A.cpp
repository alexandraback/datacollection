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

void scase() {
  int N;
  scanf("%d", &N);
  if (N == 0) {
    printf("INSOMNIA\n");
    return;
  }
  
  int M = N;
  int mask = 1023;
  while (true) {
    int M2 = M;
    while (M2 > 0) {
      mask = mask & ~(1 << (M2 % 10));
      M2 /= 10;
    }
    if (!mask) break;
    M += N;
  }
  printf("%d\n", M);
}

int main() {
    int C;
    scanf("%d",&C);
    FOR(i,1,C+1) {
        printf("Case #%d: ", i);
        scase();
    }
} 
