#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define FORIT(it, obj) for(__typeof(obj.begin()) it=obj.begin();it!=obj.end();++it)
#define REP(i, N) for(int i = 0; i < N; i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define mp make_pair
#define pb push_back
#define bpc __builtin_popcount
typedef pair<int,int> pii;
typedef pair<string, string> pss;
typedef long long ll;

struct Q {
  int sgn, val;
  Q(int s, int v) : sgn(s), val(v) {}
  //  Q(const Q& other) : sgn(other.sgn), val(other.val) {}
  bool operator ==(const Q& other) const {
    return sgn == other.sgn && val == other.val;
  }
  bool operator !=(const Q& other) const {
    return sgn != other.sgn || val != other.val;
  }
  Q operator *(const Q& other) const;
  Q(){}
};

Q tab[4][4] = {
  {Q(1, 0), Q(1, 1), Q(1, 2), Q(1, 3)},
  {Q(1, 1), Q(-1, 0), Q(1, 3), Q(-1, 2)},
  {Q(1, 2), Q(-1, 3), Q(-1, 0), Q(1, 1)},
  {Q(1, 3), Q(1, 2), Q(-1, 1), Q(-1, 0)}
};


Q Q::operator *(const Q& other) const {
  Q ans = tab[val][other.val];
  ans.sgn *= sgn * other.sgn;
  return ans;
}

Q char2Q[256];
const Q q1 = Q(1, 0), qi = Q(1, 1), qj = Q(1, 2), qk = Q(1, 3);

bool pos(const string& S, ll X) {
  ll N = S.size();
  if (N*X < 3LL) return false;
  static Q pref[10500], suff[10500];
  Q sf = q1, pr = q1;
  REP(i, N) {
    sf = char2Q[(int)S[N-1-i]] * sf;
    pr = pr * char2Q[(int)S[i]];
    suff[N-1-i] = sf;
    pref[i] = pr;
  }
  suff[N+1] = q1;
  Q powers[4]; 
  powers[0] = q1;
  FOR(i, 1, 3) powers[i] = powers[i-1] * suff[0];
  Q iprod = q1;
  //  printf("n=%lld, X=%lld\n",N, X);
  for(ll i = 0; i <= min(X * N - 3, 4*N - 1); i++) {
    iprod = iprod * char2Q[(int)S[i % N]];
    if (iprod != qi) continue;
    //    printf("i=%lld\n", i);
    Q jprod = q1;
    for(ll j = i+1; j <= min(X * N - 2, i + 4*N); j++) {
      jprod = jprod * char2Q[(int)S[j % N]];
      if (jprod != qj) continue;
      //      printf("j=%lld\n", j);
      Q kprod = (j%N == N-1) ? q1 : suff[(j + 1) % N];
      kprod = kprod  * powers[(X - j/N - 1) % 4];
      if (kprod == qk)
	return true;
    }
  }
  return false;
}

int main() {
  char2Q[(int)'i'] = qi;
  char2Q[(int)'j'] = qj;
  char2Q[(int)'k'] = qk;
  int T; cin >> T;
  FOR(casenum, 1, T) {
    cout << "Case #" << casenum << ": ";
    ll L, X; cin >> L >> X;
    string S; cin >> S;
    cout << (pos(S, X) ? "YES" : "NO") << endl;
  }

  return 0;
}

