#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,m,n) for(long long i = m; i < n; ++i)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define eps 1e-7
#define FOR(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;
bool vow(char cha) {
  re cha == 'a' || cha == 'e' || cha == 'i' || cha == 'o' || cha == 'u';
}
int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin("submission.in");
  ofstream fout("submission.out");
  int T;
  fin >> T;
  for (int TAT = 1; TAT < T + 1; ++TAT) {
    int N;
    fin>> N;
    vi d(N), n(N), w(N), e(N), s(N), dd(N), dp(N), ds(N);
    multimap<int, vi> st;
    rep(i,0,N)
    {
      fin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
      vi pn(3);
      pn[0] = w[i];
      pn[1] = e[i];
      pn[2] = s[i];
      rep(j,0,n[i])
      {
        st.insert(mp(d[i], pn));
        d[i] += dd[i];
        pn[0] += dp[i];
        pn[1] += dp[i];
        pn[2] += ds[i];
      }
    }
    vi wall(600, 0), tw(600, 0);
    int day = -1, res = 0;
    for (multimap<int, vi>::iterator it = st.begin(); it != st.end(); ++it) {
      if (day < it->fi) {
        day = it->fi;
        wall = tw;
      }
      vi sst = it->se;
      bool ok = false;
      rep(i,sst[0],sst[1])
        if (wall[i + 300] < sst[2]) {
          ok = true;
          tw[i + 300] = max(tw[i + 300], sst[2]);
        }
      if (ok)
        ++res;
    }
    fout << "Case #" << TAT << ": " << res << endl;
  }
  return 0;
}
