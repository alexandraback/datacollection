#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int new_ma(int a, int b, int C, int V){
  long long tmp = b;
  tmp = tmp * C + a;
  if(tmp >= V)tmp = V;
  return tmp;
}
int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  //
  int T, C, D, V, d[200];
  //
  cin>>T;
  for(int t = 1; t <= T; t++){
    //if(t == 2)break;
    cin>>C>>D>>V;
    //cout<< C <<" "<<D<<" "<<V<<endl;
    for(int i = 0; i < D; i++)scanf("%d",&d[i]);
    sort(d, d+D);
    int result = 0, ma = 0;
    for(int i = 0; i < D; i++){
      while( d[i] > ma+1 )result++, ma = new_ma(ma, ma+1, C, V);
      ma = new_ma(ma, d[i], C, V);
      if( ma >= V)break;
    }
    //cout<<ma<<" "<<result<<endl;
    while( ma < V )result++, ma = new_ma(ma, ma+1, C, V);
    //cout<<result<<endl;
    printf("Case #%d: %d\n",t, result);
  }
  return 0;
}
