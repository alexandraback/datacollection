#pragma comment(linker, "/stack:32000000")
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <cassert>
#include <string.h>
#include <ctime>

#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


void solve() {
  vector<int> rem;
  forn(i, 10) rem.pb(i);
  string s; cin >> s;
  int cnt[300] = {};
  forn(i, sz(s)) cnt[s[i]]++;
  string ans;
  while (sz(rem)) {
    forn(cch, 26) {
      char ch = cch + 'A';
      int pos = -1;
      forn(ii, sz(rem)) {
        int curdig = rem[ii];
        if (count(ALL(digits[curdig]), ch)) {
          if (pos == -1) pos = curdig;
          else pos = -2;
        }
      }
      if (pos >= 0) {
        rem.erase(find(ALL(rem), pos));
        while (cnt[ch]) {
          forn(ii, sz(digits[pos])) cnt[digits[pos][ii]]--;
          ans += (char)(pos + '0');
        }
        break;
      }
    }
  }
  sort(ALL(ans));
  cout << ans << endl;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
  int T; scanf("%d", &T);
  for (int tn = 1; tn <= T; ++tn) {
    printf("Case #%d: ", tn);
    solve();
  }
	return 0;
}