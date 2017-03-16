#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(a) (a).begin(), (a).end()
#define pb(x) push_back(x)
/*
ZERO (Z)
TWO (W)
SIX (X)
EIGHT (G)
FOUR (U)
THREE (H)
ONE (O)
FIVE (F)
SEVEN (S)
NINE (N)
TEN (T)
*/
typedef tuple<string, char, int> tsci;

string s;

int cnt[256];

int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int cn = 1; cn <= t; cn++) {
    cin >> s;
    memset(cnt, 0, sizeof(cnt));

    for (auto c : s) {
      cnt[(int)c]++;
    }
    printf("Case #%d: ", cn);

    vector<int> sol;
    for (auto p : vector<tuple<string, char, int>>({tsci{"ZERO", 'Z', 0},
                                                    tsci{"TWO", 'W', 2},
                                                    tsci{"SIX", 'X', 6},
                                                    tsci{"EIGHT", 'G', 8},
                                                    tsci{"FOUR", 'U', 4},
                                                    tsci{"THREE", 'H', 3},
                                                    tsci{"ONE", 'O', 1},
                                                    tsci{"FIVE", 'F', 5},
                                                    tsci{"SEVEN", 'S', 7},
                                                    tsci{"NINE", 'N', 9}})) {
      string w;
      char c;
      int d;
      tie(w, c, d) = p;
      while (cnt[(int)c] > 0) {
        sol.pb(d);
        for (auto c : w) {
          --cnt[(int)c];
        }
      }
    }

    sort(all(sol));
    for(int x : sol) {
      printf("%d", x);
    }
    printf("\n");
  }
  return 0;
}
