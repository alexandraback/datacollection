#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int tt;
int x, r, c;

int main(void){
  int i, j;
  bool rWin;
  scanf("%d", &tt);
  for(int tc=1; tc<=tt; ++tc){
    scanf("%d%d%d", &x, &r, &c);
    rWin = false;
    if(x >= 7 || (x+1)/2 > min(r, c) || (r*c)%x != 0){
      rWin = true;
    }else if((x+1)/2 == min(r, c) && x >= 4){
      rWin = true;
    }

    if(rWin){
      printf("Case #%d: RICHARD\n", tc);
    }else{
      printf("Case #%d: GABRIEL\n", tc);
    }
  }
  return 0;
}
