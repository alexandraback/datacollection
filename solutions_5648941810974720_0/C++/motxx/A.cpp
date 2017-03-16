#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <assert.h>
#include <array>
#include <cstdio>
#include <cstring>
#include <random>
#include <functional>
#include <numeric>
#include <bitset>
#include <fstream>

using namespace std;

struct before_main{before_main(){cin.tie(0); ios::sync_with_stdio(false);}} before_main;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

int main() {
#if 0
  rep(i, 10) {
    string u = "FOURFIVENINEONEFOURFIVENINEONEFOURFIVENINEONE";
    srand(unsigned(time(NULL)));
    random_shuffle(all(u));
    cout << u << endl;
  }
  return 0;
#endif

  int N; cin >> N;
  rep(i, N) {
    string s; cin >> s;
    int n = s.size();
    map<char, int> mp;
    rep(i, n) {
      mp[s[i]] ++;
    }

    cout << "Case #" << i+1 << ": ";
    stringstream ss;
    int T = mp['Z'];
    rep(i, T) {
      ss << "0"; mp['Z']--, mp['E']--, mp['R']--, mp['O']--;
    }
    T = mp['W'];
    rep(i, T) {
      ss << "2"; mp['T']--, mp['W']--, mp['O']--;
    }
    T = mp['X'];
    rep(i, T) {
      ss << "6"; mp['S']--, mp['I']--, mp['X']--;
    }
    T = mp['G'];
    rep(i, T) {
      ss << "8"; mp['E']--, mp['I']--, mp['G']--, mp['H']--, mp['T']--;
    }
    T = mp['T'];
    rep(i, T) {
      ss << "3"; mp['T']--, mp['H']--, mp['R']--, mp['E']-=2;
    }
    T = mp['S'];
    rep(i, T) {
      ss << "7"; mp['S']--, mp['E']-=2, mp['V']--, mp['N']--;
    }
    T = min({mp['F'], mp['O'], mp['U'], mp['R']});
    rep(i, T) {
      ss << "4"; mp['F']--, mp['O']--, mp['U']--, mp['R']--;
    }
    T = min({mp['F'], mp['I'], mp['V'], mp['E']});
    rep(i, T) {
      ss << "5"; mp['F']--, mp['I']--, mp['V']--, mp['E']--;
    }
    T = min({mp['N']/2, mp['I'], mp['E']});
    rep(i, T) {
      ss << "9"; mp['N']-=2, mp['I']--, mp['E']--;
    }
    T = min({mp['O'],mp['N'],mp['E']});
    rep(i, T) {
      ss << "1"; mp['O']--, mp['N']--, mp['E']--;
    }
    auto U = ss.str(); sort(all(U));
    cout << U << endl;
  }
  return 0;
}