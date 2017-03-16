#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_set>
using namespace std;

int dp[4001][5];

int main()
{
  ifstream fin("garbled_email_dictionary.txt");
  string s;
  unordered_set<string> dict;
  while (fin >> s) {
    dict.insert(s);
    for (int i = 0; i < s.size(); i++) {
      string t = s;
      t[i] = '?';
      dict.insert(t);
    }
    for (int i = 0; i < s.size(); i++) {
      for (int j = i+5; j < s.size(); j++) {
        string t = s;
        t[i] = t[j] = '?';
        dict.insert(t);
      }
    }
  }
  
  cerr << "Dictionary initialized." << endl;

  int T; cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cin >> s;
    memset(dp, 0x7f, sizeof dp);
    dp[0][4] = 0;
    int N = s.size();
    for (int i = 1; i <= N; i++) {
      for (int j = max(0, i-10); j < i; j++) {
        string t = s.substr(j, i-j);
        if (dict.count(t)) {
          for (int k = 0; k < 5; k++) {
            int g = min(4, k + (int)t.size());
            dp[i][g] = min(dp[i][g], dp[j][k]);
          }
        }
        for (int k = 0; k < t.size(); k++) {
          char c = t[k];
          t[k] = '?';
          if (dict.count(t)) {
            int r = max(0, 4 - k);
            int g = min(4, (int)t.size()-1-k);
            for (int l = r; l < 5; l++) {
              dp[i][g] = min(dp[i][g], dp[j][l] + 1);
            }
          }
          t[k] = c;
        }
        for (int k = 0; k < t.size(); k++) {
          for (int l = k+5; l < t.size(); l++) {
            char c = t[k], d = t[l];
            t[k] = t[l] = '?';
            if (dict.count(t)) {
              int r = max(0, 4 - k);
              int g = min(4, (int)t.size()-1-l);
              for (int l = r; l < 5; l++) {
                dp[i][g] = min(dp[i][g], dp[j][l] + 2);
              }
            }
            t[k] = c, t[l] = d;
          }
        }
      }
    }
    
    int ans = 0x7f7f7f7f;
    for (int i = 0; i < 5; i++) {
      ans = min(ans, dp[N][i]);
    }
    
    printf("Case #%d: %d\n", tt, ans);
  }
}