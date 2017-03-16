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
    vector<int> a(n+1, n+1);
    a[1] = 1;
    rep(i,1,n) {
      a[i+1] = min(a[i+1], a[i] + 1);
      string s = to_string(i);
      reverse(all(s));
      int i2 = stoi(s);
      if (i2 > i && i2 <= n)
        a[i2] = min(a[i2], a[i] + 1);
    }
    cout << a[n] << endl;
	}
}
