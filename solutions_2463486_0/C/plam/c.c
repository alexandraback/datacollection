#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXN (10000001)

typedef unsigned long long uint64;
char SIEVE[MAXN];
int curstack;
uint64 STACK[1000];

int is_pal(uint64 n) {
  uint64 tens=10;
  uint64 msd, lsd;
  uint64 numdig=1;
  
  while(tens-1 < n) {
    tens*=10;
    numdig++;
  }
  tens/=10;
  while(n) {
    if((numdig==1) && (n < 10)) {
      return 1;
    }
    msd = n/tens;
    lsd = n%10;
    if(msd!=lsd) {
      return 0;
    }
    n -= msd*tens;
    n /= 10;
    tens /= 100;
    numdig-=2;
  }
  return 1;
}

void calc_sieve() {
  uint64 n;
  for(n = 1; n <MAXN;n++) {
    if(is_pal(n) && is_pal(n*n)) {
      //    if(is_pal(n) ) {
      SIEVE[n] = 1;
      STACK[curstack] = n*n;
      curstack++;
    }
  }
}

uint64 calc_range(uint64 A, uint64 B) {
  int count=0,i;
  for(i=0;i<curstack;i++) {
    if((STACK[i] >= A) && (STACK[i] <=B)) {
      count++;
    }
  }
  return count;
}  

void dump_sieve() {
  uint64 n;
  for(n=1;n < MAXN;n++) {
    if(SIEVE[n]) {
      printf("%llu %llu\n",n, n*n);
    }

  }
}

void dump_stack() {
  uint64 i;
  for(i=0;i<curstack;i++) {
    printf("%llu\n",STACK[i]);
  }
}

char buf[32*1024];

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))

void main(int argc, char **argv) {
  FILE *fd = fopen(argv[1], "r");
  
  assert(fd);
  
  fgets((char*)buf, 1024, fd);
  int NUMCASE;
  sscanf(buf, "%d", &NUMCASE);
  
  int curcase;
  char *str, *saveptr, *tok;
  uint64 A, B;
  assert( is_pal(1221));
  assert( is_pal(1233333321));
  assert( is_pal(123444444321));
  assert( is_pal(88888122188888));
  assert( is_pal(1444333223334441));
  assert( is_pal(9921299921299));
  assert( is_pal(99212999921299));
  assert( is_pal(1221));
  assert( is_pal(1221));
  assert( !is_pal(1233231));

  calc_sieve();
  //  dump_sieve();
  //  dump_stack();
  //  return;
  for( curcase = 1; curcase <= NUMCASE; curcase++ ) {
    printf( "Case #%d: ", curcase );
    fgets((char*)buf, 1024, fd);
    sscanf(buf, "%llu %llu", &A, &B);

    uint64 val;
    val = calc_range(A, B);

    printf("%llu\n", val);
  }
}
