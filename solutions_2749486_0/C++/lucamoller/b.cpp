#include <stdio.h>
#include <string.h>

int T, X, Y;
int mx, my;

int modu(int x){
  if(x < 0) return -x;
  return x;
}

char resp[10000000];

int main() {
  scanf(" %d", &T);
  for(int t=1; t<=T; t++) {
    scanf(" %d %d", &X, &Y);
    mx = modu(X);
    my = modu(Y);
    
    int i = 0;
    int soma = 0;
    for(i=0; i<10000000; i++) {
      soma += i;
      if(soma > mx+my) {
        i--;
        break;
      }
    }
    
    int j = i;
    for(; j>0; j--) {
      if(mx > my) {
          mx -= j;
          if(X > 0) resp[j] = 'E';
          else resp[j] = 'W';
      }
      else {
          my -= j;
          if(Y > 0) resp[j] = 'N';
          else resp[j] = 'S';
      }
    }
    while(mx > 0) {
      if(X > 0) {
        resp[i+1] = 'W';
        resp[i+2] = 'E';
      } else {
        resp[i+1] = 'E';
        resp[i+2] = 'W';
      }
      i+=2;
      mx--;
    }
    while(my > 0) {
      if(Y > 0) {
        resp[i+1] = 'S';
        resp[i+2] = 'N';
      } else {
        resp[i+1] = 'N';
        resp[i+2] = 'S';
      }
      i+=2;
      my--;
    }
    resp[i+1] = '\0';
    printf("Case #%d: %s\n",t, (resp+1));
  }
}
