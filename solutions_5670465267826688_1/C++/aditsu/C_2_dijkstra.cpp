#include <iostream>
#include <vector>

using namespace std;

int mult[4][4] = {{1, 2, 3, 4}, {2, -1, 4, -3}, {3, -4, -1, 2}, {4, 3, -2, -1}};

int mm(int x, int y) {
  int t = 1;
  if (x < 0) {
    x = -x;
    t = -t;
  }
  if (y < 0) {
    y = -y;
    t = -t;
  }
  return mult[x - 1][y - 1] * t;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    int l;
    long long x;
    cin >> l >> x;
    string s;
    cin >> s;
    vector<int> v;
    int p = 1;
    for (int j = 0; j < l; ++j) {
      p = mm(p, s[j] - 'g');
      v.push_back(p);
    }
    vector<int> v2;
    v2.push_back(1);
    int p2 = 1;
    for (long long j = 0; j < x; ++j) {
      p2 = mm(p2, p);
      if (p2 == 1) {
        break;
      }
      v2.push_back(p2);
    }
    int z = v2.size();
    int a = v2[x % z];
    if (a != -1) {
      cout << "Case #" << i << ": NO" << endl;
      continue;
    }
    int n, k;
    int ok = 0;
    for (n = 0; n < z * 2; ++n) {
      for (k = 0; k < l; ++k) {
        if (ok == 0 && mm(v2[n % z], v[k]) == 2) {
          ok = 1;
        }
        if (ok == 1 && mm(v2[n % z], v[k]) == 4) {
          ok = 2;
          break;
	}
      }
      if (ok == 2) break;
    }
    cout << "Case #" << i << ": " << ((ok == 2 && n < x) ? "YES" : "NO") << endl;
  }
}
