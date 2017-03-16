#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int numTC, TC = 1, X, R, C;
  scanf("%d", &numTC);
  while(numTC--){
    scanf("%d %d %d", &X, &R, &C);
    if(X==1){ printf("Case #%d: GABRIEL\n", TC++); continue; }
    if(X==2){
      printf("Case #%d: %s\n", TC++, ((R*C)&1)? "RICHARD": "GABRIEL"); continue;
    }
    if((R*C)%X){ printf("Case #%d: RICHARD\n", TC++); continue; }
    if(X>2 && X<7){
      printf("Case #%d: %s\n", TC++, min(R, C)>=X-1? "GABRIEL": "RICHARD");
    } else printf("Case #%d: RICHARD\n", TC++);
  }
  return 0;
}
