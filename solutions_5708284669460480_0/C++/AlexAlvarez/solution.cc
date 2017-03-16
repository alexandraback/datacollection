#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

string target;
int a, b;

int dp_max(int pos, int k, vector<vector<int> >& M, vector<int>& pi, map<char, double>& P) {
  if (pos == b) return 0;
  int& ans = M[pos][k];

  if (ans == -1) {
    ans = 0;
    for (map<char, double>::iterator it = P.begin(); it != P.end(); ++it) {
      int kk = k;
      while (kk > 0 and target[kk] != it->first) kk = pi[kk];
      if (target[kk] == it->first) ++kk;
      int inc = 0;
      if (kk == a) {
        ++inc;
        kk = pi[kk];
      }
      ans = max(ans, inc + dp_max(pos + 1, kk, M, pi, P));
    }
  }

  return ans;
}

double dp_exp(int pos, int k, vector<vector<double> >& M, vector<int>& pi, map<char, double>& P) {
  if (pos == b) return 0;
  double& ans = M[pos][k];

  if (ans < -1) {
    ans = 0;
    for (map<char, double>::iterator it = P.begin(); it != P.end(); ++it) {
      int kk = k;

      while (kk > 0 and target[kk] != it->first) kk = pi[kk];
      if (target[kk] == it->first) ++kk;
      int inc = 0;
      if (kk == a) {
        ++inc;
        kk = pi[kk];
      }
      ans += it->second*(inc + dp_exp(pos + 1, kk, M, pi, P));
    }
  }

  return ans;
}

double solve() {
  int k;
  cin >> k >> a >> b;
  map<char, double> prob, P;
  for (int i = 0; i < k; ++i) {
    char c;
    cin >> c;
    ++prob[c];
  }
  for (map<char, double>::iterator it = prob.begin(); it != prob.end(); ++it) {
    P[it->first] = it->second/k; 
  }
  int kk = 0;
  vector<int> pi(a + 1);
  cin >> target;
  for (int i = 2; i <= a; ++i) {
    while (kk > 0 and target[i - 1] != target[kk]) kk = pi[kk];
    if (target[i - 1] == target[kk]) ++kk;
    pi[i] = kk;
  }

  vector<vector<double> > M(b + 2, vector<double>(a + 2, -5));
  vector<vector<int> > D(b + 2, vector<int>(a + 2, -1));
  double expected = dp_exp(0, 0, M, pi, P);
  int maxim = dp_max(0, 0, D, pi, P);
  return maxim - expected;
}

int main() {
  cout.setf(ios::fixed);
  cout.precision(8);
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": " << solve() << endl;
  }
}
