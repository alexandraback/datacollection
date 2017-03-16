#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 10005
using namespace std;

int testcase, N;
char S[MAXN];
vector <int> V;

int main () {
  freopen("A-large.in","r",stdin);
  freopen("A.out","w",stdout);
  scanf("%d",&testcase);
  for (int TC=1;TC<=testcase;++TC) {
    scanf("%d %s",&N,S);
    V.clear();
    for (int i=0;i<strlen(S);++i)
      for (char c='1';c<=S[i];++c) V.push_back(i);
    int ans = 0;
    for (int i=0;i<(int)V.size();++i) ans = max(ans,V[i]-i);
    printf("Case #%d: %d\n",TC,ans);
  }
}
