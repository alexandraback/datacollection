#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define REP(i,n) for(int i=0;i<(n);++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define dump(x) cerr << "  (L" << __LINE__ << ") " << #x << " = " << (x) << endl;
#define dumpv(x) cerr << "  (L" << __LINE__ << ") " << #x << " = "; REP(q,(x).size()) cerr << (x)[q] << " "; cerr << endl;
template<typename T1, typename T2>
ostream& operator<<(ostream& s, const pair<T1, T2>& d) {return s << "(" << d.first << "," << d.second << ")";}

void solve(int N, vector<int>& S) {
  map<int, int> m;
  for (int i = 1; i < (1 << N) - 1; i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) sum += S[j];
    }

    if (m.find(sum) != m.end()) {
      int num1 = m[sum];
      int num2 = i;
      REP(k, N) if (num1 & (1 << k)) cout << S[k] << " ";
      cout << endl;
      REP(k, N) if (num2 & (1 << k)) cout << S[k] << " ";
      cout << endl;
      return;
    } else {
      m[sum] = i;
    }
  }
  cout << "Impossible" << endl;
}

int main() {
  int T; cin >> T;
  REP(t, T) {
    int N; cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    cout << "Case #" << t+1 << ":" << endl;
    solve(N, S);
  }
}

