#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <cassert>
#define MAXN 1005
using namespace std;

int testcase, N, A[MAXN];

int main () {
  freopen("B-large.in","r",stdin);
  freopen("B.out","w",stdout);
  scanf("%d",&testcase);
  for (int TC=1;TC<=testcase;++TC) {
    scanf("%d",&N);
    for (int i=0;i<N;++i) scanf("%d",&A[i]);
    int ans = MAXN;
    for (int z=1;z<MAXN;++z) {
      int cnt = 0;
      for (int i=0;i<N;++i) cnt += (A[i]-1)/z;
      ans = min(ans,cnt+z);
    }
    printf("Case #%d: %d\n",TC,ans);
  }
}
