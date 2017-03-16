#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

bool comp(PII a, PII b) { return a.second > b.second; }

int solve() {
  int n;
  cin >> n;
  assert(n <= 2);

  int s, m, t;
  vector<PII> v;
  for (int i = 0; i < n; ++i) {
    cin >> s >> m >> t;
    for (int j = 0; j < m; ++j) {
      v.push_back(PII(s, t + j));
    }
  }

  if (v.size() == 1) {
    return 0;
  }
  else {
    assert(v.size() == 2);
    sort(v.begin(), v.end(), comp);
/*
    double time_slow = (360.0 - v[0].first)/(360.0/v[0].second);
    double pos_fast = v[1].first + 360.0/v[1].second*time_slow;
    //cerr << v[0].first << " " << v[0].second << endl;
    //cerr << v[1].first << " " << v[1].second << endl;

    //cerr << time_slow << " " << pos_fast << endl;
    if (fabs(pos_fast - 720.0) < 1e-9) return 1;
    else if (pos_fast + 1e-6 > 720.0) return 1;
    return 0; */

    if (360*v[1].first*v[1].second + 360*(360 - v[0].first)*v[0].second >= 720*360*v[1].second) return 1;
    return 0;
  }

  return -1;
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": " << solve() << endl;
  }
}
