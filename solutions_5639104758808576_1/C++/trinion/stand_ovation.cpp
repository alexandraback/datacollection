/*
Author : Md Kamruzzaman
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

#define INVALID -1

#define _max(a, b)                 ((a) > (b) ? (a):(b))
#define _min(a, b)                 ((a) < (b) ? (a):(b))
#define _abs(a)                    ((a) > 0 ? (a): -(a))
#define _swap(a, b, t)             do { t=a; a=b; b=t; } while(0)
#define _isEqual(a, b)             (_abs((a) - (b)) < 1e-6)
#define _rscanf                    ret = scanf

using namespace std;

typedef vector<int> IntVec;
typedef vector<long> LongVec;
typedef vector<double> DoubleVec;
typedef map<string, int> StrIntMap;

#define _stl_iter(obj, it) for(typeof(obj.begin()) it = obj.begin(); it != obj.end(); it++) 

int main(void) {
  int T, kase, ret;
  char s[2000];
  
  _rscanf("%d", &T);
  for(kase=1;kase<=T;kase++) {
    int maxShy, i;
    
    ret = scanf("%d %s", &maxShy, s);
    int mn = 0, count = 0;
    for(i=0;i<=maxShy;i++) {
      if(s[i] == '0') continue;
      if(i <= count) 
	count += s[i] - '0';
      else {
	mn += (i - count);
	count = i + s[i] - '0';
      }
    }
    printf("Case #%d: ", kase);
    printf("%d\n", mn);
  }
  return 0;
}
