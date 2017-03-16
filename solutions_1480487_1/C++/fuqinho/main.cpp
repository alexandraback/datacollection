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


int main() {
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int N; cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    int sum = 0;
    for (int i = 0; i < N; i++) sum += S[i];

    vector<int> S2 = S;
    sort(S2.begin(), S2.end());

    int filled = N;
    int fsum = sum;
    for (int i = N-1; i >= 0; i--) {
      if (S2[i] * (i+1) > sum + fsum) {
        filled = i;
        fsum -= S2[i];
      } else {
        break;
      }
    }

    double thresh = ((double)sum + fsum) / filled;
    printf("Case #%d: ", t+1);
    for (int i = 0; i < N; i++) {
      double p = (thresh - S[i]) / sum;
      if (p >= 0) {
        printf("%.6f ", p * 100);
      } else {
        printf("%.6f ", 0.0);
      }
    }
    printf("\n");
  }
}

