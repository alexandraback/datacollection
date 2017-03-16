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
  int N;
  scanf("%d",&N);
  int A[N], B[N], completed[N];
  REP(i,N) {
    scanf("%d%d",&A[i], &B[i]);
    completed[i] = 0;
  }
  
  int points = 0;
  int games = 0;
  int bestB;
  while(points < 2*N) {     
    REP(i,N) {
      if (completed[i] < 2 && B[i] <= points) {
        ++games;       
        points += 2 - completed[i];
        completed[i] = 2;
        goto ok;
      }
    }
    bestB = -1;
    REP(i,N) {
      if (completed[i] == 0 && A[i] <= points) {
        if (bestB == -1 || B[i] > B[bestB]) bestB = i;
      }    
    }
    if (bestB == -1) break;
    
    completed[bestB] = 1;
    ++points;
    ++games;
    
    ok:;
  }
  
  if (points < 2 * N) 
    printf("Case #%d: Too Bad\n", CASEID);  
  else
    printf("Case #%d: %d\n", CASEID, games);
}

int main() {
  int T;
  scanf("%d",&T);
  FOR(t,1,T+1)scase(t);
}
