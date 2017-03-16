#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<complex>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define REP(i,a,n) for(int i = a ; i < n ; i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main(){
  int T;
  cin>>T;
  for(int t = 1 ; t <= T ; t++){
    int n;
    cin>>n;
    int v[200];
    int sum = 0;
    rep(i,n){
      cin>>v[i];
      sum += v[i];
    }
    int sum2 = sum * 2;
    double av = (double)sum2 / n;
    double res[200];
    double rr = 0;
    rep(i,n){
      double diff = av - v[i];
      double tmp = diff / sum * 100;
      res[i] = max(tmp , 0.0);
      rr += res[i];
    }
    rep(i,n){
      res[i] = res[i] / rr * 100;
    }
    printf("Case #%d:",t);
    rep(i,n){
      printf(" %.6f",res[i]);
    }
    printf("\n");
  }
}
