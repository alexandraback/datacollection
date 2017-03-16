#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstring>
#include <cmath>

using namespace std;

char cadena[1000005];
char cadena2[1000005];
char micad[1000005];
char *cadin;
int len;

void calcular(){
  int i;
  len = 0;
  while(1){
    if(!isdigit(cadin[len])) break;
    len++;
  }
  
  for(int i = 0; i < len; i++){
    cadena2[i] = cadin[i];
  }
  
  for(int i = 0; i < len/2; i++){
    cadin[len-i-1] = cadin[i];
  }
  
  for(int i = 0; i < len; i++){
    if(cadena2[i] > cadin[i]) break;
    if(cadena2[i] < cadin[i]) return;
  }
  
  
  i = len/2;
  while(true){
    if(cadin[i] == '\0'){
      
      
      cadin[i] = '1';
      len += 1;
      cadin[len] = '\0';
      
      
      break;
    }else if(cadin[i] < '9'){
      cadin[i] += 1;
      break;
    }
    cadin[i] = '0';
    i++;
  }
  
  for(int i = 0; i < len/2; i++){
    cadin[i] = cadin[len-i-1];
  }
  
  
}

bool ispalin(char *s){
  int n = strlen(s);
  for(int i = 0; i < n/2; i++){
    if(s[i] != s[n-i-1]) return false;
  }
  return true;
}

int T;
int main(){
  scanf("%d", &T);
  long long qa, qb, a, b, res, cuad;
  cadena[0] = '0';
  cadin = cadena+1;
  for(int t = 0; t < T; t++){
    scanf("%lld %lld", &a , &b);
    res = 0;
    qa = sqrt(a)-1;
    qb = sqrt(b);
    
    //printf("%lld %lld \n", qa, qb);
    sprintf(cadin, "%lld", qa);
    
    
    for(int i = 0; i < 200000; i++){
      
      calcular();
      sscanf(cadin, "%lld", &cuad);
      cuad = cuad * cuad;
      if(cuad < a) continue;
      if(cuad > b) break;
      
      sprintf(micad, "%lld", cuad);
      
      //printf("%lld\n", cuad);
      if(ispalin(micad)) res += 1;
      
    }
    printf("Case #%d: %lld\n", t+1, res);
  }
}


