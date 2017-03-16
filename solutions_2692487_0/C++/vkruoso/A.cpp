#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int T,n,C=1,res;
int v[1000010];
long long int a;

int run(int pos, int n, long long int A){
  if(pos==n) return 0;
  if(v[pos]<A)
    return run(pos+1, n, A+v[pos]);
  int op1=9999999;
  if(A>1) op1 = run(pos, n, A+A-1);
  int op2 = run(pos, n-1, A);
  return 1+min(op1,op2);
}


int main(){

  scanf("%d",&T);
  while(T--){
    scanf("%lld",&a);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",v+i);
    sort(v,v+n);

/*
    res=0;
    for(int i=0;i<n;i++){
      if(v[i]<a){ // posso comer
        a+=v[i];
        continue;
      }
      res++;
      if(a-1==0){ // remover atual
        continue;
      }
      a+=a-1;
      i--;
    }
*/
    printf("Case #%d: %d\n",C++,run(0,n,a));
  }

  return 0;
}
