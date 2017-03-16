#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<set>
#include<deque>

using namespace std;

const int MAX = 41;
int number;
long long powers[MAX];

long long gcd ( long long a, long long b){
  long long c;
  while ( a != 0 ) {
    c = a; a = b%a;  b = c;
  }
  return b;
}

void init(){
  long long power = 1;
  for(int i=0; i<MAX; ++i){
    powers[i] = power;
    power = 2*power;
  }
}

bool check(long long nom, long long denom){
  bool error = (denom < nom);
  if(!error){    
    error = true;
    for(int i=0; i<MAX; ++i){
      if(denom == powers[i]){
	error = false;
	break;
      }
    }
  }
  return error;
}

void runCalc(long long nom, long long denom){
  for(int i=0; i<MAX; ++i){
    if(powers[i]*nom >= denom){
      printf("%d", i);
      break;
    }
  }
}

void calc(long long nom, long long denom){
  long long div = gcd(nom, denom);
  nom = nom/div;
  denom = denom/div;
  bool error = check(nom, denom);
  if(error){
    printf("impossible");
  }
  else{
    runCalc(nom, denom);
  }
}

void run(){
  long long first,second;
  char sign;
  scanf("%lld", &first);
  scanf("%c", &sign);
  scanf("%lld", &second);
  calc(first, second);  
}

int main(){
  init();
  scanf("%d", &number);
  for(int i=1; i<=number; ++i){
    printf("Case #%d: ", i);
    run();
    printf("\n");
  }
  return 0;
}
