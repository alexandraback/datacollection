#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstring>

using namespace std;

void run() {
  char s[1000];
  scanf("%999s",s);
  int pos=strlen(s)-1;
  char curr='+';
  int sol=0;
  while (pos>=0) {
    assert(s[pos]=='+' || s[pos]=='-');
    if (curr!=s[pos]) {
      ++sol;
      curr=s[pos];
    }
    --pos;
  }
  printf("%d\n",sol);
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
