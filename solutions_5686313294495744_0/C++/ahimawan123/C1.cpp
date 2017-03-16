#include<iostream>
#include<set>
#include<string>
#include<cstdio>
using namespace std;

#define N 20
int p2[N];

bool cover(int x, int n, string w1[], string w2[]) {
  set<string> s1, s2;
  for (int i = 0; i < n; i++) {
    if (p2[i] & x) {
      s1.insert(w1[i]);
      s2.insert(w2[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (s1.find(w1[i]) == s1.end()) return false;
    if (s2.find(w2[i]) == s2.end()) return false;
  }
  return true;
}

int counting(int x) {
  int ret = 0;
  for (int i = 0; i < N; i++) {
    if (x & p2[i]) ret++;
  }
  return ret;
}

int main() {
  int cases, n;
  string w1[N], w2[N];
  for (int i = 0; i < 20; i++) {
    p2[i] = (1<<i);
  }
  cin >> cases;
  for (int cas = 1; cas <= cases; cas++) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> w1[i] >> w2[i];
    }
    int sol = n;
    for (int i = 0; i < p2[n]; i++) {
      int tmp = counting(i);
      if (tmp < sol && cover(i, n, w1, w2)) {
	sol = tmp;
      }
    }
    printf("Case #%d: %d\n", cas, (n-sol));
  }
  return 0;
}
