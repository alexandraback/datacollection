#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <functional>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;

const string PROGRAM_NAME = "google";

struct hiker {
  int start;
  int speed;
  bool operator<(const hiker& other) const {
    if (start != other.start) {
      return start < other.start;
    }

    return speed < other.speed;
  }
};

int sign(double d)  {
  if (d < -epsylon) {
    return -1;
  } else if (d > epsylon) {
    return 1;
  }

  return 0;
}
int solve(const hiker& a, const hiker& b) {
  if (a.speed == b.speed) {
    return 0;
  }
  double va = double(360)/double(a.speed);
  double vb = double(360)/double(b.speed);
  double v = vb - va;

  if (sign(v) > 0) {
    double dist = double(360 - b.start) + a.start;
    double t = dist / v;
    if (sign(t - double(360 - a.start)/ va) <= 0) {
      return 1;
    } else {
      return 0;
    }
  } else {
    double t2 = (double(360) + double(b.start - a.start)) / (-v);
    if (sign(t2 - double(360 - b.start) / vb) <= 0) {
      return 1;
    } else {
      return 0;
    }
  }
}
int main() {
  freopen((PROGRAM_NAME + ".in").c_str(), "r", stdin);
  freopen((PROGRAM_NAME + ".out").c_str(), "w", stdout);
  int nt;
  cin >> nt;
  for (int it = 1; it <= nt; it++) {
    int n;
    cin >> n;
    vector<hiker> a;
    for (int i = 0; i < n; ++i) {
      int d;
      int h;
      int m;
      scanf("%d %d %d", &d, &h, &m);
      for (int j =0; j< h; ++j) {
        hiker temp;
        temp.start = d;
        temp.speed = m + j;
        a.push_back(temp);
      }
    }

    sort(all(a));

    int answer = 0;
    if (a.size() == 2) {
      answer = solve(a[0], a[1]);
    }
    cout << "Case #" << it << ": " << answer << endl;
  }
  return 0;
}
