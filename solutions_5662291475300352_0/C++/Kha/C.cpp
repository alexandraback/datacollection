#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define rep(i,s,e) for (int i=(s);i<(e);++i)
#define pb push_back
#define mk make_pair
#define fst first
#define snd second
#define all(x) (x).begin(),(x).end()
#define clr(x,y) memset(x,y,sizeof x)
#define contains(x,y) (x).find(y)!=(x).end()
#define endl "\n"

int dx[]={0,0,1,-1,1,-1,1,-1}, dy[]={-1,1,0,0,1,-1,-1,1};
const int mod = 1e9+7;

int main() {
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(16);

	int t;
	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cout << "Case #" << ti << ": ";
    int n; cin >> n;
    vector<int> starts, times;
    rep(i,0,n) {
      int d, h, m; cin >> d >> h >> m;
      rep(j,0,h) {
        starts.pb(d);
        times.pb(m+j);
      }
    }
    if (starts.size() < 2)
      cout << 0 << endl;
    else {
      int min_sol = INT_MAX;
      ll hed = *min_element(all(starts));
      for (auto ti : times) {
        ll het = ti * (360 - hed);
        int sol = 0;
        rep(i,0,starts.size()) {
          ll hit = times[i], d = starts[i];
          ll stop = d * hit + het;
          if (stop < 360 * hit || stop >= 2 * 360 * hit)
            sol++;
        }
        min_sol = min(min_sol, sol);
      }
      cout << min_sol << endl;
    }
	}
}
