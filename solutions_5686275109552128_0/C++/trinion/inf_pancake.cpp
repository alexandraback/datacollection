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

#define MAX 1005

int d, p[MAX], maxValue[MAX][MAX];

inline int getMaxPart(int n, int k) {
  if(k==0) return n;
  if(n%(k+1)==0) return n/(k+1);
  return 1 + n/(k+1);
}

int main(void) {
  int T, kase, ret;
  int i, j, k, mx;
  
  ret = scanf("%d", &T);
  for(kase=1;kase<=T;kase++) {
    ret = scanf("%d", &d);
    mx = 0;
    for(i=0;i<d;i++) {
      ret = scanf("%d", &p[i]);
      mx = _max(mx, p[i]);
    }
    
    for(j=0;j<mx;j++)
      maxValue[0][j] = getMaxPart(p[0], j);
    
    for(i=1;i<d;i++) {
      for(j=0;j<mx;j++) {
	maxValue[i][j] = MAX;
	for(k=0;k<=j;k++) {
	  int t = _max(maxValue[i-1][j-k], getMaxPart(p[i], k));
	  if(t < maxValue[i][j])
	    maxValue[i][j] = t;
	  else
	    break;
	}
      }
    }
    int mn = MAX;
    for(j=0;j<mx;j++) {
      mn = _min(mn, (j+maxValue[d-1][j]));
    }
    printf("Case #%d: ", kase);
    printf("%d\n", mn);
  }

  return 0;
}

