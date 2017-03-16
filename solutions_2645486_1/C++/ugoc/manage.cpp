#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long manage(vector<long long>& v, long long s, long long e, long long init_val, long long end_val, long long E, long long R) {
  if (e < s) return 0;
  if (end_val - init_val == R * (e - s)) return 0;
  //cout << s << " - " << e << ": " << init_val << " -> " << end_val << endl;
  if (e == s) return (init_val - end_val) * v[s];
  vector<long long>::iterator m = max_element(v.begin() + s, v.begin() + e + 1);

  long long offset = m - v.begin();
  long long before = min<long long>(E, init_val + R * (offset - s));
  long long after = max<long long>(0, end_val - R * (e - offset));
  long long gain = (before - after) * (*m);
  //cout << "gain = v[" << offset << "] * " << (before - after) << " = "
  //  << gain << endl;
  return gain + manage(v, s, offset - 1, init_val, max<long long>(0, before - R), E, R)
    + manage(v, offset + 1, e, min<long long>(E, after + R), end_val, E, R);
}

void solve(long long n) {
  long long E, R, N;
  cin >> E >> R >> N;
  vector<long long> v;
  for (long long i = 0; i < N; ++i) {
    long long x;
    cin >> x;
    v.push_back(x);
  }
  cout << "Case #" << n << ": " << manage(v, 0, v.size() - 1, E, 0, E, R)
    << endl;
}

int main(int argc, const char *argv[]) {
  int N;
  cin >> N;
  cin.ignore(100000, '\n');
  for (int n = 0; n < N; n++) {
    solve(n + 1);
  }
  return 0;
}
