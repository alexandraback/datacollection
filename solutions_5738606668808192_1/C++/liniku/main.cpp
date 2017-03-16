#include <iostream>
#include <vector>
using namespace std;

typedef long long int LLI;

vector<LLI> p;

void bit_print(int x, int N) {
  vector<int> b;
  b.resize(N);
  b[N-1] = 1;
  int i = 0;
  while (x) {
    b[i] = x & 1;
    x >>= 1;
    ++i;
  }
  for (int i = b.size() - 1; i >= 0; --i) {
    cout << b[i];
  }
}

void gen_prime(int M) {
  vector<bool> t;
  p.clear();
  t.resize(M+1);
  for (int i = 2; i <= M; ++i) {
    t[i] = true;
  }
  for (int i = 2; i * i <= M; ++i) {
    if (t[i]) {
      for (int j = i + i; j <= M; j += i) {
        t[j] = false;
      }
    }
  }
  for (int i = 2; i <= M; ++i) {
    if (t[i]) {
      p.push_back(i);
    }
  }
}

int main() {
  int T, N, J, c;
  LLI x;
  vector<LLI> ans;
  ans.resize(11);
  gen_prime(1000);
  cin >> T >> N >> J;
  cout << "Case #1:" << endl;
  c = 0;
  x = 0;
  while (c < J) {
    bool success = true;
    for (int i = 2; i <=10; ++i) {
      LLI y, m, q;
      for (int j = 0; j < p.size(); ++j) {
        q = p[j];
        m = 1;
        // start bit
        for (int k = 0; k < N - 1; ++k) {
          m *= i;
          m %= q;
        }
        // middle bits
        y = 0;
        LLI t = x;
        LLI z = 1;
        while (t) {
          if (t & 1) {
            y += z;
          }
          t >>= 1;
          z *= i;
          z %= q;
        }
        y %= q;
        m += y;
        // end bit
        m += 1;
        m %= q;
        if (!m) {
          break;
        }
      }
      if (!m) {
        ans[i] = q;
      } else {
        success = false;
        break;
      }
    }
    if (success) {
      bit_print(x + 1, N);
      for (int i = 2; i <= 10; ++i) {
        cout << " " << ans[i];
      }
      cout << endl;
      ++c;
    }
    x += 2;
  }
  return 0;
}
