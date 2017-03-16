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


int visited[1009];
int first[1009];
int second[1009];

void solve() {
  int n;
  scanf("%d",&n);		
  FOR(i,1,n) {
    visited[i] = 0;
    scanf("%d%d",&first[i],&second[i]);
  }
  int stars = 0;  
  int wynik = 0;
  while (stars < 2*n) {
    int bestvisit = 0;
    int bestid = 0;
    bool cont = false;
    FOR(i,1,n) {
      if (visited[i] == 2) continue;            
      if (visited[i] == 1) {
        if (second[i] <= stars) {
          ++stars;
          ++wynik;
          visited[i] = 2;
          cont = true;
          break;
        }
      } else if (visited[i] == 0) {
        if (first[i] <= stars) {
          if (second[i] <= stars) {
            bestid = i; bestvisit = 2;
          } else if (bestvisit == 0) {
            bestid = i; bestvisit = 1;
          } else if (bestvisit == 1 && second[bestid] < second[i]) {
            bestid = i; bestvisit = 1;
          }
        }
      }
    }
    if (cont) continue;    
    if (!bestid) { printf("Too Bad\n"); return; }
    visited[bestid] = bestvisit;
    stars += bestvisit;
    ++wynik;
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

















