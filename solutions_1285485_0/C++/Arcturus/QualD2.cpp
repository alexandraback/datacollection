#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define e 0.0000001

int H, W, D;
char arr[30][31];
int posx, posy;
int dist;  
long long ctr=0;
int prime[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

void checkside(){
  int curdist;
  int tempx, tempy;
  
  curdist = 0;
  tempx = posx/2; tempy = posy/2;
  while(arr[tempy][tempx] != '#'){
    tempx++;
    curdist++;
  }
  if(curdist*2 - 1 <= dist/2) ctr++;
  
  curdist = 0;
  tempx = posx/2; tempy = posy/2;
  while(arr[tempy][tempx] != '#'){
    tempx--;
    curdist++;
  }
  if(curdist*2 - 1 <= dist/2) ctr++;
  
  curdist = 0;
  tempx = posx/2; tempy = posy/2;
  while(arr[tempy][tempx] != '#'){
    tempy++;
    curdist++;
  }
  if(curdist*2 - 1 <= dist/2) ctr++;
  
  curdist = 0;
  tempx = posx/2; tempy = posy/2;
  while(arr[tempy][tempx] != '#'){
    tempy--;
    curdist++;
  }
  if(curdist*2 - 1 <= dist/2) ctr++;
}

bool comp(double a, double b){
  if(a < b){
    if(a + e >= b) return true;
  }
  else {
    if(b + e >= a) return true;
  }
  return false;
}

void coba(int vx, int vy){
  int initx = vx, inity = vy;
  double tempdist = 0;
  double factx, facty; 
  double tempx, tempy;
  double movx, movy, movdist;
  int nextx, nexty;
  int prevx, prevy;
  
  tempx = posx; tempy = posy;
  while(tempdist + e < dist){
    if(vx > 0) factx = (ceil(tempx + e) - tempx)/vx;
    else factx = (floor(tempx - e) - tempx)/vx;
    if(vy > 0) facty = (ceil(tempy + e) - tempy)/vy;
    else facty = (floor(tempy - e) - tempy)/vy;
    
//    printf("factx = %llf, facty = %llf\n", factx, facty);
    if(factx < facty){
      if(vx > 0) movx = ceil(tempx + e) - tempx;
      else movx = floor(tempx - e) - tempx;
      movy = movx * vy / vx;
    }
    else{
      if(vy > 0) movy = ceil(tempy + e) - tempy;
      else movy = floor(tempy - e) - tempy;
      movx = movy * vx / vy;
    }
//    printf("movx = %llf, movy = %llf\n", movx, movy);
    movdist = sqrt(movx*movx + movy*movy);
    
    if(movdist + tempdist - e > dist){
      movx = movx*(dist - tempdist)/movdist;
      movy = movy*(dist - tempdist)/movdist;
      movdist = dist - tempdist + e;
    }
    tempdist += movdist;
    tempx += movx;
    tempy += movy;
//    printf("tempdist = %llf, tempx = %llf, tempy = %llf\n", tempdist, tempx, tempy);
    
    if(comp(tempx, posx) && comp (tempy, posy)){
      ctr++; 
//      printf("%d %d sukses\n", initx, inity);
      return;
    }
    
    if(vx > 0){
      nextx = ((int)ceil(tempx + e) - 1)/2;
      prevx = ((int)floor(tempx - e))/2;
    }
    else {
      nextx = ((int)floor(tempx - e))/2;
      prevx = ((int)ceil(tempx + e) - 1)/2;
    }
    if(vy > 0){
      nexty = ((int)ceil(tempy + e) - 1)/2;
      prevy = ((int)floor(tempy - e))/2;
    }
    else {
      nexty = ((int)floor(tempy - e))/2;
      prevy = ((int)ceil(tempy + e) - 1)/2;
    }
//    printf("nextx = %d nexty = %d\n", nextx, nexty);
    
    if(arr[nexty][nextx] == '#'){
      if(prevx == nextx) vy = -vy;
      else if(prevy == nexty) vx = -vx;
      else{
        if(arr[nexty][prevx] == '#' && arr[prevy][nextx] == '#'){
          vx = -vx;
          vy = -vy;
        }
        else if(arr[nexty][prevx] == '#') vy = -vy;
        else if(arr[prevy][nextx] == '#') vx = -vx;
        else return;
      }
    }
//    printf("vx = %d vy = %d\n\n", vx, vy);
  }
}

int main(){
  int jcase;
  bool skip;
  /*strcpy(arr[0], "######");
  strcpy(arr[1], "#..X.#");
  strcpy(arr[2], "#.#..#");
  strcpy(arr[3], "#...##");
  strcpy(arr[4], "######");
  
  H = 5, W = 6, D = 3;
  posx = 7, posy = 3;
  dist = 6;
  coba(-1, 1);
  printf("ctr = %lld\n", ctr);
  getch();
  */
  
  freopen("D-small-attempt0.in", "r", stdin);
  freopen("D-small-attempt0.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase < jcase; icase++){
    scanf("%d %d %d", &H, &W, &D);
    gets(arr[0]);
    for(int i=0; i<H; i++){
      gets(arr[i]);
      for(int j=0; j<W; j++){
        if(arr[i][j] == 'X') {
          posx = j*2 + 1;
          posy = i*2 + 1;
        }
      }
    }
    ctr = 0;
    dist = D*2;
    for(int i=-50; i<51; i++){
      for(int j=-50; j<51; j++){
        if(i==0 || j==0) continue;
        skip = false;
        for(int k=0; k<15; k++){
          if(i%prime[k] == 0 && j%prime[k] == 0){
            skip = true;
            break;
          }
        }
        if(!skip) coba(i, j);
      }
    }
    checkside();
    printf("Case #%d: %lld\n", icase + 1, ctr);
  }
}
