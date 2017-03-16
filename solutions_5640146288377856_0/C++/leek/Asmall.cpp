#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int R,C,W;

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    scanf("%d %d %d", &R, &C, &W);
    int eachrow = C/W;
    int ret = R*eachrow;
    if(C%W == 0)
      ret += W-1;
    else ret += W;

    printf("Case #%d: %d\n",tc,ret);
  }

  return 0;
}