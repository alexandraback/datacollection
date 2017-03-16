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

int kount[26];
int keys[26], K, N, L, S;
double pr[26];
char target[21];
double bc;
int mx;

int getBanana(char *s) {
  int i, j, k = 0;
  for(i=0;i+L<=S;i++) {
    for(j=0;j<L;j++) {
      if(s[i+j] != target[j]) 
	break;
    }
    if(j==L)
      k++;
  }
  mx = _max(mx, k);
  return k;
}

void populate(char *s, int pos, double p) {
  int i;

  if(pos == S) {
    //    printf("%lf\n", p);
    bc += getBanana(s) * p;
    return;
  }
  for(i=0;i<N;i++) {
    s[pos] = keys[i];
    populate(s, pos+1, p*pr[i]);
  }
  return;
}
    
int main(void) {
  int T, kase, ret;
  
  _rscanf("%d", &T);
  for(kase=1;kase<=T;kase++) {
    memset(kount, 0, sizeof(kount));
    char s[100];
    _rscanf("%d %d %d\n", &K, &L, &S);
    _rscanf("%s", s);
    int i;

    for(i=0;i<K;i++)
      kount[s[i]-'A']++;
    
    N = 0;
    for(i=0;i<26;i++) {
      if(kount[i]) {
	keys[N] = i+'A';
	pr[N] = (double)kount[i]/K;
	N++;
      }
    }
    mx = 0;
    bc = 0;
    _rscanf("%s", target);
    populate(s, 0, 1.0);
    
    printf("Case #%d: %.7lf", kase, mx-bc);
    printf("\n");
  }

  return 0;
}
