#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,a,b;
int c;
int f[111111];

int solve(int i,int d){
  if(i == n) return 1;
  //cout << n << ":" << d << endl;
  if(f[d] == -1){
    f[d]+=2;
    int t1 = f[d-1];
    int t2 = f[d+1];
    f[d-1]=0;
    f[d+1]=0;
    int ret = solve(i+1,50000);
    if(d == a && f[d]-1 == b) c+=ret;
    //printf("%d != %d && %d != %d\n",d,a,f[d]-1,b);
    f[d] -= 2;
    f[d-1]=t1;
    f[d+1]=t2;
    return ret;
  }
  if(f[d] < f[d+1] && f[d] < f[d-1]){
    f[d]+=2;
    int ret = solve(i+1,50000);
    if(d == a && f[d]-1 == b) c+=ret;
    f[d] -= 2;
    return ret;
  }

  if(f[d] < f[d+1] && f[d] > f[d-1]){
    return solve(i,d-1);
  }
  if(f[d] > f[d+1] && f[d] < f[d-1]){
    return solve(i,d+1);
  }
  //printf("%d - %d - %d\n",f[d-1],f[d],f[d+1]);
  return solve(i,d-1)+solve(i,d+1);
}

int main(void){
  int T;
  scanf("%d",&T);
  for(int k = 1; k <= T; k++){
    scanf("%d %d %d",&n,&a,&b);
    a += 50000;
    c = 0;
    memset(f,-1,sizeof(f));
    int ret = solve(0,50000);
    //cout << ret << endl;
    //cout << c << endl;
    printf("Case #%d: %.15lf\n",k,((double)c)/ret);
  }
}
