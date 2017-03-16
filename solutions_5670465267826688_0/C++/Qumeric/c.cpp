#include <bits/stdc++.h>
#define I 3
#define J 4
#define K 5

using namespace std;

typedef long long ll;

int ans;
int  r[256][256];
int c[11111][11111];

bool evalute(vector<int> &v, int a, int b) {
  cerr << "EVALUTE: " << a << " " << b << endl;
}


int main() {
  r[1][1] = 1;
  r[1][I] = I;
  r[1][J] = J;
  r[1][K] = K;
  r[I][1] = I;
  r[I][I] = -1;
  r[I][J] = K;
  r[I][K] = -J;
  r[J][1] = J;
  r[J][I] = -K;
  r[J][J] = -1;
  r[J][K] = I;
  r[K][1] = K;
  r[K][I] = J;
  r[K][J] = -I;
  r[K][K] = -1;


  freopen("c1.in", "r", stdin);
  freopen("c1.out", "w", stdout);
  int n; cin >> n;
  for (int t = 1; t <= n; t++) {
    int l, x; cin >> l >> x;
    string s;
    string tmp; cin >> tmp;
    for(int i = 0; i < x; i++) {
      s += tmp;
    }
    vector<int> v(s.size());
    for (int i = 0; i < s.size(); i++) {
      v[i] = s[i]-'i'+3;
    }

    for(int i = 0; i < v.size(); i++) {
      c[i][i] = v[i];
      for (int j = i+1; j < v.size(); j++) {
      if (c[i][j-1] < 0)
        c[i][j] = -r[-c[i][j-1]][v[j]];
      else 
        c[i][j] = r[c[i][j-1]][v[j]];
      }
    }

    bool good = false;
    if (s.size() >= 3) {
      for (int i = 0; i < s.size()-1; i++)
        for (int j = i+1; j < s.size()-1; j++) {
          int x = c[0][i];
          int y = c[i+1][j];
          int z = c[j+1][s.size()-1];
          //cerr << x << ' ' << y << ' ' << z << endl;
          if (x==3 && y==4 && z==5) {
            good = true;
            goto NXT;
          }
        }
    }
NXT:
    cerr << t << endl;
    cout << "Case #" << t << ": " << (good ? "YES" : "NO") << endl;
  }
}
