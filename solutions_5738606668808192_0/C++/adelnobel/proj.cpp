#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

const int MAXPRIMECHECK = 2000;
int MYMAXDEPTH = 15;
vector<int> primesToCheck;

int N, J;

vector<pair<int, vector<int> > > answer;

int powLog(int b, int p, int mod) {
  if (p == 0) {
    return 1;
  }
  int ret = powLog(b, p / 2, mod);
  ret *= ret;
  if (ret >= mod) {
    ret %= mod;
  }
  if (p & 1) {
    ret *= b;
    if (ret >= mod) {
      ret %= mod;
    }
  }
  return ret;
}

void solve(int depth, int mask) {
  if (depth == MYMAXDEPTH) {
    vector<int> myAns;
    bool isOkay = true;
    for (int base = 2; base <= 10 && isOkay; base++) {
      bool foundPrime = false;
      for (int j = 0; j < primesToCheck.size() && !foundPrime; j++) {
        int curMod = 1 + powLog(base, N - 1, primesToCheck[j]);
        if (curMod >= primesToCheck[j]) {
          curMod %= primesToCheck[j];
        }
        for (int k = 1; k < N - 1; k++) {
          if (mask & (1 << k)) {
            curMod += powLog(base, k, primesToCheck[j]);
            if (curMod >= primesToCheck[j]) {
              curMod -= primesToCheck[j];
            }
          }
        }
        if (curMod == 0) {
          foundPrime = true;
          myAns.push_back(primesToCheck[j]);
        }
      }
      if (!foundPrime) {
        isOkay = false;
      }
    }
    if (isOkay) {
      answer.push_back(make_pair(mask, myAns));
    }
    return;
  }

  solve(depth + 1, mask);
  if (answer.size() == J) return;
  solve(depth + 1, mask | (1 << depth));

}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("in.out", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string S;

  int T;
  cin >> T;

  for(int i = 2; i < MAXPRIMECHECK; i++) {
    bool isPrime = true;
    for(int j = 2; j*j <= i && isPrime; j++) {
      if (i % j == 0) isPrime = false;
    }
    if (isPrime) primesToCheck.push_back(i);
  }

  for (int t = 1; t <= T; t++) {
    cin >> N >> J;
    MYMAXDEPTH = min(N - 1, 16);
    cout << "Case #" << t << ":" << endl;

    solve(1, 0);
    assert(answer.size() == J);
    for(int i = 0; i < answer.size(); i++) {
      int num = answer[i].first;
      cout << 1;
      for(int j = N-2; j > 0; j--) {
        cout << ((num >> j) & 1);
      }
      cout << 1;
      assert(answer[i].second.size() == 9);
      for(int j = 0; j < 9; j++) {
        cout << " " << answer[i].second[j];
      }
      cout << endl;
    }

    cout << endl;
  }

  return 0;
}
