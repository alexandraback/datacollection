#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 200;
const int INF = 100000000;

int n, x, s[N], data[N];
double ans[N];

void solve(){
  int rem = x;
  fill(data, data+N, 0);
  while(rem>0){
    int cnt = 0;
    int valm = INF;
    for(int i=0;i<n;i++){
      if(valm > s[i] + data[i]){
        valm = s[i] + data[i];
      }else if(valm == s[i] + data[i]) cnt++;
    }
    if(cnt > rem){
      for(int i=0;i<n;i++){
        if(data[i] == 0) ans[i] = 0.0;
        else if(s[i] + data[i] == valm) ans[i] = ((double)data[i]+(double)rem/cnt) / x;
        else ans[i] = (double)data[i] / x;
      }
      return;
    }else{
      for(int i=0;i<n;i++){
        if(s[i] + data[i] == valm){
          data[i]++;
          rem--;
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    if(data[i] == 0) ans[i] = 0.0;
    else ans[i] = (double)data[i] / x;
  }
}

main(){
  int T;
  cin >> T;
  for(int t=1;t<=T;t++){
    cin >> n;
    x = 0;
    for(int i=0;i<n;i++){
      cin >> s[i];
      s[i] *= 100000;
      x += s[i];
    }
    solve();
    printf("Case #%d:", t);
    for(int i=0;i<n;i++) printf(" %.6f", ans[i]*100.0);
    printf("\n");
  }
}
