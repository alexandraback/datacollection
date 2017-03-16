#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f

using namespace std;

const double PI = acos(-1.0);
typedef pair<int, int> pii;
typedef long long ll;

int matJP[11][11], matPS[11][11], matJS[11][11];
int matUsed[11][11][11];

int mat[11][11];
int main (void) {
	int t; scanf("%d", &t);
	for (int cases = 1; cases <= t; cases++) {
		int J, p, s, k; scanf("%d %d %d %d", &J, &p, &s, &k);
		int iteracoes = 0;
		int begin = 0;
		vector < pair<int, pii> > ans;
		while (k--) {
			for (int i = 0; i < J; i++) {
				int k = (i + iteracoes) % s, counter = 0;
				int beg = k;
				do  {
					ans.pb(mp(i + 1, mp(++counter, k + 1)));
					k = (k - 1 + s) % s;
					if (counter == p) break;
				} while (k != beg);
			}
			iteracoes++;
			if (iteracoes % s == 0) break;
		} 
		printf("Case #%d: %d\n", cases, (int) ans.size());
		for (int i = 0; i < (int) ans.size(); i++) {
			printf("%d %d %d\n", ans[i].fi, ans[i].se.fi, ans[i].se.se);
		}
	}
	return 0;
}
