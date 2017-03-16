#include <iostream>
#include <cstdio>
#define EPSILON 1e-12
#define MAXN 205
using namespace std;

int testcase,N,sum,S[MAXN];
double hi,lo,mid;

bool eq(double a,double b){
  return a-b < EPSILON && b-a < EPSILON;
}

bool can(double v,int x){
  double score = (double)(S[x]) + v * (double)(sum), t = 1.0 - v;
//  printf("v = %lf, score = %lf\n",v,score);
  for(int i=0;i<N;++i)
    if(i != x && (double)(S[i]) < score)
      t -= (score - (double)(S[i]))/(double)(sum);
  return (t < 0 || eq(t,0.0));
}

int main(){
  freopen("A-large.in","r",stdin);
  freopen("A.out","w",stdout);
  scanf("%d",&testcase);
  for(int TC=1;TC<=testcase;++TC){
    scanf("%d",&N);
    sum = 0;
    for(int i=0;i<N;++i){
      scanf("%d",&S[i]);
      sum += S[i];
    }
    printf("Case #%d:",TC);
    for(int i=0;i<N;++i){
     // printf("testing %d\n",i);
      lo = 0.0, hi = 1.0;
      while(!eq(hi,lo)){
        mid = (hi+lo)/2.0;
        if(can(mid,i)) hi = mid;
        else lo = mid;
      }
      printf(" %.9lf",hi*100.0);
    }
    printf("\n");
  }
}
