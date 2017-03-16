#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double EPS = 1e-7;

#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())

const int MAX_D = 100;
int tc;

int data[MAX_D + 5];
void solve() {
  int C, D, V;
  scanf("%d %d %d", &C, &D, &V);
  REP(i, D) scanf("%d", &data[i]);
  sort(data, data + D);
  
  int idx = 0;
  ll toCover = 1;
  int ans = 0;
  // BEWARE OVERFLOW! USED LONG LONG - FIXED?
  while(toCover <= V) {
    while(idx < D && data[idx] <= toCover) toCover += (ll)data[idx++]*(ll)C;
    if (toCover <= V) {
      ans++;
      toCover += toCover*(ll)C;
    }
    //printf("toCover = %lld\n", toCover);
  }  
  printf("Case #%d: %d\n", tc, ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (tc = 1; tc <= T; tc++) solve();
	return 0;
}
