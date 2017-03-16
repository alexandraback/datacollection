#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct SLevel{
  int lv1, lv2;
  bool stat1, stat2;
};

bool compfunc(SLevel a, SLevel b){
  if(a.lv2 > b.lv2 || (a.lv2 == b.lv2 && a.lv1 < b.lv1)) return true;
  return false;
}

int main(){
  int jcase;
  int N;
  SLevel lv[1001];
  bool inc, loop;
  int ans;

  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase = 0; icase < jcase; icase++){
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d %d", &lv[i].lv1, &lv[i].lv2);
    
    for(int i=0; i<N; i++) lv[i].stat1 = lv[i].stat2 = false;
    
    sort(lv, lv+N, compfunc);
    
    //for(int i=0; i<N; i++) printf("%d %d\n", lv[i].lv1, lv[i].lv2);
    //getch();
    
    int star = ans = 0;
    while(1){
      inc = loop = false;
      for(int i=0; i<N; i++){
        if(lv[i].lv2 <= star && !lv[i].stat2){
          lv[i].stat2 = true;
          if(lv[i].stat1){
            star += 1;
    //        printf("C2 on %d\n", i);
          }
          else{
            lv[i].stat1 = true;
            star += 2;
    //        printf("C1 C2 on %d\n", i);
          }
          inc = true;
          ans += 1;
        }
      }
      
      for(int i=0; i<N; i++){
        if(!lv[i].stat2){
          loop = true;
          break;
        }
      }
      if(!loop) break;
      if(inc) continue;
      
      for(int i=0; i<N; i++){
        if(lv[i].lv1 <= star && !lv[i].stat1){
          lv[i].stat1 = true;
          star++;
          inc = true;
          ans += 1;
    //      printf("C1 on %d\n", i);
          break;
        }
      }
      
      if(!inc) break;
      
      loop = false;
      for(int i=0; i<N; i++){
        if(!lv[i].stat2){
          loop = true;
          break;
        }
      }
      
      if(!loop) break;
    }
    
    if(inc) printf("Case #%d: %d\n", icase+1, ans);
    else printf("Case #%d: Too Bad\n", icase+1);
  }
}
  
