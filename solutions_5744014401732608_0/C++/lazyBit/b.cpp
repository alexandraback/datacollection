#include<stdio.h>
#include<iostream>
#include<vector>
#include<bitset>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<sstream>
#include<cstring>

#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);

using namespace std;

const int MAXN = (int) 5e5 + 10;

int n, m;
vector<int> ord;

void print(vector<vector<int> > a) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j];
      /*
      if (j + 1 < n) {
        cout << " ";
      }
      */
    }
    cout << endl;
  }
}

int good(vector<vector<int> > a) {
  vector<int> dp(n, 0);
  dp[ord[0]] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[ord[j]][ord[i]]) {
        dp[ord[i]] += dp[ord[j]];
      }
    }
  }
  //print(a);
  //cout << dp[ord[n - 1]] << endl;
  return (dp[ord[n - 1]] == m);
}

pair<int, vector<vector<int> > > rec(int idx,  vector<vector<int> > a) {
  if (idx == n - 1) {
    if (good(a)) {
      return make_pair(true, a); 
    }
  } else {
    int total = n - idx - 1;
    for (int mask = 0; mask < (1 << total); mask++) {
      vector<vector<int> > b = a;
      for (int i = 0; i < total; i++) {
        if (mask & (1 << i)) {
          int cur = idx + 1 + i; 
          b[ord[idx]][ord[cur]] = 1;
        }
      }
      auto res = rec(idx + 1, b);
      if (res.first) {
        return res;
      }
    }
  }
  return make_pair(false, vector<vector<int> > ());
}

pair<int, vector<vector<int> > > solve() {
  vector<vector<int> > a(n, vector<int>());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i].push_back(0);
    }
  }
  auto res = rec(0, a);
  return res;
}

int main() {
  #ifndef ONLINE_JUDGE
        input;
        output;
    #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T, tc = 1;;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    vector<vector<int> > a;
    int ok = false;
    for (int pos = 0; pos < n - 1; pos++) {
      ord.clear();
      for (int i = 0; i < n; i++) {
        ord.push_back(-1);
      }
      ord[pos] = 0;
      ord[n - 1] = n - 1;
      int cur = 1;
      for (int i = 0; i < n; i++) {
        if (ord[i] == -1) {
          ord[i] = cur;
          cur++;
        }
      }
      auto res = solve();
      if (res.first) {
       a = res.second;
       for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          a[i][j] = a[ord[i]][ord[j]];
        }
       }
       ok = true;
       break;
      }
    }
    /*
    vector<int> v;
    for (int i = 0; i < n - 1; i++) {
      v.push_back(i);
    } 
    vector<vector<int> > a;
    int ok = false;
    do {
      ord.clear();
      for (int x : v) {
        ord.push_back(x);
      }
      ord.push_back(n - 1);
      auto res = solve();
      if (res.first) {
       a = res.second;
       for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          a[i][j] = a[ord[i]][ord[j]];
        }
       }
       ok = true;
       break;
      }
    } while (next_permutation(v.begin(), v.end()));
    */
    if (ok) {
      cout << "Case #" << tc++ << ": " << "POSSIBLE" << endl;
      print(a);
    } else {
      cout << "Case #" << tc++ << ": " << "IMPOSSIBLE" << endl;
    }
  }
  return 0;
}	
