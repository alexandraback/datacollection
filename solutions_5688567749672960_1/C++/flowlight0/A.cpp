#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(auto i = (c).begin(); i != (c).end(); ++i)
#define BIT(n, m) (((n) >> (m)) & 1)

typedef long long ll;

const ll inf = 1e15;
const ll mod = 1000 * 1000 * 1000 + 7;
const double eps = 1e-9;

int dist[1000001];


void solve(){
  ll n;
  cin >> n;
  // int true_ans = dist[n];
  string str  = "1";
  string goal = "";
  while (n > 0){
    goal += ('0' + (n % 10));
    n /= 10;
  }
  reverse(ALL(goal));
  // cout << goal << endl;
  // cout << goal.size() << endl;
  
  ll sum = 1;
  while (goal.size() > str.size()){
    int cost[] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999};
    if (str == "1"){
      str = "10";
      sum += 9;
    } else {
      sum += 1 + cost[str.size() / 2] + cost[(str.size() + 1) / 2];
      str = str + '0';
    }
  }
  // cout << sum << endl;

  ll ans1 = sum + atoll(goal.c_str()) - atoll(str.c_str());
  ll ans2 = 1LL << 60;

  // pattern 2
  string suffix = goal.substr((goal.size() + 1) / 2);
  
  if (goal != str){
    if (atoll(suffix.c_str()) == 0 && goal[goal.size() / 2] == '0'){
      string prefix = string(goal.begin(), goal.begin() + goal.size() / 2);
      prefix = to_string(atoll(prefix.c_str()) - 1);
      reverse(ALL(prefix));
      str = string(str.begin(), str.begin() + (str.size() + 1) / 2) + prefix;
      reverse(ALL(str));
      assert(atoll(goal.c_str()) >= atoll(str.c_str()));
      ans2 = sum + atoll(prefix.c_str()) + 1 + atoll(goal.c_str()) - atoll(str.c_str());
    } else {
      string prefix = string(goal.begin(), goal.begin() + goal.size() / 2);
      reverse(ALL(prefix));
      str = string(str.begin(), str.begin() + (str.size() + 1) / 2) + prefix;
      reverse(ALL(str));
      assert(atoll(goal.c_str()) >= atoll(str.c_str()));
      ans2 = sum + atoll(prefix.c_str()) + 1 + atoll(goal.c_str()) - atoll(str.c_str());
    }
  }
  // assert(min(ans1, ans2) == true_ans);
  cout << min(ans1, ans2) << endl;
}
 
int main(){
  int T;
  cin >> T;

  // memset(dist, -1, sizeof(dist));
  // dist[1] = 1;
  // queue<int> que;
  // que.push(1);
  // while (!que.empty()){
  //   int v = que.front(); que.pop();
  //   string str = to_string(v);
  //   reverse(ALL(str));

  //   vector<int> next_values;
  //   next_values.push_back(v + 1);
  //   next_values.push_back(atoll(str.c_str()));

  //   for (int w : next_values){
  //     if (w <= 1000 * 1000 && dist[w] == -1){
  //       dist[w] = dist[v] + 1;
  //       que.push(w);
  //     }
  //   }
  // }
  
  REP(t, T){
    printf("Case #%d: ", t + 1);
    solve();
  }
  return 0;
}
