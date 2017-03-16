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
  int op2 = 1+run(pos, n-1, A);
  if(A>1){
    int i=0; while(i<n-pos and A<=v[pos]) A+=(A-1), i++;
    if(v[pos]<A)
      op1 = i+run(pos, n, A);
  }
  return min(op1,op2);
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
