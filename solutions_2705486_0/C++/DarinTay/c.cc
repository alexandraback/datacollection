#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> W;
set<string> Ws;
set<int> Wc[11][26];
set<int> Wcf[11][26][26];
set<int> Wl[11];
string S;
int mem[4001][5];

#define INF 10000

void self_intersect(set<int>& a, set<int>& b) {
  set<int>::iterator i1 = a.begin();
  set<int>::iterator i2 = b.begin();
  while (i1 != a.end() && i2 != b.end()) {
    if (*i1 < *i2) {
      a.erase(i1++);
    } else if (*i2 < *i1) {
      i2++;
    } else {
      i1++;
      i2++;
    }
  }
  a.erase(i1, a.end());
}

int solve(int p, int b) {
  if (p == S.size()) return 0;
  int &ans = mem[p][b];
  if (ans != -1) return ans;
  ans = INF;

#if 0
  // L == 1
  if (S[p] == 'a' || S[p] == 'i') {
    ans = min(ans, solve(p+1, b == 0 ? b : b-1));
  } else if (b == 0) {
    ans = min(ans, solve(p+1, 4) + 1);
  }

  // L == 2
  if (p+2 <= S.size()) {
    string t = S.substr(p, 2);
    if (Wcf[2][t[0]-'a'][t[1]-'a'].size() > 0) {
      ans = min(ans, solve(p+2, b < 1 ? 0 : b-2));
    } else if (b <= 1) {
      if (Wc[2][t[0]-'a'].size()>0) {
        ans = min(ans, solve(p+2, 4) + 1);
      }
      
      if (b==0 && Wc[2][t[1]-'a'].size()>0) {
        ans = min(ans, solve(p+2, 3) + 1);
      }
    }
  }
  #endif
  
  for (int L=1;L<=10;++L) {
    if (p+L > S.size()) break;
    string t = S.substr(p, L); 
    set<int> op;
    if (b == 0) op = Wl[L];
    else if (b == 1) op = Wc[L][t[0]-'a'];
    else {
      op = Wcf[L][t[0]-'a'][t[1]-'a'];
      for (int i = 2; i<b && i <t.size(); ++i) {
        self_intersect(op, Wcf[L][t[i-1]-'a'][t[i]-'a']);
      }
    }

    for (set<int>::iterator it=op.begin(); it != op.end(); ++it) {
      string w = W[*it];
      int mb = b;
      int mc = 0;
      for (int i = 0; i < w.size(); ++i) {
        if (w[i] ==  t[i]) {
          mb = max(0, mb-1);
        } else {
          if (mb == 0) {
            mb = 4;
            ++mc;
          } else {
            mb = -1;
            break;
          }
        }
      }

      if (mb != -1) {
        ans = min(ans, solve(p+L, mb) + mc);
      }
    }
  }
  //cout << p << ' ' << b << ": " << ans << endl;

  return ans;
}

int main() {
  ifstream in("garbled_email_dictionary.txt");
  string s;
  int max_len = 0;
  int max_b1 = 0;
  int max_b2 = 0;
  while (in >> s) {
    int idx = W.size();
    W.push_back(s);
    Ws.insert(s);
    int len = s.size();
    Wl[len].insert(idx);
    for (int i=0;i<s.size();++i) {
      Wc[len][s[i] - 'a'].insert(idx);
      max_b1 = max(max_b1, (int)Wc[len][s[i] - 'a'].size());
      if (i != 0) {
        Wcf[len][s[i-1] - 'a'][s[i] - 'a'].insert(idx);
        max_b2 = max(max_b2, (int)Wcf[len][s[i-1]-'a'][s[i] - 'a'].size());
      }
    }
    max_len = max(max_len, (int)s.size());
  }
  /*
  cout << "Max size: " << max_len << endl;
  cout << max_b1 << ' ' << max_b2 << endl;
  for (int i=0;i<11;++i)
    cout << "# len: " << i << ": " << Wl[i].size() << endl;
  */

  int T;
  cin>>T;
  for (int t=1;t<=T;++t) {
    cin>>S;
    memset(mem,-1,sizeof(mem));

    cout << "Case #" << t << ": " << solve(0, 0) << endl;
  }
}
