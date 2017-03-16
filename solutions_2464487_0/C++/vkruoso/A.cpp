#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 1e-8

int T,n,C=1;
long long int r,t,topaint;

int cmpf(double a, double b){
  if(fabs(a-b)<=EPS) return 0;
  return a<b ? -1:1;
}

long long int area(long long int r){
  return r*r;
}

int main(){

  scanf("%d",&T);
  while(T--){
    scanf("%lld %lld",&r,&t);
    int ans=0;
    while(t>0ll){
      topaint = area(r+1ll) - area(r);
      if(topaint <= t){
        t -= topaint;
        r = r+2ll;
        ans++;
      } else break;
    }
    printf("Case #%d: %d\n",C++,ans);
  }

  return 0;
}
