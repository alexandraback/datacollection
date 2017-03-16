#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <complex>
#define MP              make_pair
#define CMNT            1
#define INF             0x3fffffff
#define MM(s,a)         memset((s),(a),sizeof((s)))
using namespace std;

typedef unsigned           uint;
typedef long long int     llint;
typedef pair<int,int>       PII;
typedef pair<double,double> PDD;

int T;
llint a[101],b[101];
int   A[101],B[101];
int N,M;

llint match(int one, int two, int three){
  llint vol=a[0],take;
  llint sol=0,best=0;
  int at=0;
  llint a1,a2,a3;
  for (int i=0; i<one  ; ++i,++at){if(B[at]==A[0]) {take=0;if (vol>=b[at]) {take=b[at]; vol-=b[at];} else if (vol>0) {take=vol; vol=0;}  sol+=take; }} a1=vol; vol=a[1]; if (A[0]==A[1]) vol+=max(a1,(llint)0);
  for (int i=0; i<two  ; ++i,++at){if(B[at]==A[1]) {take=0;if (vol>=b[at]) {take=b[at]; vol-=b[at];} else if (vol>1) {take=vol; vol=0;}  sol+=take; }} a2=vol; vol=a[2]; if (A[1]==A[2]) vol+=max(a2,(llint)0); if (two==0) vol+=a1;
  for (int i=0; i<three; ++i,++at){if(B[at]==A[2]) {take=0;if (vol>=b[at]) {take=b[at]; vol-=b[at];} else if (vol>0) {take=vol; vol=0;}  sol+=take;}} best=max(best,sol);
  return best;
}   

int main(){
  scanf("%d",&T);
  for (int t=1; t<=T; ++t){
    printf("Case #%d: ",t);
    scanf("%d %d",&N,&M);
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    memset(A,0,sizeof A);
    memset(B,0,sizeof B);
    for (int i=0; i<N; ++i) scanf("%lld %d",&a[i],&A[i]);
    for (int i=0; i<M; ++i) scanf("%lld %d",&b[i],&B[i]);
    a[N]=0;
    b[M]=0;
    llint sol=0;
    for (int only1=0; only1<=M; ++only1){
      int to=M-only1;
      if (N==1 && only1>0) break;
      for (int only2=0; only2<=to; ++only2){
	int only3=M-only1-only2;
	if (N==1) {only1=M; only2=0; only3=0;}
	if (N==2) {only2=M-only1; only3=0;}
	//	printf("--> %d %d %d %lld\n",only1,only2,only3,match(only1,only2,only3));
	sol=max(sol,match(only1,only2,only3));
	if (N==1) break;
	if (N==2) break;
      }
    }
    //    llint a=1;
    //    for (int i=0; i<62; ++i) a*=2;
    printf("%lld\n",sol); //printf("%lld\n",a);
  }
}
