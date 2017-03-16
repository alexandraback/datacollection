#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define MAXN 1200

int T;
int cnt[MAXN];
int smax;
string s;

int main() {
  cin >> T;
  REP(zz,T) {
    cin >> smax;
    cin >> s;
    REP(i,smax+1) cnt[i]=s[i]-'0';
    int score = 0;
    int stands = 0;
    REP(i,smax+1) {
      while (i>stands) {
        ++score; ++stands;
      }
      stands+=cnt[i];
    }
    cout << "Case #" << (zz+1) << ": " << score << endl;
  }
}
