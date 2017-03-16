#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<ll, ll> pll;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define DB(X) { if(1) cerr << "DB: " << (#X) << " = " << (X) << endl; }

ll B, M;
vl poss;
bool f[50][50];

bool compute(ll b){
	if(b == B-1) return poss[B-1] == M;
	FOR(n, 0, B-b+1){
		FOR(next, b+1, b+n+1){
			poss[next] += poss[b];
			f[b][next] = true;
		}
		if(compute(b+1)) return true;
		FOR(next, b+1, b+n+1){
			poss[next] -= poss[b];
			f[b][next] = false;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll TC;
	cin >> TC;
	FOR(tc,0,TC){
		cin >> B >> M;
		FOR(i,0,50){
			FOR(j,0,50)
				f[i][j] = false;
		}
		poss = vl(B, 0);
		poss[0] = 1;
		cout << "Case #" << tc+1 << ": ";
		if(compute(0)){
			cout << "POSSIBLE" << endl;
			FOR(i,0,B){
				FOR(j,0,B){
					if(f[i][j]) cout << 1;
					else cout << 0;
				}
				cout << endl;
			}
		}
		else cout << "IMPOSSIBLE" << endl;
	}
}
