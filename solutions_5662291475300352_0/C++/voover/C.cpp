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

vector<pair<int, LL>> hikers;

void scase() {
  hikers.clear();
  
  int N;
  scanf("%d", &N);
  REP(i,N) {
    int D, H, M;
    scanf("%d%d%d", &D, &H, &M);
    REP(j, H) {
      hikers.push_back(mp(D, (M + j)));
    }
  }
  
  if (hikers.size() == 1) {
    printf("%d\n", 0);
    return;
  }
  
  LL T1 = hikers[0].nd * (360 - hikers[0].st);
  LL T2 = hikers[1].nd * (360 - hikers[1].st);
  LL T = max(T1, T2);
  if ((T >= T1 + 360 * hikers[0].nd) || (T >= T2 + 360 * hikers[1].nd)) {
    printf("%d\n", 1);
  } else {
    printf("%d\n", 0);
  }
}

int main() {
  int Z;
  scanf("%d", &Z);
  REP(z,Z) {
    printf("Case #%d: ", z+1);
    scase();
  }
}    
