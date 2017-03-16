#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <queue>

using namespace std;

vector<int> p;
int dp[1003][1003];

void init(){
  for(int i = 1; i <= 1000; i++){
    for(int j = 1; j <= i; j++){
      dp[i][j] = i / j - 1;
      if(i % j != 0)
        dp[i][j]++;
    }
  }
}

bool f(int v){
  for(int k = 1; k <= v; k++){
    bool ok = 1;
    int cut = v - k;
    for(int i = 0; i < p.size(); i++){
      if(p[i] <= k)
        continue;
      cut -= dp[ p[i] ][k];
      if(cut < 0){
        ok = 0;
        break;
      }
    }
    if(ok)
      return true;
  }
  return false;
}

int main(){
  /* freopen("B-large.in", "r", stdin); */
  /* freopen("B-large.ans", "w", stdout); */
  int T;
  cin >> T;

  init();
  for(int x = 1; x <= T; x++){
    int d;
    cin >> d;
    p.resize(d);

    int r = 0;
    for(int i = 0; i < d; i++){
      cin >> p[i];
      r = max(r, p[i]);
    }

    sort(p.begin(), p.end(), std::greater<int>());
    int l = 0;
    while(l < r - 1){
      int mid = (l + r) / 2;
      if(f(mid))
        r = mid;
      else
        l = mid;
    }

    int ans = r;
    cout << "Case #" << x << ": " << ans << endl;
  }
}

