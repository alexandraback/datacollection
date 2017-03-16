#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

#define endl "\n"
#define all(x) x.begin(), x.end()

typedef long long ll;

struct hiker
{
  int d, h, m;

  double time() const
  {
    int r = 360 - d;
    return r / 360.0 * m;
  }
};

const double EPS = 1e-5;

int cnt = 0;

void solve()
{
  ++cnt;
  int n;
  cin >> n;
  if (n == 1) {
    cerr << "ASD" << cnt;
    cout << 0 << endl;
    int a, b, c;
    cin >> a >> b >> c;
    return;
  }
  hiker h1, h2;
  cin >> h1.d >> h1.h >> h1.m;
  cin >> h2.d >> h2.h >> h2.m;

  if (h1.d < h2.d || (h1.d == h2.d && h1.m > h2.m)) {
    swap(h1, h2);
  }

  if (abs(h1.time() - h2.time()) < EPS
      || abs(h1.time() + h1.m - h2.time()) < EPS
      || abs(h2.time() + h2.m - h1.time()) < EPS) {
    cerr << "FDAIL";
    cerr << cnt;
  }

  if (h1.time() + h1.m + EPS < h2.time()) {
    cout << 1 << endl;
  } else {
    if (h2.time() + h2.m + EPS < h1.time()) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_cases;
  cin >> test_cases;

  for (int t = 1; t <= test_cases; t++) {
    //cerr << "Solving " << t << endl;
    cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
