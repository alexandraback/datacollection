#include <bits/stdc++.h>

using namespace std;

#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rep(a,b) fr(a,0,b)
#define fst first
#define snd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
 
const int oo = 0x3f3f3f3f;
 
typedef long long ll;
typedef pair<int,int> pii;

int main() {
  int T;
  cin >> T;
  fr(caso,1,T+1) {
    int n;
    cin >> n;
    vector<pair<string,string>> topics(n);
    for (auto &x : topics) cin >> x.fst >> x.snd;
      
    int ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
      vector<pair<string,string>> fakes;
      vector<pair<string,string>> good;
      for (int i = 0; i < n; ++i) {
        if(mask & (1 << i)) fakes.push_back(topics[i]);
        else good.push_back(topics[i]);
      }
      
      set<string> words[2];  
      for (auto par : good) {
        words[0].insert(par.fst);
        words[1].insert(par.snd);
      }
      
      bool can = true;
      for (auto par : fakes) {
        can &= (words[0].find(par.fst) != words[0].end());
        can &= (words[1].find(par.snd) != words[1].end());
      }
      
      if (can) ans = max(ans, int(fakes.size()));
    }
    printf("Case #%d: %d\n", caso, ans);
  }
  
  return 0;
}