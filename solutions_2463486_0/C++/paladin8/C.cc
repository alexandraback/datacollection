#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LIMIT 10000

vector<long long> p;

long long oddpal(long long x) {
  vector<int> d;
  long long tmp = x;
  while (tmp) { d.push_back(tmp % 10); tmp /= 10; }
  for (int i = 0; i+1 < d.size(); i++) x = 10 * x + d[i+1];
  return x;
}

long long evenpal(long long x) {
  vector<int> d;
  long long tmp = x;
  while (tmp) { d.push_back(tmp % 10); tmp /= 10; }
  for (int i = 0; i < d.size(); i++) x = 10 * x + d[i];
  return x;
}

long long ispal(long long x) {
  vector<int> d;
  long long tmp = x;
  while (tmp) { d.push_back(tmp % 10); tmp /= 10; }
  for (int i = 0; 2*i+1 < d.size(); i++)
    if (d[i] != d[d.size()-1-i]) return false;
  return true;
}

void go(long long x) {
  if (x >= LIMIT) return;

  long long x1 = oddpal(x);
  if (ispal(x1*x1)) p.push_back(x1);
  long long x2 = evenpal(x);
  if (ispal(x2*x2)) p.push_back(x2);

  for (int i = 0; i < 10; i++) go(10 * x + i);
}

int get(long long x) {
  for (int i = 0; i < p.size(); i++)
    if (p[i] * p[i] > x)
      return i;
  return p.size();
}

int main() {
  for (int i = 1; i < 10; i++) go(i);
  sort(p.begin(), p.end());

  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    long long A, B; cin >> A >> B;
    cout << "Case #" << c << ": " << get(B) - get(A-1) << endl;
  }
  return 0;
}
