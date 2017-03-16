#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <climits>
#include <ctime>
using namespace std;

typedef long long     ll;
typedef double        dbl;

#define X             first
#define Y             second
#define mp            make_pair
#define pb            push_back
#define sz(x)         static_cast<int>((x).size())
#define all(x)        x.begin(),x.end()

#ifdef ROMCHELA
#    define D(x)          cout<<#x<<" = "<<(x)<<endl
#    define Ds()          cout<<"------------"<<endl
#    define eprintf(...)  printf(__VA_ARGS__);
#else
#    define D(c)             static_cast<void>(0)
#    define Ds(x)            static_cast<void>(0)
#    define eprintf(...)     static_cast<void>(0)
#endif

const int maxn = 1e6 + 10;

ll strtoint(string s) {
  ll res = 0;
  for (int i = 0; i < sz(s); i++) {
    res = res * 10LL + (s[i] - '0');
  }
  return res;
}

pair<string, string> stupid(string a, string b) {
  string ans_a, ans_b;
  int ans_diff = INT_MAX, ans_nn, ans_mm;
  for (int i1 = '0'; i1 <= '9'; i1++) {
    for (int i2 = '0'; i2 <= '9'; i2++) {
      for (int i3 = '0'; i3 <= '9'; i3++) {
        if (a[0] != '?' && i1 != a[0]) continue;
        if (a[1] != '?' && i2 != a[1]) continue;
        if (a[2] != '?' && i3 != a[2]) continue;
        for (int j1 = '0'; j1 <= '9'; j1++) {
          for (int j2 = '0'; j2 <= '9'; j2++) {
            for (int j3 = '0'; j3 <= '9'; j3++) {
              if (b[0] != '?' && j1 != b[0]) continue;
              if (b[1] != '?' && j2 != b[1]) continue;
              if (b[2] != '?' && j3 != b[2]) continue;
              
              string n1 = "";
              n1 += i1;
              n1 += i2;
              n1 += i3;
              int nn = strtoint(n1);
              string n2 = "";
              n2 += j1;
              n2 += j2;
              n2 += j3;
            
              int mm = strtoint(n2);

              if (abs(nn - mm) < ans_diff || (abs(nn - mm) == ans_diff && nn < ans_nn) || 
                  (abs(nn - mm) == ans_diff && nn == ans_nn && mm < ans_mm)) {
                ans_diff = abs(nn - mm);
                ans_nn = nn;
                ans_mm = mm;
                ans_a = n1;
                ans_b = n2;
              }
            }
          }
        }
      }
    }
  }

  return mp(ans_a, ans_b);
}

pair<string, string> sol(string a, string b) {
  for (int i = 0; i < sz(a); i++) {
    if (a[i] != '?' && b[i] != '?') {
      if (a[i] > b[i]) {
        // min a max b
        for (int j = i + 1; j < sz(a); j++) {
          if (a[j] == '?')
            a[j] = '0';
          if (b[j] == '?')
            b[j] = '9';
        }
        break;
      } else if (a[i] < b[i]) {
        // min b max a
        for (int j = i + 1; j < sz(a); j++) {
          if (a[j] == '?')
            a[j] = '9';
          if (b[j] == '?')
            b[j] = '0';
        }
        break;
      } else
        continue;
    } else if (a[i] == '?' && b[i] != '?') {
      a[i] = b[i];
    } else if (a[i] != '?' && b[i] == '?') {
      b[i] = a[i];
    } else {
      a[i] = '0';
      b[i] = '0';
    }
  }
  return mp(a, b);
}


pair<string, string> best(pair<string, string> a, pair<string, string> b) {
  ll diff1 = abs(strtoint(a.X) - strtoint(a.Y));
  ll diff2 = abs(strtoint(b.X) - strtoint(b.Y));

  if (diff1 < diff2)
    return a;

  if (diff2 < diff1)
    return b;

  if (strtoint(a.X) < strtoint(b.X))
    return a;
  if (strtoint(a.X) > strtoint(b.X))
    return b;

  if (strtoint(a.Y) < strtoint(b.Y))
    return a;
  return b;
}


pair<string, string> solve(string a, string b) {
  pair<string, string> res = sol(a, b);
  for (int i = 0; i < sz(a); i++) {
    if (a[i] != '?' && b[i] != '?') continue;
    string at = a;
    string bt = b;
    if (a[i] == '?' && b[i] == '?') {
      at[i] = '0';
      bt[i] = '1';
      res = best(res, sol(at, bt));

      at[i] = '1';
      bt[i] = '0';
      res = best(res, sol(at, bt));
    } else if (a[i] != '?' && b[i] == '?') {
      if (a[i] != '9') {
        bt[i] = a[i] + 1;
        res = best(res, sol(at, bt));
      }
      if (a[i] != '0') {
        bt[i] = a[i] - 1;
        res = best(res, sol(at, bt));
      }
    } else if (a[i] == '?' && b[i] != '?') {
      if (b[i] != '9') {
        at[i] = b[i] + 1;
        res = best(res, sol(at, bt));
      }
      if (b[i] != '0') {
        at[i] = b[i] - 1;
        res = best(res, sol(at, bt));
      }

    }
  }
  return res;
}

int main() {
#ifdef ROMCHELA
  freopen("B22.in", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n;
  scanf("%d\n", &n);
  for (int T = 1; T <= n; T++) {
    string a, b;
    cin >> a >> b;
    int n = sz(a);
    int m = sz(b);
    while (sz(a) < sz(b) || sz(a) < 3)
      a = "0" + a;
    while (sz(b) < sz(a) || sz(b) < 3)
      b = "0" + b;

    //pair<string, string> ans = stupid(a, b);
    pair<string, string> res = solve(a, b);
    
    //if (ans != res) {
      //printf("my answer = %s %s\n", a.c_str(), b.c_str());
      //printf("correct answer = %s %s\n", ans.X.c_str(), ans.Y.c_str());
      //break;
    //}
    
    while (sz(res.X) != n) {
      res.X = res.X.substr(1, sz(res.X) - 1);
      //ans.X = ans.X.substr(1, sz(ans.X) - 1);
    }
    while (sz(res.Y) != m) {
      res.Y = res.Y.substr(1, sz(res.Y) - 1);
      //ans.Y = ans.Y.substr(1, sz(ans.Y) - 1);
    }
    printf("Case #%d: %s %s\n", T, res.X.c_str(), res.Y.c_str());
  }


#ifdef ROMCHELA
  cerr << "\nTIME ELAPSED: " << 1. * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
  return 0;
}
