#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int overlap(string& target, string& str){
  for(int i = str.size(); i > 0; --i){
    if(str.substr(1).compare(target.substr(0, i)) == 0){
      return i;
    }
  }
  return 0;
}

vector<string> enumAll(int s, string& key){
  set<string> xs {""};
  int ks = key.size();
  for(int i = 0; i < s; ++i){
    set<string> nxs {};
    for(int j = 0; j < ks; ++j){
      for(auto it = xs.begin(); it != xs.end(); ++it){
        string str = string(*it);
        nxs.insert(str.append(1, key[j]));
      }
    }
    xs = nxs;
  }
  return vector<string>(xs.begin(), xs.end());
}

double prob(vector<double>& ps, string& str){
  double p = 1;
  int ss = str.size();
  for(int i = 0; i < ss; ++i){
    p *= ps[str[i]-'A'];
  }
  return p;
}

int countStr(string& str, string& target){
  int cnt = 0;
  unsigned long idx = 0;
  while(1){
    idx = str.find(target, idx);
    if(idx != string::npos){
      ++cnt;
    } else {
      break;
    }
    ++idx;
  }
  return cnt;
}

double solve2(int k, int l, int s, string key, string target){
  auto strs = enumAll(s, key);
  //cout << strs.size() << endl;
  int maxCnt = 0;
  double expCnt = 0;
  int ss = strs.size();
  auto ps = vector<double>(26, 0);
  for(int i = 0; i < k; ++i){
    ++ps[key[i]-'A'];
  }
  for(int i = 0; i < 26; ++i){
    ps[i] /= k;
  }
  for(int i = 0; i < ss; ++i){
  //  cout << strs[i] << endl;
    int cnt = countStr(strs[i], target);
  //  cout << "cnt = " << cnt << endl;
    maxCnt = max(maxCnt, cnt);
    expCnt += cnt * prob(ps, strs[i]);
  }
  return maxCnt - expCnt;
}
/**
int solve(int k, int l, int s, string key, string target){
  auto dp = vector<vector<vector<int>>>(s+1, vector<vector<int>>(s+1, vector<int>(s+1)));
  auto ps = vector<double>(26);
  for(int i = 0; i < l; ++i){
    ++ps[key-'A'];
  }
  for(int i = 0; i < 26; ++i){
    ps[i] /= l;
  }
  dp[0][0][0] = 1.0;
  for(int i = 0; i < s; ++i){
    for(int j = 0; j < s; ++j){
      for(int k = 0; k < s; ++k){
        if(k == l-1){
          int lap = overlap(target, target.substr(1));
          dp[i+1][j+1][lap] += dp[i][j][k]*ps[target[k]-'A'];
        } else {
          dp[i+1][j][k+1] += dp[i][j][k]*ps[target[k]-'A'];
          for(int p = 0; p < 26; ++p){
            if(target[k]-'A' == p){
              continue;
            }
            lap = overlap(target, target.substr(k))
            dp[i+1][j][]
          }
        }
      }
    }
  }
}
*/
int main(){
  int t;
  cin >> t;
  int k, l, s;
  string key, target;
  for(int i = 0; i < t; ++i){
    cin >> k >> l >> s;
    cin >> key >> target;
    printf("Case #%d: %.7f\n", i+1, solve2(k, l, s, key, target));
  }
}
