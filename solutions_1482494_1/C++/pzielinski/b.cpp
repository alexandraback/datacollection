#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i = 0; i < (n); ++i)
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define FORE(it, V) for (__typeof(V.begin()) it = V.begin(); it != V.end(); ++it)

#define PB push_back
#define FI first
#define SE second
#define MP make_pair

typedef long long LL;

const int MAXN = 5005;
int wziety[MAXN];
int cost[MAXN][2];

void testcase() {
  int n;
  scanf("%d", &n);
  REP(i,n) {
    scanf("%d%d", &cost[i][0], &cost[i][1]);
    wziety[i] = 0;
  }

  int res = 0;
  int kasa2 = 0;
  int kasa = 0;
  do {
    kasa2 = kasa;
    REP(i,n) {
      if (wziety[i] == 2) continue;
      if (kasa >= cost[i][1]) {
	if (wziety[i] == 1) ++kasa;
	else kasa += 2;
	wziety[i] = 2;
	++res;
      }
    }
    if (kasa2 != kasa) { continue; }

    int maksior = -1, index = -1;
    REP(i,n) {
      if (wziety[i]) continue;
      if (kasa >= cost[i][0]) {
	if (cost[i][1] > maksior) {
	  maksior = cost[i][1];
	  index = i;
	}
      }
    }

    if (maksior == -1) break;
    ++kasa; ++res;
    wziety[index] = 1;

  } while (kasa != kasa2);
  if (kasa == 2*n) {
    printf("%d\n", res);
  } else {
    printf("Too Bad\n");
  }
}

int main() {
  int t;
  scanf("%d", &t);
  FOR(i,1,t) {
    printf("Case #%d: ", i);
    testcase();
  }
}
