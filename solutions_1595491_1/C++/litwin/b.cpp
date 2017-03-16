#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define REP(I,N) for(int I=0;I<(N);++I)
#define FOR(I,A,B) for(int I=(A);I<=(B);++I)
#define FORD(I,A,B) for(int I=(A);I>=(B);--I)
#define FOREACH(I,C) for(__typeof((C.begin())) I=(C).begin();I!=(C).end();++I)
#define st first
#define nd second
#define mp make_pair
#define pb push_back

PII info[100];

void comp_info(int p) {
  FOR(i,0,100) 
    info[i] = mp(0, 0);
  FOR(i,0,10)
  FOR(j,0,10)
  FOR(k,0,10) {
    int mi = min(i,min(j,k));
    int mx = max(i,max(j,k));
    int sum = i + j + k;
    if (mx - mi > 2) continue;
    
    if (mx >= p) {
      info[sum].st = 1;
      if (mx - mi < 2) info[sum].nd = 1;
    }
  }
}

void solve() {
  int n, m, points;
  scanf("%d %d %d",&n,&m,&points);
  comp_info(points);
  
  int wynik = 0;
  FOR(i,1,n) {
    int x;
    scanf("%d",&x);
    if (info[x].st == 0) continue;
    if (info[x].nd == 0) {
      if (m > 0) {        
        ++wynik;
        --m;
      }
    } else {
      ++wynik;
    }
  }   		  
  printf("%d\n",wynik);
}

int main() {  
	int tests;
	scanf("%d\n",&tests);
	FOR(test,1,tests) {
		printf("Case #%d: ", test);
		solve();
	}
	return 0;
}

















