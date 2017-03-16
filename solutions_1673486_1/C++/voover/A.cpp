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
#include <climits>
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

void scase(int CASEID) {
  int A, B;
  scanf("%d%d",&A,&B);
  double result = B + 2;
  double p = 1;
  FOR(i,1,A+1) {
    double x;
    scanf("%lf",&x);
    p *= x;
    result = min(result, A - i + B - i + 1 + (1 - p) * (B + 1));
  }
  printf("Case #%d: %0.9lf\n", CASEID, result);
}

int main() {
  int T;
  scanf("%d",&T);
  FOR(t,1,T+1)scase(t);
}
