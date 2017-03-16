#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int X,R,C;

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    bool richard = false;
    cin >> X >> R>> C;
    if(X==1) richard = true;
    else if(X==2) {
      if( ((R*C)%2)==0) richard = true;
    }
    else {
      if( ((R*C) % X) ==0 && (R>=X || C >=X) && (R > X/2 && C> X/2)) {
        richard = true;
      }
    }
    if(richard)
      printf("Case #%d: GABRIEL\n",tc);
    else
      printf("Case #%d: RICHARD\n",tc);


  }

  return 0;
}