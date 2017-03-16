#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>
#include <deque>

using namespace std;

int war(vector<double> a, vector<double> b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  deque<double> qa, qb;
  for (int i = 0; i < (int)a.size(); i++) {
    qa.push_back(a[i]);
    qb.push_back(b[i]);
  }
  int r = 0;
  while (!qa.empty()) {
    if (qa.back() < qb.back()) {
      qa.pop_back();
      qb.pop_back();
    } else {
      qa.pop_back();
      qb.pop_front();
      r++;
    }
  }
  return r;
}

int deceitful_war(vector<double> a, vector<double> b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  deque<double> qa, qb;
  for (int i = 0; i < (int)a.size(); i++) {
    qa.push_back(a[i]);
    qb.push_back(b[i]);
  }
  int r = 0;
  while (!qa.empty()) {
    if (qa.front() < qb.front()) {
      qa.pop_front();
      qb.pop_back();
    } else {
      qa.pop_front();
      qb.pop_front();
      r++;
    }
  }
  return r;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<double> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];
    printf("Case #%d: ", t);
    printf("%d %d\n", deceitful_war(a, b), war(a, b));
  }
}