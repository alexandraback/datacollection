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
string tab[4][4] = {
  {"1", "i", "j", "k"},
  {"i", "-1", "k", "-j"},
  {"j", "-k", "-1", "i"},
  {"k", "j", "-i", "-1"}
};

string mul(string a, string b) {
  const bool neg = ((a[0] == '-') ^ (b[0] == '-'));
  const char ac = a[a.size() - 1], bc = b[b.size() - 1];
  const int ai = (ac == '1' ? 0 : ac - 'i' + 1);
  const int bi = (bc == '1' ? 0 : bc - 'i' + 1);
  const string uprod = tab[ai][bi];
  
  if (neg)
    return uprod[0] == '-' ? uprod.substr(1) : "-" + uprod;
  else
    return uprod;
}

bool pos(const string& S) {
  int N = S.size();
  if (N < 3) return false;
  static string kprods[10500];
  string suff = "1";
  for(int k = N-1; k >= 0; k--) {
    suff = mul(S.substr(k, 1), suff);
    kprods[k] = suff;
  }
  string iprod = "1";
  FOR(i, 0, N-3) {
    iprod = mul(iprod, S.substr(i, 1));
    //    cout << iprod << endl;
    if (iprod != "i") continue;
    //    cout << "i=" << i << endl;
    string jprod = "1";
    FOR(j, i+1, N-2) {
      jprod = mul(jprod, S.substr(j, 1));
      if (jprod != "j") continue;
      //      cout << "j=" << j << endl;
      const string& kprod = kprods[j+1];
      if (kprod == "k")
	return true;
    }
  }
  return false;
}

int main() {
  int T; cin >> T;
  FOR(casenum, 1, T) {
    cout << "Case #" << casenum << ": ";
    int L, X; cin >> L >> X;
    string pat; cin >> pat;
    string S = "";
    REP(i, X) S += pat;
    cout << (pos(S) ? "YES" : "NO") << endl;
  }

  return 0;
}

