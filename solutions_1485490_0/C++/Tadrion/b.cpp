//Tadrion
#include <cstdio>
#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define CLEAR(x) (memset(x,0,sizeof(x)))
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define VAR(v, n) __typeof(n) v = (n)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOREACH(i, c) for(VAR(i,(c).begin()); i != (c).end(); ++i)
#define DBG(v) cout<<#v<<" = "<<v<<endl; 
#define IN(x,y) ((y).find(x)!=(y).end())
#define ST first
#define ND second
#define PB push_back
#define PF push_front
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
int T;
LL aaa[110],bbb[110];
LL A[110],B[110];
int N,M;
LL a[110],b[110];
LL toys[110];
int main() {
  scanf("%d",&T);
  FOR(tttt,1,T) {
    CLEAR(toys);
    scanf("%d %d",&N,&M);
    for(int i = 1; i <= N; i++) {
      scanf("%lld %lld",&aaa[i],&A[i]);
      if(A[i] == A[i-1]) {
      	a[i-1] += a[i];
      	i--;
      	N--;
      }
    }
    for(int i = 1; i <= M; i++) {
      scanf("%lld %lld",&bbb[i],&B[i]);
      if(B[i] == B[i-1]) {
	b[i-1] += b[i];
	i--;
	M--;
      }
    }
    // printf("%d %d\n",N,M);
    LL res = 0;
    if(N==1) {
      for(int i = 1; i <= M; i++) {
	if(A[1] == B[i] && a[1] > 0) {
	  res += MIN(a[1],bbb[i]);
	  a[1] -= bbb[i];
	}
      }
    }
    else if(N==2) {
      for(int p = 0; p <= M; p++) {
	a[1]=aaa[1]; a[2]=aaa[2];
	for(int i = 1; i <= M; i++)
	  b[i] = bbb[i];
	LL res2=0;
	for(int i = 1; i <= M; i++) {
	  if(i <= p) {
	    if(A[1] == B[i] && a[1] >= 0) {
	      res2 += MIN(a[1],b[i]);
	      a[1] -= b[i];
	    }
	  }
	  else {
	    if(A[2] == B[i] && a[2] >= 0) {
	      res2 += MIN(a[2],b[i]);
	      a[2] -= b[i];
	    }
	  }
	}
	res = MAX(res,res2);
	//printf("%lld\n",res2);
      }
      
    }
    else if(N==3) {
       for(int p = 0; p <= M; p++) {
	 for(int q = p; q <= M; q++) { 
	   a[1] = aaa[1]; a[2]=aaa[2]; a[3]=aaa[3];
	   
	   for(int i = 1; i <= M; i++)
	     b[i] = bbb[i];

	   LL res2 =0;


	   for(int i = 1; i <= M; i++) {
	     if(p < q) {
	       if(i <= p) {
		 if(A[1] == B[i] && a[1] >= 0) {
		   res2 += MIN(a[1],b[i]);
		   a[1] -= b[i];
		 }
	       }
	       else if(i > p && i <= q) {
		 if(A[2] == B[i] && a[2] >= 0) {
		   res2 += MIN(a[2],b[i]);
		   a[2] -= b[i];
		 }
	       }
	       else {
		 if(A[3] == B[i] && a[3] >= 0) {
		   res2 += MIN(a[3],b[i]);
		   a[3] -= b[i];
		 }
	       }
	     }
	     else {
	       if(i <= p) {
		 if(A[1] == B[i] && a[1] >= 0) {
		   res2 += MIN(a[1],b[i]);
		   a[1] -= MIN(a[1],b[i]);
		   b[i] -= MIN(a[1],b[i]);
		 }
	       }
	       if(i >= p) {
		 res2 += MIN(a[3],b[i]);
		 a[3] -= MIN(a[3],b[i]);
		 b[i] -= MIN(a[3],b[i]);
	       }


	     }
	   }
	   res = MAX(res2,res);
	   //printf("res2:%lld %d %d %lld %lld %lld\n",res2,p,q,a[1],a[2],a[3]);
	 }
       }
    }
   
    printf("Case #%d: %lld\n",tttt,res);
  }
  return 0;
}
