#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <algorithm>

using std::upper_bound;
using std::lower_bound;


#define FOR(i, a , b) for(int i = (a); i <= (b); ++i)

unsigned long long fsq[10002];
int count = 0;
const unsigned long long LIMIT = 10000000;
unsigned long long str[60];


bool isPalin(unsigned long long a){
  int l = 0;
  while(a){
    str[l++] = a%10;
    a /= 10;
  }
  int i = 0, j = l-1;
  while(i < j){
    if(str[i] != str[j])
      return false;
    i++; 
    j--;
  }
  return true;
}

int main(){
  for(unsigned long long i = 1; i <= LIMIT; ++i){
    if(isPalin(i)){
      unsigned long long j = i*i;
      if(isPalin(j))
	fsq[count++] = j;
    }
  }
  int N;
  unsigned long long a, b;
  scanf("%d", &N);
  FOR(I, 1, N){
    scanf("%llu %llu", &a, &b);
    unsigned long long* l = lower_bound(fsq, fsq + count, a);
    unsigned long long* u = upper_bound(fsq, fsq + count, b);
    printf("Case #%d: %d\n", I, u-l);
  }
  return 0;
}



// Local Variables:
// compile-command: "g++ -O3 -o C1 C-1.cc"
// End:
