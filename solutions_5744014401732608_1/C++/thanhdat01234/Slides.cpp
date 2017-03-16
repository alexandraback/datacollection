#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

ll Pow(int p){
	return 1LL << p;
}

int main(){
	freopen("in.inp", "r", stdin);
	freopen("ou.out", "w", stdout);

	int t;
	ll n, m;
	int f[60][60];

	scanf("%d", &t);
	for (int itest = 0; itest < t; ++itest) {
		scanf("%lld %lld", &n, &m);

		memset(f,0,sizeof(f));
		cout << "Case #" << itest + 1 << ":";
		if ((1LL << (n-2)) < m){
			cout << " IMPOSSIBLE\n";
			continue;
		}
		m--;
		f[1][n] = 1;
		cout << " POSSIBLE\n";
		for (int i = 2; i < n; i++){
			if (!m) break;
			f[1][i] = 1;
			for (int j = i-1; j > 1; j--)
				if (Pow(j-2) <= m){
					f[i][j] = 1;
					m -= Pow(j-2);
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