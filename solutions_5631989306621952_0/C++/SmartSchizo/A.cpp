#include<stdio.h>
#include<algorithm>
using namespace std;

char S[100000];
char S2[100000];
char Final[100000];

void solve(int t) {
  int i, f, l;
  scanf("%s",S);
  S2[0] = S[0];
  for(i=1;S[i];i++) S2[i] = max( S[i], S2[i-1] );
  f = 0;
  l = i;
  Final[ l-- ] = 0;
  for(i--;i>=0;i--) {
    if(S[i] == S2[i]) {
      Final[ f++ ] = S[i];
    } else {
      Final[ l-- ] = S[i];
    }
  }
  
  printf("Case #%d: %s\n",t,Final);
}

int main() {
  int t,T;
  scanf("%d",&T);
  for(t=1;t<=T;t++) solve(t);
  return 0;
}