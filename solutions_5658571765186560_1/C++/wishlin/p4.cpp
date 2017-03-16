#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  int cas,x,r,c,res;

  cin>>cas;
  for (int k=1; k<=cas; ++k) {
    cin>>x>>r>>c;
    res=0;

    if (x==1) {
      res = 1;
    }
    else if (x==2) {
      res = ((r%2==0)||(c%2==0));
    }
    else if (x==3) {
      res = ((r%3==0)||(c%3==0)) && (r>=2) && (c>=2);
    }
    else if (x==4) {
      res = ((r*c)%4==0) && (r>=3) && (c>=3);
    }
    else if (x<=6) {
      res = ((r*c)%x==0) && (r>=x-1) && (c>=x-1);
    }

    if (res) printf("Case #%d: GABRIEL\n", k);
    else printf("Case #%d: RICHARD\n", k);
  }
  return 0;
}
