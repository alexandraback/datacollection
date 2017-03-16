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

const int N = 2000000; 
int min_lex[N + 100];
int ile[N + 100];

void comp() {
  FOR(i,0,N) {
    int mlex = i;
    int mod = 10;
    int mno = 1;
    
    int digit = 0;
    int x = i;
    while (x) { 
      ++digit; 
      x /= 10;
      mno *= 10;
    }
    
    FOR(step, 1, digit - 1) { 
      mno /= 10;     
      int pref = i / mod;
      int suf = i % mod;      
      if (suf >= (mod / 10)) {
        int cand = suf * mno + pref;
        mlex = min(cand, mlex);      
      }
      mod *= 10;    
    }
    min_lex[i] = mlex;
  }
}

void solve() {
	int A, B;
	scanf("%d %d\n",&A, &B);	
  FOR(i,A,B) {
    ++ile[min_lex[i]];
  }	
  LL wynik = 0;
  FOR(i,0,N) {
    wynik += ((LL)ile[i] * ((LL)ile[i] - 1LL)) / 2LL;
    ile[i] = 0;
  }
  cout << wynik << endl;
}

int main() {
  comp();
	int tests;
	scanf("%d\n",&tests);
	FOR(test,1,tests) {
		printf("Case #%d: ", test);
		solve();
	}
	return 0;
}

















