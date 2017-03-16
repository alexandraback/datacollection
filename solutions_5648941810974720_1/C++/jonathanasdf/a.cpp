#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int T; cin >> T;
  for (int zz=1; zz <= T; zz++) {
    cout << "Case #" << zz << ": ";
    string s; cin >> s;
    int c[26]; memset(c, 0, sizeof c);
    for (int i=0; i < s.size(); i++) c[s[i]-'A']++;

    int count[10]; memset(count, 0, sizeof count);
    count[0] = c['Z'-'A'];
    count[2] = c['W'-'A'];
    count[4] = c['U'-'A'];
    count[6] = c['X'-'A'];
    count[8] = c['G'-'A'];
    c['Z'-'A']-=count[0];
    c['E'-'A']-=count[0];
    c['R'-'A']-=count[0];
    c['O'-'A']-=count[0];
    c['T'-'A']-=count[2];
    c['W'-'A']-=count[2];
    c['O'-'A']-=count[2];
    c['F'-'A']-=count[4];
    c['O'-'A']-=count[4];
    c['U'-'A']-=count[4];
    c['R'-'A']-=count[4];
    c['S'-'A']-=count[6];
    c['I'-'A']-=count[6];
    c['X'-'A']-=count[6];
    c['E'-'A']-=count[8];
    c['I'-'A']-=count[8];
    c['G'-'A']-=count[8];
    c['H'-'A']-=count[8];
    c['T'-'A']-=count[8];
    count[1] = c['O'-'A'];
    count[3] = c['R'-'A'];
    count[5] = c['F'-'A'];
    count[7] = c['S'-'A'];
    c['O'-'A']-=count[1];
    c['N'-'A']-=count[1];
    c['E'-'A']-=count[1];
    c['T'-'A']-=count[3];
    c['H'-'A']-=count[3];
    c['R'-'A']-=count[3];
    c['E'-'A']-=count[3];
    c['E'-'A']-=count[3];
    c['F'-'A']-=count[5];
    c['I'-'A']-=count[5];
    c['V'-'A']-=count[5];
    c['E'-'A']-=count[5];
    c['S'-'A']-=count[7];
    c['E'-'A']-=count[7];
    c['V'-'A']-=count[7];
    c['E'-'A']-=count[7];
    c['N'-'A']-=count[7];
    count[9] = c['I'-'A'];
    for (int i=0; i < 10; i++) {
      for (int j=0; j < count[i]; j++) cout << i;
    }
    cout << endl;
  }
  return 0;
}
