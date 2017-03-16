#include <cstdio>
#include <iostream>
#include <vector>

#define MAX 100000
#define BUG(x) {cerr<<(#x)<<" = "<<(x)<<endl;}

using namespace std;

int n, lim;

vector<int> p;
bool mark[MAX];

void eratosthenes() {
  for (int i = 2; i < MAX; i++) {
    if (!mark[i]) {
      p.push_back(i);
      for (int j = i + i; j < MAX; j += i) {
        mark[j] = true;
      }
    }
  }
}

bool test(int i, int b, int p) {
  int x = 1;
  int r = 0;

  for (int j = 0; j < n; j++) {
    int k = 1;
    if (0 < j && j < n - 1) {
      k = (i >> (j - 1)) & 1;
    }

    r = (r + k * x) % p;
    x = (x * b) % p;
  }

  return r == 0;
}

int test(int i, int b) {
  for (int j = 0; j < p.size() && p[j] < i; j++) {
    if (test(i, b, p[j])) {
      return p[j];
    }
  }
  return -1;
}

bool test(int i) {
  vector<int> results;

  for (int b = 2; b <= 10; b++) {
    int t = test(i, b);

    if (t == -1) {
      return false;
    }

    results.push_back(t);
  }

  cout << 1;
  for (int j = n - 3; j >= 0; j--) {
    cout << ((i >> j) & 1);
  }
  cout << "1 ";

  for (int j = 0; j < results.size(); j++) {
    cout << results[j] << " ";
  }
  cout << endl;
  return true;
}

void gen() {
  int found = 0;
  for (int i = 0; i < (1 << (n - 2)); i++) {
    if (test(i)) {
      found++;
      if (found == lim) {
        return;
      }
    }
  }
}

int main() {
  int ntest;
  cin >> ntest;

  eratosthenes();

  for (int test = 1; test <= ntest; test++) {
    cout << "Case #" << test << ":" << endl;

    cin >> n >> lim;
    gen();
  }
}
