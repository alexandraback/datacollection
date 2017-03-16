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

vector<pair<LL, LL>> hikers;

LL get(LL T) {
  LL result = 0;
  REP(i, hikers.size()) {
    if (hikers[i].st >= T) {
      result += 1;
    } else {
      result += (T - hikers[i].st) / hikers[i].nd;
    }
  }
  return result;
}

void scase() {
  hikers.clear();
  
  int N;
  scanf("%d", &N);
  REP(i,N) {
    int D, H, M;
    scanf("%d%d%d", &D, &H, &M);
    REP(j, H) {
      hikers.push_back(mp(2 * (360 - D) * (LL)(M + j), 2 * 360 * (LL)(M + j)));
    }
  }
  
  LL result = hikers.size();
  result = min(result, get(1));
  REP(i, hikers.size())for(int j = -1; j < 2; ++j) {
    result = min(result, get(hikers[i].st + j));
  }

  printf("%lld\n", result); 
}

int main() {
  int Z;
  scanf("%d", &Z);
  REP(z,Z) {
    printf("Case #%d: ", z+1);
    scase();
  }
}    
