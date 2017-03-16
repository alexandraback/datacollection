/*
Author : KZ
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

#define INVALID -1
#define INF  1000000000
#define INFL (long)INF*INF

#define _max(a, b)                 ((a) > (b) ? (a):(b))
#define _min(a, b)                 ((a) < (b) ? (a):(b))
#define _abs(a)                    ((a) > 0 ? (a): -(a))
#define _swap(a, b, t)             do { t=a; a=b; b=t; } while(0)
#define _isEqual(a, b)             (_abs((a) - (b)) < 1e-6)
#define _rscanf                    ret = scanf

typedef std::vector<int> IntVec;
typedef std::vector<long> LongVec;
typedef std::vector<double> DoubleVec;
typedef std::map<std::string, int> StrIntMap;

#define _stl_iter(obj, it) for(typeof(obj.begin()) it = obj.begin(); it != obj.end(); it++) 

int C, D, D1, V, N;
int isPossible[101];
int isNewPossible[101];
int denom[21], denom1[10], newdenom[110];
int mark[105], minc;

int isFound(void) {
  int i, j;

  for(i=1;i<=V;i++) {
    if(isPossible[i] || isNewPossible[i]) continue;
    for(j=1;j<i;j++) {
      if(isPossible[j] && isNewPossible[i-j])
	break;
    }
    if(j==i)
      return 0;
  }
  return 1;
}
    
void search(int id, int s) {
  if(s <= V)
    isPossible[s] = 1;

  if(id == D || s > V) return;
  search(id+1, s+denom[id]);
  search(id+1, s);
  return;
}

void searchNew(int id, int s) {
  if(s <= V)
    isNewPossible[s] = 1;

  if(id == D1 || s > V) return;
  searchNew(id+1, s+denom1[id]);
  searchNew(id+1, s);
  return;
}

void subset(int id, int c) {
  if(id == N)
    return;

  if(c < 6) {
    denom1[c] = newdenom[id];
    D1 = c+1;
    memset(isNewPossible, 0, sizeof(isNewPossible));
    searchNew(0, 0);
    //    printf("%d %d\n", D1, isNewPossible[2]);
    if(isFound()) {
      if(D1 < minc)
	minc = D1;
    }
    else
      subset(id+1, c+1);
  }
  subset(id+1, c);
  return;
}

int main(void) {
  int T, kase, ret;
  
  _rscanf("%d", &T);
  for(kase=1;kase<=T;kase++) {
    memset(isPossible, 0, sizeof(isPossible));
    memset(isNewPossible, 0, sizeof(isNewPossible));
    memset(mark, 0, sizeof(mark));
    _rscanf("%d %d %d", &C, &D, &V);
    int i, j;

    for(i=0;i<D;i++) {
      _rscanf("%d", &denom[i]);
      mark[denom[i]] = 1;
    }
    N = 0;
    for(i=1;i<=V;i++) {
      if(!mark[i])
	newdenom[N++] = i;
    }
    minc = V+1;
    search(0, 0);
    for(i=1;i<=V;i++) {
      if(isPossible[i]==0)
	break;
    }
    if(i <= V) 
      subset(0, 0);
    else
      minc = 0;
    printf("Case #%d: %d", kase, minc);
    printf("\n");
  }

  return 0;
}
