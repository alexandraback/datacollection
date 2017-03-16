#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
typedef long long ll;
const int inf = (1<<28);
typedef pair<int, int> ii;

int main() {
  vector<vector<string> > dic(11);

  {
    ifstream ifs("garbled_email_dictionary.txt");
    string word;
    while(ifs >> word) dic[word.size()].push_back(word);
  }

  vector<vector<vector<int> > > trie(11, vector<vector<int> >(1, vector<int>(26, -1)));

  {
    rep(kk, 11) {
      rep(k, dic[kk].size()) {
        string &word = dic[kk][k];
        int cur = 0;
        rep(i, word.size()) {
          if(trie[kk][cur][word[i]-'a'] == -1) {
            trie[kk].push_back(vector<int>(26, -1));
            trie[kk][cur][word[i]-'a'] = trie[kk].size() - 1;
          }
          cur = trie[kk][cur][word[i]-'a'];
        }
      }
    }

    // rep(i, 11) cout << i << ": " << trie[i].size() << endl;
  }

  int T; cin >> T;
  for(int t=1; t<=T; t++) {
    string text; cin >> text;
    vector<int> dp(text.size()+1, inf);
    dp[0] = 0;
    
    rep(i, text.size()) {
      
      for(int j=1; j<11; j++) {
        
        string word = text.substr(i, j);
        vector<ii> opt(1, ii(0, 0));
        rep(k, word.size()) {
          vector<ii> temp;
          rep(kk, opt.size()) {
            for(int xx = word[k]-'a'-4; xx<=word[k]-'a'+4; xx++) {
              int x = (xx + 26) % 26;
              if(trie[j][opt[kk].first][x] != -1) {
                temp.push_back(ii(trie[j][opt[kk].first][x], opt[kk].second+(xx!=word[k]-'a')));
              }
            }
          }
          opt = temp;
        }

        if(!opt.empty()) {
          int mini = inf;
          rep(iii, opt.size()) mini = min(mini, opt[iii].second);
          if(i+j<=text.size()) dp[i+j] = min(dp[i+j], dp[i]+mini);
        }
        
      }
      
    }
    
    cout << "Case #" << t << ": " << dp[text.size()] << endl;
  }
}
