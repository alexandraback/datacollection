#include <bits/stdc++.h>
#include <iostream>
#include <cstdint>

#define fori(i,b,e) for (int i = (b); i < (e); i++)
#define mp make_pair
#define pb push_back
#define add insert
#define all(a) (a).begin(), (a).end()
#define elsif else if
#define sz(a) ((int)(a).size())

using namespace std;

typedef long long int int64;

inline int getInt() { int res;  scanf("%d", &res);  return res; }
inline double getDbl() { double res;  scanf("%lf", &res);  return res; }
int s[100];
const int lim = 10000;
int rems[11][lim];
int n;

void clear() {
}

void read() {
}

void inc() {
  int i = n-2;
  while (s[i]) {
    s[i] = 0;
    i--;
  }
  s[i] = 1;
}


void solve() {
  n = getInt();
  fori(b,2,11) {
    fori(i,2,lim) {
      int cur = 1;
      fori(t,0,n-1) {
        cur = cur * b % i;
      }
      rems[b][i] = (i - cur) % i;
    }
  }
  int k = getInt();
  s[0] = 1;
  fori(i,1,n-1)
    s[i] = 0;
  s[n-1] = 1;
  fori(i,0,k) {
    while (true) {
      bool outerGood = true;
      vector<int> divs;
      fori(b, 2, 11) {
        int64 cur = 0;
        fori(i,1,n)
          cur = cur * b + s[i];
        bool good = false;
        fori(i,2,10000) {
          if (cur != i && cur % i == rems[b][i]) {
            good = true;
            divs.pb(i);
            break;
          }
        }
        if (!good) {
          outerGood = false;
          break;
        }
      }
      if (outerGood) {
        fori(i,0,n)
          printf("%d", s[i]);
        printf(" ");
        for (auto x : divs)
          printf("%d ", x);
        printf("\n");
        /*fori(b, 2, 11) {
          int64 cur = 0;
          fori(i,0,n)
            cur = cur * b + s[i];
          cout << cur << " ";
        }
        printf("\n");*/
        inc();
        break;
      }
      inc();
    }
    cout.flush();
  }
}

int main() {
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  srand(time(0));
  int N = getInt();
  fori(T,1,N+1) {
    clear();
    read();
    printf("Case #%d:\n", T);
    solve();
  }
  return 0;
}
