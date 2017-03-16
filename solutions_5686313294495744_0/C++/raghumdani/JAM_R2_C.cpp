#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
string s1[N], s2[N];

bool isGood(int mask, int n) {
  int k = 1;
  
  map <string, map <string, int> > mp;
  for(int i = 0; i < n; ++i) {
    if((1 << i) & mask) {
      mp[s1[i]][s2[i]] = 1;
    }
  }
  for(int i = 0; i < n; ++i) {
    if((1 << i) & mask) {
      for(int j = 0; j < n; ++j) {
        if(j == i) continue;
        if((1 << j) & mask) {
          if(mp[s1[i]][s2[i]] && mp[s1[i]][s2[j]] && mp[s1[j]][s2[j]]) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

int main()
{
  freopen("IN.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  int t;
  cin >> t;
  
  for(int tt = 1; tt <= t; ++tt) {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
      cin >> s1[i] >> s2[i];
    }
    int tot = (1 << n);
    bool done = false;
    for(int i = n; i >= 0; --i) {
      vector <int> val;
      for(int j = 0; j < n - i; ++j) val.push_back(0);
      for(int j = 0; j < i; ++j) val.push_back(1);
      do {
        int mask = 0;
        for(int j = 0; j < n; ++j) {
          if(val[j])
          mask |= (1 << j);
        }
        if(isGood(mask, n)) {
          printf("Case #%d: %d\n", tt, n - i);
          done = true;
          break;
        }
      } while(next_permutation(val.begin(), val.end()));
      if(done) break;
    }
    
  }
  return (0);
}
