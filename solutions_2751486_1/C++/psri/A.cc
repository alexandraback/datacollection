#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <assert.h>

using std::map;
using std::pair;
using std::vector;
using std::sort;

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned long ul;


#define FOR(i, a , b) for(int i = (a); i <= (b); ++i)
#define FOREACH(it, container) for(typeof(container.begin()) it = container.begin(); it != container.end(); ++it)

const unsigned int L = 1000000 + 10;
char name[L];
ul cons[L];

bool isc(char c){
  switch (c){
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return false;
    break;
  default:
    return true;
    break;
  }
  return true;
}

ul getLen(ul pos, ul l){
  int i;
  for(i = pos; i < l; ++i){
    if(!isc(name[i]))
      break;
  }
  return (i-pos);
}

int main(){
  int N;
  scanf("%d", &N);
  for(int I = 1; I <= N; ++I){
    ul n, l;
    scanf("%s %lu", name, &n);
    l = strlen(name);
    int i;
    cons[0] = getLen(0, l);
    ul t = l - n;
    for(i = 1; i <= t; ++i){
      if(cons[i-1] == 0)
	cons[i] = getLen(i, l);
      else{
	cons[i] = cons[i-1] - 1;
      }
    }
    
    ull ans = 0;
    ull temp = 0;
    for(i = 0; i <= t; ++i){
      if(cons[i] >= n){
	ans += (temp + 1)*(l-n-i+1);
	temp = 0;
      }
      else
	temp++;
    }
    
    printf("Case #%d: %llu\n", I, ans);
    
  }
  return 0;
}

// Local Variables:
// compile-command: "g++ -O3 -o A A.cc"
// End:
