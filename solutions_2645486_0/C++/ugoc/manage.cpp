#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int manage(vector<int>& v, int s, int e, int init_val, int end_val, int E, int R) {
  if (e < s) return 0;
  if (end_val - init_val == R * (e - s)) return 0;
  //cout << s << " - " << e << ": " << init_val << " -> " << end_val << endl;
  if (e == s) return (init_val - end_val) * v[s];
  vector<int>::iterator m = max_element(v.begin() + s, v.begin() + e + 1);

  int offset = m - v.begin();
  int before = min<int>(E, init_val + R * (offset - s));
  int after = max<int>(0, end_val - R * (e - offset));
  int gain = (before - after) * (*m);
  //cout << "gain = v[" << offset << "] * " << (before - after) << " = "
  //  << gain << endl;
  return gain + manage(v, s, offset - 1, init_val, max<int>(0, before - R), E, R)
    + manage(v, offset + 1, e, min<int>(E, after + R), end_val, E, R);
}

void solve(int n) {
  int E, R, N;
  cin >> E >> R >> N;
  vector<int> v;
  for (int i = 0; i < N; ++i) {
    int x;
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
