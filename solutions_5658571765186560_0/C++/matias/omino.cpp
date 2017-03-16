#include<iostream>
#include<cstdio>

using namespace std;

int main() {
  int T;
  cin>>T;
  for (int t=1;t<=T;t++) {
    int X,R,C;
    cin>>X>>R>>C;
    if (R>C) {
      int tmp = C;
      C = R;
      R = tmp;
    }
    int ok = 1;
    if ((R*C)%X != 0) ok = 0;
    if (X > 6) ok = 0;
    if (X > C) ok = 0;
    if ((X+1)/2 > R) ok = 0;
    if (R*2 == X && R>1) ok = 0;
    if (R*2 == X-1 && R==3) ok = 0;
    printf("Case #%d: %s\n", t,ok?"GABRIEL":"RICHARD");
  }
}
