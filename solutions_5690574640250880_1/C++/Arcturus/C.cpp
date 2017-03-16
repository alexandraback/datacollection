#include <stdio.h>

bool isFlip;
bool isValid;
int W, H, N;
char arr[61][61];

void Swap(int &a, int &b){
  int c = a;
  a = b;
  b = c;
}

void Work1(){
  isValid = true;
  
  arr[0][0] = 'c';
  for(int i=1; i<N; i++) arr[0][i] = '.';
  for(int i=N; i<W; i++) arr[0][i] = '*';
}
void Work2(){
  if(N%2 == 0) isValid = true;
  else isValid = false;
  if(N == 1) isValid = true;
  else if(N == 2) isValid = false;
  if(!isValid) return;
  
  int th = N/2;
  for(int i=0; i<th; i++){
    arr[0][i] = '.';
    arr[1][i] = '.';
  }
  for(int i=th; i<W; i++){
    arr[0][i] = '*';
    arr[1][i] = '*';
  }
  arr[0][0] = 'c';
}
void WorkN(){
  isValid = false;
  if(N == 2) return;
  if(N == 3) return;
  if(N == 5) return;
  if(N == 7) return;
  
  isValid = true;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      arr[i][j] = '*';
    }
  }
  arr[0][0] = 'c';
  if(N == 1) return;
  
  arr[0][1] = arr[1][0] = arr[1][1] = '.';
  if(N == 4) return;
  
  arr[0][2] = arr[1][2] = '.';
  if(N == 6) return;
  
  arr[2][0] = arr[2][1] = '.';
  if(N == 8) return;
  
  int ctN = 8;
  int ctW = 3;
  while((ctN+2 <= N)&&(ctW<W)){
    arr[0][ctW] = arr[1][ctW] = '.';
    ctW++;
    ctN+=2;
  }
  if(ctN+1 == N){
    arr[2][2] = '.';
    ctN++;
  }
  if(ctN == N) return;
  
  int ctH = 3;
  while((ctN+2 <= N)&&(ctH<H)){
    arr[ctH][0] = arr[ctH][1] = '.';
    ctH++;
    ctN+=2;
  }
  if(ctN+1 == N){
    arr[2][2] = '.';
    ctN++;
  }
  if(ctN == N) return;
  
  ctW = ctH = 2;
  while(ctN < N){
    arr[ctH][ctW] = '.';
    ctW++;
    if(ctW == W){
      ctW = 2;
      ctH++;
    }
    ctN++;
  }
}

int main(){
  int jcase;
  
  freopen("C-large.in", "r", stdin);
  freopen("C-large.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase<jcase; icase++){
    scanf("%d %d %d", &H, &W, &N);
    N = W*H - N;
    if(H > W){ 
      isFlip = true;
      Swap(W, H);
    }
    else isFlip = false;
    
    printf("Case #%d:\n", icase+1);
    if(H == 1) Work1();
    else if(H == 2) Work2();
    else WorkN();
    
    if(isFlip) Swap(W, H);
    if(isValid){
      for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
          if(!isFlip) printf("%c", arr[i][j]);
          else printf("%c", arr[j][i]);
        }
        printf("\n");
      }
    }
    else printf("Impossible\n");
  }
  
  return 0;
}
