#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <cmath>
#include <algorithm>

#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int which(int index, vector<string>& a){
  const int n = a.size();
  int ret = 0;
  for(int i = 0; i < n; i++)
    if(i != index && a[index] == a[i])
      ret |= 1 << i;
  return ret;
}

int dp[1<<16];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  for(int o = 1; o <= T; o++){
    printf("Case #%d: ", o);
    int n;
    cin >> n;
    vector<string> first;
    vector<string> second;
    string a, b;
    for(int i = 0; i < n; i++){
      cin >> a >> b;
      //cout << "a=" << a << " b=" << b << endl;
      first.push_back(a);
      second.push_back(b);
    }
    vector< pair<int, int> > from;
    for(int i = 0; i < n; i++){
      from.push_back(make_pair(which(i, first), which(i, second)));
    }
    //for(int i = 0; i < n; i++)printf("from %d %d\n", from[i].first, from[i].second);
    //memset(dp, sizeof(dp), 0);
    const int lim = 1<<n;
    for(int m = 0; m < lim; m++)dp[m] = 0;
    int ans = 0;
    for(int m = 0; m < lim; m++){
      for(int i = 0; i < n; i++){
        if((m>>i)&1)
          continue;
        int next = m | (1<<i);
        bool sat = ((from[i].first & m) > 0) && ((from[i].second & m) > 0);
        //if(sat && o==2)printf("m=%d next=%d\n", m, next);
        dp[next] = max(dp[next], dp[m] + (sat ? 1 : 0));
      }
    }
    for(int m = 0; m < lim; m++)
      ans = max(ans, dp[m]);
    printf("%d\n", ans);
  }

  return 0;
}
