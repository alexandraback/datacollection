#include <iostream>
#include <vector>
using namespace std;

long long rev(long long x) {
  long long y = 0;
  while (x) {
    y = (x % 10) + y * 10;
    x /= 10;
  }
  return y;
}



long long nnext(long long x) {
  long long y = 0;
  while (x >= 10) {
    y = 9 + y * 10;
    x /= 10;
  }
  return y;
}

long long next(long long x) {
  long long n = nnext(x);
  if (x >= n) return nnext(x * 10);
  return n;
}

long long solve(long long n) {
  std::vector<long long> a(n+1, 1000000);
  std::vector<long long> p(n+1, 1000000);
  for (int i = 0; i < a.size(); ++i) { a[i] = i; p[i] = i-1; }
  auto up =  [&](long long x, long long v, long long y) {
    if (x < 0 || x >= a.size()) return;
    if (a[x] > v) {
//      cerr << y << " " << x << " " << v << endl;
      a[x] = v;
      p[x] = y;
    }
  };
  for (long long i = 0; i < n+1; ++i) {
    long long x = i + 1;
    long long y = rev(i);
    up(x, a[i]+1,i);
    up(y, a[i]+1,i);
  }
  //cerr << a[n] << endl;
  int now = n;
//for (auto x : p ) cerr << x << " " ;
//cerr << endl;
  while (now>0) {
    cerr << now << endl;
    now = p[now];
  }
  return a[n];
  return 0;
}

long long go(long long from, long long to) {
  long long a = (to-from);
  for (int i = 0; i+from <= to && i <= 2e7; ++i) {
    long long b = i;
    long long y = from + i;
    y = rev(y);
    b ++;
    if (to >= y) {
      b += abs(to-y);
      if (a > b) {
        a = b;
      }
    }
  }
  return a;
}

long long solve2(long long n) {
  long long nn = 9;
  long long a = 0;
  long long now = 0;
  while (nn <= n) {
    a += go(now, nn);
    now = nn;
    nn = 9 + nn*10;
  }
  //cerr << now << " " << n << " " << a << endl;
  return a + go(now, n);
}

int main() {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    long long n;
    cin >> n;
    if (t > 80) {
//  cout << next(n) << endl;
//  continue;
//    cout << "Case #" << t << ": " <<  solve(n) << endl;
    cout << "Case #" << t << ": " <<  solve2(n) << endl;
    cerr << "Case #" << t << ": " <<  solve2(n) << endl;
    }

  }
}
