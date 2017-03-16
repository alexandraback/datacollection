#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 10005
#define WIN 1
#define FAIL 0
using namespace std;

int testcase, X,R,C;

void done(int TC,bool res) {
  printf("Case #%d: %s\n",TC,(res==WIN)?"GARBIEL":"RICHARD");
}

int main () {
  freopen("D-small-attempt0.in","r",stdin);
  freopen("D.out","w",stdout);
  scanf("%d",&testcase);
  for (int TC=1;TC<=testcase;++TC) {
    scanf("%d%d%d",&X,&R,&C);
    if (X >= 7 || max(R,C) < X || (X+1)/2 > min(R,C) || ((R*C) % X != 0) ) done(TC,FAIL);
    else if ((X+1)/2 < min(R,C)) done(TC,WIN);
    else {
      int A = min(R,C), B = max(R,C);
      int V = X - A, L = V+1;
      bool ok = 1;
      for (int i=0;i<=V;++i) {
        int t1 = V * i, t2 = V * (V-i);
        bool can = 0;
        for (int j=0;j<=B-L;++j) {
          int p = t1 + A * j, q = t2 + A * (B-L-j);
          if ((p % X == 0) && (q % X == 0)) {
            can = 1;
            break;
          }
        }
        if (!can) ok = 0;
      }
      done(TC,ok);
    }
  }
}
