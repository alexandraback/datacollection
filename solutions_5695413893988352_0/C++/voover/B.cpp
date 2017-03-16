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

int N;
char C[20], J[20];

LL bestC = 0, bestJ = 1LL<<62;

void go(int k, LL curC, LL curJ) {
  if (k == N) {
    if (abs(curC - curJ) > abs(bestC - bestJ)) return;
    if (abs(curC - curJ) < abs(bestC - bestJ) || PII(curC, curJ) < PII(bestC, bestJ)) {
      bestC = curC;
      bestJ = curJ;
    }
    return;
  }
  
  vector<PII> possible;
  if (curC < curJ) {
    possible.push_back(PII(C[k] == '?' ? 9 : C[k] - '0', J[k] == '?' ? 0 : J[k] - '0'));
  } else if (curC > curJ) {
    possible.push_back(PII(C[k] == '?' ? 0 : C[k] - '0', J[k] == '?' ? 9 : J[k] - '0'));
  } else if (C[k] != '?' && J[k] != '?') {
    possible.push_back(PII(C[k] - '0', J[k] - '0'));
  } else if (C[k] == '?' && J[k] == '?') {
    possible.push_back(PII(0, 0));
    possible.push_back(PII(1, 0));
    possible.push_back(PII(0, 1));
  } else if (C[k] == '?') {
    int JD = J[k] - '0';
    possible.push_back(PII(JD, JD));
    if (JD > 0) possible.push_back(PII(JD - 1, JD));
    if (JD < 9) possible.push_back(PII(JD + 1, JD));
  } else {
    int CD = C[k] - '0';
    possible.push_back(PII(CD, CD));
    if (CD > 0) possible.push_back(PII(CD, CD - 1));
    if (CD < 9) possible.push_back(PII(CD, CD + 1));  
  }
  
  FOREACH(it, possible) {
    go(k + 1, curC * 10 + it->first, curJ * 10 + it->second);
  }
}

char FORMAT[100];

void scase() {
  bestC = 0, bestJ = 1LL<<62;

  scanf("%s%s", C, J);
  N = strlen(C);
  go(0, 0, 0);
  sprintf(FORMAT, "%%0%dlld %%0%dlld\n", N, N);
  printf(FORMAT, bestC, bestJ);
}

int main() {
    int C;
    scanf("%d",&C);
    FOR(i,1,C+1) {
        printf("Case #%d: ", i);
        scase();
    }
} 
