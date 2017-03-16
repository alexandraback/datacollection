#include <bits/stdc++.h>

using namespace std;

const int IT = 100;

int get_mask(long long x) {
  int result = 0;

  while (x) {
    result |= 1 << (x % 10);
    x /= 10;
  } 

  return result;
}

long long f(int n) {
  if (n == 0) {
    return -1ll;
  }

  int mask = 0;
  for (int i = 1; i <= IT; i++) {
    mask |= get_mask(n * 1ll * i);

    if (mask + 1 == (1 << 10)) {
      return n * 1ll * i;
    }
  }

  return -1ll;
}

void set_up() {
  int counter = 0;
  for (int x = 0; x <= 1000000; x++) {
    counter += f(x) == -1;
  }

  cerr << counter << "\n";
}

void solve(int case_id) {
  int n; cin >> n;

  int result = f(n);

  cout << "Case #" << case_id << ": ";
  if (result == -1) {
    cout << "INSOMNIA\n";
  } else {
    cout << f(n) << "\n";
  }
}

int main() {
  // set_up();

  int cases; cin >> cases;

  for (int i = 1; i <= cases; i++) {
    solve(i);
  }

  return 0;
}