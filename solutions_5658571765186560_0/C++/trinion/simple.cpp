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
  int T=0, kase, ret;
  int X, R, C;
  
  _rscanf("%d", &T);
  for(kase=1;kase<=T;kase++) {
    _rscanf("%d %d %d", &X, &R, &C);
    
    printf("Case #%d: ", kase);
    if(X== 1)
      printf("GABRIEL\n");
    else if(X==2) {
      if((R*C)%2)
	printf("RICHARD\n");
      else
	printf("GABRIEL\n");
    }
    else if(X==3) {
      if(R==1 || C==1)
	printf("RICHARD\n");
      else if((R*C)%3)
	printf("RICHARD\n");
      else
	printf("GABRIEL\n");
    }
    else {
      assert(X==4);
      if(R==1 || C==1)
	printf("RICHARD\n");
      else if((R*C)%4)
	printf("RICHARD\n");
      else if(_max(R, C) < 4)
	printf("RICHARD\n");
      else if(R*C==8)
	printf("RICHARD\n");
      else
	printf("GABRIEL\n");
    }
  }

  return 0;
}
