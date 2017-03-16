//mishraiiit
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
typedef pair <ll, ll> pll;

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

int brute[11];
char keyboard[101];
char tomake[101];
ll k, l, s;
char best[101];

ll counterr = 0;
ll total = 0;
ll maxi = 0;

ll power(ll a, ll b) {
  if(b == 0) return 1;
  ll root = power(a, b / 2);
  if(b % 2 == 0) {
    return root * root;
  }
  return root * root * a;
}

void solve(int where) {
  if(where == s) {
    total++;
    return;
  } else {
    for(int i = 0; keyboard[i]; i++) {
      brute[where] = i;
      if(where >= l - 1) {
        for(int j = 0; j < l; j++) {
          if(keyboard[brute[where - j]] != tomake[l - 1 - j]) break;
          if(j == l - 1) {
            counterr = counterr + (ll) power(k, (s - where - 1));
          }
        }
      }
      solve(where + 1);
    }
  }
}

int main() {

    fastScan;
    int id = 0;
    int t;
    cin >> t;
    while(t--) {
      set <char> onkeyboard;
      maxi = 0;
      id++;
      cin >> k >> l >> s;
      for(int i = 0; i < 101; i++)
        keyboard[i] = 0;
      cin >> keyboard >> tomake;

      for(int i = 0; keyboard[i]; i++)
        onkeyboard.insert(keyboard[i]);

      bool sarihai = true;

      for(int j = 0; j < tomake[j]; j++) {
        sarihai = sarihai && (onkeyboard.find(tomake[j]) != onkeyboard.end());
      }

      if(!sarihai) {
        goto down;
      }

      for(int i = 0; i < 101; i++) best[i] = 0;
      for(int i = 0; i < s; i++) {
        if(best[i]) {
          bool cool = true;
          for(int j = i; j < min(s, i + l); j++) {
            if(best[i]) {
              cool = cool && (best[i] == tomake[j - i]);
            } else {
              break;
            }
          }
          if(cool) {
            for(int j = i; j < min(s, i + l); j++) {
              if(j == i + l - 1) maxi++;
              best[j] = tomake[j - i];
            }
          }
        } else {
          for(int j = i; j < min(s, i + l); j++) {
            if(j == i + l - 1) maxi++;
            best[j] = tomake[j - i];
          }
        }
      }


      counterr = 0;
      total = 0;
      solve(0);
      printf("Case #%d: %.12f\n", id, ((double) maxi) - ((double) ((double) counterr / (double) total)));
      continue;
down: ;
      printf("Case #%d: %.12f\n", id, 0.0);

    }
  
    return 0;
}
