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

double rate[100010];
double sum_rate[100010];
int main(){
  int T;
  cin>>T;
  for(int t = 1 ; t <=T ; t++){
    int a,b;
    cin>>a>>b;
    sum_rate[0] = 1.0;
    rep(i,a){
      cin>>rate[i];
      sum_rate[i+1] = rate[i] * sum_rate[i];
      //cout<<sum_rate[i]<<endl;
    }
    double res = 1000000000;
    for(int i = 0 ; i <= a ; i++){
      double r = sum_rate[a-i];
      double rr = 1.0 - r;
      int type = b - a + i + i + 1;
      int type2 = type;
      if(i !=a){
        type2 = type + b + 1;
      }
      double tmp = type * r + type2 * rr;
      res = min(res, tmp);
    }
    double type = 1 + b + 1;
    res = min(res , type);
    printf("Case #%d: %.6f\n",t,res);
  } 
}
