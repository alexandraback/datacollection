/* no greedy easy life */

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <queue>
#include <ctime>

#define pii pair<int, int>
  
#define pb push_back
#define mp make_pair
  
#define f first
#define s second
  
using namespace std;

typedef long long ll;
typedef double ld;

typedef vector<int> vi;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int INF = (int) 1e9 + 7;
const int MAXN = (int) 3e5 + 7;

string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int cnt[10][26];
int w[26];

bool used[10];

int main() {                                       
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif                                                                                          
  
  for (int i = 0; i < 10; i++) {
    for (auto it : digits[i])
      cnt[i][it - 'A']++;
  }

  vector<pii> order;
  for (int i = 0; i < 10; i++) {
    for (int ch = 0; ch < 26; ch++) {
      vector<int> all;
      for (int x = 0; x < 10; x++)
        if (!used[x] && cnt[x][ch]) all.pb(x);
      if (all.size() == 1) {
        used[all[0]] = 1;
        order.pb(mp(all[0], ch));
      }
    }
  }

  int t;
  cin >> t;
  for (int cs = 1; cs <= t; cs++) {
    printf("Case #%d: ", cs);
    string s;
    cin >> s;
    memset(w, 0, sizeof w);
    for (auto it : s)
      w[it - 'A']++;
    vector<int> ans;
    for (auto it : order) {
      assert(w[it.s] % cnt[it.f][it.s] == 0);
      int freq = w[it.s] / cnt[it.f][it.s];
      for (auto it : digits[it.f])
        w[it - 'A'] -= freq;
      while (freq--)
        ans.pb(it.f);
    }
    sort(ans.begin(), ans.end());
    for (auto it : ans)
      cout << it;
    cout << endl;
  }
  return 0;
}