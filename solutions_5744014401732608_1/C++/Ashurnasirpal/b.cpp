#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(int cnum){
  int res[60][60] = {};
  int b;
  ll m;
  printf("Case #%d: ",cnum);
  cin >> b >> m;
  for(int i = 1;i < b;++i){
    for(int j = i+1;j < b;++j){
      res[i][j] = 1;
    }
  }
  ll lim = (ll)pow(2,b-2);
  if(m > lim){
    puts("IMPOSSIBLE");
    return;
  }else if(lim == m){
    res[0][b-1] = 1;
    --m;
  }
  puts("POSSIBLE");
  int dist = b-2;
  while(m != 0){
    if(m % 2 == 1)res[0][dist] = 1;
    m /= 2;--dist;
  }
  for(int i = 0;i < b;++i){
    for(int j = 0;j < b;++j){
      cout << res[i][j];
    }
    cout << endl;
  }
}

int main(void){
  int t;
  cin >>t;
  for(int i = 0;i < t;++i)solve(i+1);
  return 0;
}
