#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstring>

using namespace std;

void run() {
  char S[1001];
  scanf("%1000s",S);
  int l=strlen(S);
  while (l>0) {
    int x=l-1;
    int maxp=x;
    char maxc=S[x];
    while (--x>=0) {
      if (S[x]>maxc) { maxc=S[x]; maxp=x; }
    }
    putchar(maxc);
    S[maxp]=' ';
    l=maxp;
  }
  l=strlen(S);
  for (int i=0;i<l;++i) if (S[i]!=' ') putchar(S[i]);
  printf("\n");
}

int main() {
  int T;
  scanf("%d",&T);
  for (int t=1;t<=T;++t) {
    printf("Case #%d: ",t);
    run();
  }
  return 0;
}
