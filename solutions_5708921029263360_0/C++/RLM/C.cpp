#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int J, P, S, K;
int TOP;
int maxres, maxcnt;
int res, cnt;
vvi jp, js, ps;

void update() {
  if (cnt > maxcnt) {
    maxres = res;
    maxcnt = cnt;
  }
}

void bt(int k) {
  if (k == TOP) return update();
  int j = k/(P*S);
  int p = (k/S)%P;
  int s = k%S;
  if (jp[j][p] < K and js[j][s] < K and ps[p][s] < K) {
    cnt++;
    jp[j][p]++;
    js[j][s]++;
    ps[p][s]++;
    res ^= (1<<k);
    bt(k+1);
    res ^= (1<<k);
    ps[p][s]--;
    js[j][s]--;
    jp[j][p]--;
    cnt--;
  }
  bt(k+1);
}

void print(int r) {
  for (int k = 0; k < TOP; ++k) if (r&(1<<k)) {
    int j = k/(P*S);
    int p = (k/S)%P;
    int s = k%S;
    cout << j+1 << ' ' << p+1 << ' ' << s+1 << endl;
  }
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> J >> P >> S >> K;
    cout << "Case #" << t << ": ";
    TOP = J*P*S;
    maxres = res = maxcnt = cnt = 0;
    jp = js = ps = vvi(3, vi(3, 0));
    bt(0);
    cout << maxcnt << endl;
    print(maxres);
  }
}