#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;
#define INF 1000000000
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);i++) 
#define FS first
#define SD second
#define MP make_pair

int C[20];
int M[20];
bool found;

void go(int idx, int a, int b) {
  if (found) return;
  if (idx == 20) {
  //  printf("%d %d\n", a, b);
    found = (a == b) && (a > 0);
  }
  else {
    C[idx] = 0;
    go(idx + 1, a, b); 
    if (found) return;
    C[idx] = 1;
    go(idx + 1, a + M[idx], b);
    if (found) return;
    C[idx] = 2;
    go(idx + 1, a, b + M[idx]);
  }
}

int main(){
  int T;scanf("%d",&T);
  FORE(test,1,T){
    printf("Case #%d:\n", test);
    int n;scanf("%d",&n);
    FOR(i,0,20) {
      scanf("%d",&M[i]); 
      C[i] = 0;
    }
    found = false;
    go(0,0,0);
    
    if (found) {
      FOR(i,0,20) {
        if (C[i] == 1) printf("%d ", M[i]); 
      }
      printf("\n");
      FOR(i,0,20) {
        if (C[i] == 2) printf("%d ", M[i]); 
      }
      printf("\n");
    }
    else {
      printf("Impossible\n"); 
    }
    
  }
}
