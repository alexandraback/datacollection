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

#define MAX 10010

int qmap[256][256];
char L_str[MAX];
int L_val[5];
int prefixVal[MAX], suffixVal[MAX];
int L, X;

void init(void) {
  qmap[1][1] = 1;
  qmap[1]['i'] = 'i';
  qmap[1]['j'] = 'j';
  qmap[1]['k'] = 'k';
  qmap['i'][1] = 'i';
  qmap['i']['i'] = -1;
  qmap['i']['j'] = 'k';
  qmap['i']['k'] = -1*('j');
  qmap['j'][1] = 'j';
  qmap['j']['i'] = -1*('k');
  qmap['j']['j'] = -1;
  qmap['j']['k'] = 'i';
  qmap['k'][1] = 'k';
  qmap['k']['i'] = 'j';
  qmap['k']['j'] = -1*('i');
  qmap['k']['k'] = -1;
  
  return ;
}
  
int qmul(int i, int j) {
  if(i < 0 && j < 0)
    return qmap[-i][-j];
  else if(i<0)
    return -qmap[-i][j];
  else if(j<0)
    return -qmap[i][-j];
  else
    return qmap[i][j];
}

int main(void) {
  int T, kase, ret;
  
  init();
  _rscanf("%d", &T);
  for(kase=1;kase<=T;kase++) {
    _rscanf("%d %d", &L, &X);
    _rscanf("%s", L_str);

    int i, j, k, l;
    prefixVal[0] = suffixVal[L] = 1;
    i = 1, j = L-1;
    for(;i<=L; i++, j--) {
      prefixVal[i] = qmul(prefixVal[i-1], L_str[i-1]);
      suffixVal[j] = qmul(L_str[j], suffixVal[j+1]);
    }
    
    L_val[0] = 1;
    L_val[1] = suffixVal[0];
    for(i=2;i<=4;i++)
      L_val[i] = qmul(L_val[i-1], L_val[1]);
    assert(L_val[4] == 1);

    int flag = 0, p, q, r;

    for(i=0;i<4;i++) {
      if(i >= X) continue;
      for(j=0;j<=L;j++) {
	p = qmul(L_val[i], prefixVal[j]);
	if(p != 'i') continue;
	
	q = 1;
	for(k=j+1;k<=L;k++) {
	  q = qmul(q, L_str[k-1]);
	  if(q != 'j') continue;

	  int rem = X - i - 1;
	  assert(rem >= 0);
	  r = qmul(suffixVal[k], L_val[rem % 4]);
	  if(r == 'k') {
	    flag = 1;
	    //	    printf("%d %d %d\n", i, j, k);
	    goto soln;
	  }
	}
	for(l=0;l<4;l++) {
	  if(i+l+1 >= X) continue;
	  for(k=0;k<=L;k++) {
	    q = qmul(qmul(suffixVal[j], L_val[l]), prefixVal[k]);
	    if(q != 'j') continue;
	    
	    int rem = X - i - l - 2;
	    assert(rem >= 0);
	    r = qmul(suffixVal[k], L_val[rem % 4]);
	    if(r == 'k') {
	      flag = 1;
	      //	      printf("%d %d %d %d\n", i, j, l, k);
	      goto soln;
	    }
	  }
	}
      }
    }

  soln:
    if(flag)
      printf("Case #%d: YES\n", kase);
    else
      printf("Case #%d: NO\n", kase);
  }

  return 0;
}
