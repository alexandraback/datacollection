/*
Author:
Prob:
Link:
Tag:
Comp:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int MAX = 1e5 + 10;
const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int main(){
	// freopen("test.in", "rt", stdin);
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int t;
	ll n, m;
	int f[60][60];

	cin >> t;
	FOR(cs,1,t){
		cin >> n >> m;

		memset(f,0,sizeof(f));
		cout << "Case #" << cs << ":";
		if ((1LL << (n-2)) < m){
			cout << " IMPOSSIBLE\n";
			continue;
		}
		cout << " POSSIBLE\n";
		m--;
		f[1][n] = 1;
		for (int i = 2; i < n; i++){
			if (!m) break;
			f[1][i] = 1;
			for (int j = i-1; j > 1; j--)
				if ((1LL << (j-2)) <= m){
					f[i][j] = 1;
					m -= (1LL << (j-2));
				}
			if (m > 0){
				f[i][n] = 1;
				m--;
			}
		}

		FOR(i,1,n){
			FOR(j,1,n)
				cout << f[i][j];
			cout << endl;
		}
	}

	return 0;
}