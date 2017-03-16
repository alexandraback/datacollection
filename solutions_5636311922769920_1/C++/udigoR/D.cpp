#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <tuple>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<bool> produce(vector<bool> &v, int K, int C) {
  int s = K;
  vector<bool> g(K, true);
  vector<bool> in(v), out;
  for (int i = 1; i < C; i++) {  
    out.erase(out.begin(), out.end());
    for (int j = 0; j < s; j++) {
      if (in[j] == true)
        out.insert(out.end(), g.begin(), g.end());
      else
        out.insert(out.end(), v.begin(), v.end());
    }
    in.swap(out);
    s *= K;
  }
  return in;
}

int check(int K, int C, vector<long long> &pos) {
  for (int i = 1; i <= K; ++i) {
    vector<bool> v(K, false);
    v[i-1] = true;
    auto x = produce(v, K, C);
    bool isOk = false;
    for (auto q:pos)
      if (x[q-1] == true) {
        isOk = true;
        break;
      }
    if (!isOk)
      return i;
  }
  return 0;
}

long long pow(long long x, long long y) {
  long long r = x;
  for (int i = 1; i < y; ++i)
    r *= x;
  return r;
}

int main() {
  int T;
  cin >> T;

  for (int testCase=0; testCase < T; ++testCase)
  {
    long long K, C, S; 
    cin >> K >> C >> S;

    long long p = 0, x = 1;
    vector<long long> pos;

    cout << "Case #" << testCase + 1 << ": ";

    if (K == 1) {
      pos.push_back(1);
    }

    if (C > K)
      C = K;

    while (x != K) {
      long long c = C;
      while (c > 1) {
        if (c - 2 != 0)
          p += x * pow(K, c-2);
        c--;
        x++;
        if (x == K) {
          break;
        }
      }
      pos.push_back(p + x);
      if (x < K) {
        if (C-1 != 0)
          p = x * pow(K, C-1);
        x++;
        if (x == K) {
          pos.push_back(p + x);
        }
      }
    }

    //cout << check(K, C, pos) << " ";
    
    if (pos.size() > S)
      cout << "IMPOSSIBLE";
    else
      for (auto k : pos)
        cout << k << " ";

    cout << endl;

  }

  return 0;
}