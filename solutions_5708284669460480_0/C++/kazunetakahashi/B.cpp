#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init() {
}

// 変数を書く

int klen, llen, s;
string K, L;
vector<string> V[10];

void input() {
  cin >> klen >> llen >> s;
  cin >> K >> L;
  for (auto i=0; i<10; i++) {
    V[i].clear();
  }
}

void output() {
  V[0].push_back("");
  for (auto i=0; i<s; i++) {
    // V[i]からV[i+1]をつくる
    for (unsigned j=0; j<V[i].size(); j++) {
      string str = V[i][j];
      for (auto k=0; k<klen; k++) {
        V[i+1].push_back(str + K[k]);
      }
    }
  }
  int maxword = 0;
  int hasword = 0;
  for (unsigned i=0; i<V[s].size(); i++) {
    // cerr << "i = " << i << ", V[s][i] = " << V[s][i] << endl;
    int cnt = 0;
    for (auto j=0; j+llen-1<s; j++) {
      for (auto k=0; k<llen; k++) {
        if (V[s][i][j+k] != L[k]) {
          // cerr << j << " " << k << endl;
          goto EXIT;
        }
      }
      cnt++;
    EXIT: continue;
    }
    hasword += cnt;
    maxword = max(cnt, maxword);
  }
  cerr << "maxword = " << maxword << ", hasword = " << hasword << endl;
  cout << fixed << setprecision(10) << maxword - ((double)hasword)/((int)V[s].size()) << endl;
}

int main() {
  init();
  int T;
  cin >> T;
  for (auto t=1; t<=T; t++) {
    cout << "Case #" << t << ": "; 
    input();
    output();
  }
}
