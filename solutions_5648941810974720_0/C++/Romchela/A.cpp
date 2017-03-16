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
string d[] = {"FOUR", "SIX", "SEVEN", "EIGHT", "FIVE", "THREE", "TWO", "ZERO", "ONE", "NINE"};
int q[] = {4,6,7,8,5,3,2,0,1,9};

int main() {
#ifdef ROMCHELA
  freopen("A3.in", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int n;
  scanf("%d\n", &n);
  for (int T = 1; T <= n; T++) {
    string s;
    getline(cin, s);
    vector<int> cnt(30, 0);
    for (int i = 0; i < sz(s); i++) 
      cnt[s[i] - 'A']++;


    vector<int> ans;
    for (int i = 0; i <= 9; i++) {
      int j;
      bool flag = true;
      for (j = 0; j < sz(d[i]); j++) {
        if (cnt[d[i][j] - 'A']) {
          cnt[d[i][j] - 'A']--;
        } else {
          flag = false;
          break;
        }
      }

      if (flag) {
        i--;
        ans.pb(q[i + 1]);
        continue;
      } else {
        j--;
        for (; j >= 0; j--)
          cnt[d[i][j] - 'A']++;
      }
    }

    for (int i = 0; i <= 9; i++) {
      if (cnt[i] != 0) {
        assert(false);
      }
    }
    sort(all(ans));
    printf("Case #%d: ", T);
    for (int i = 0; i < sz(ans); i++)
      printf("%d", ans[i]);
    puts("");
  }

#ifdef ROMCHELA
  cerr << "\nTIME ELAPSED: " << 1. * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
  return 0;
}
