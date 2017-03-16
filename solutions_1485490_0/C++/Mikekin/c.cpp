#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

struct data
{
	long long x;
	int y;
};

int tt;
data fir[200], sec[200];
long long f[200][200], ans;
long long sum[200][200],tum[200][200],tmp;
int n, m;

int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		cin >> n >> m;
		memset(tum, 0, sizeof(tum));
		for (int i = 1; i <= n; i++) {
			cin >> fir[i].x >> fir[i].y;
			for (int j = 1; j <= 100; j++)
				tum[j][i] = tum[j][i - 1];
			tum[fir[i].y][i] += fir[i].x;
		}
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= m; i++) {
			cin >> sec[i].x >> sec[i].y;
			for (int j = 1; j <= 100; j++)
				sum[j][i] = sum[j][i - 1];
			sum[sec[i].y][i] += sec[i].x;
		}
		memset(f, 0, sizeof(f));
		ans = 0;
		for (int tot = 1; tot <= n + m; tot++) {
			for (int i = 0, j = tot; i <= n; i++, j--) {
				if (j > m) continue;
				for (int wi = 0; wi < i; wi++) {
					for (int wj = 0; wj < j; wj++) {
						tmp = sum[fir[i].y][j]- sum[fir[i].y][wj];
						tmp = min(tmp, tum[fir[i].y][i]-tum[fir[i].y][wi]);
						f[i][j] = max(f[i][j], f[wi][wj] + tmp);
						ans = max(ans, f[i][j]);
					}
				}
			}
		}
		printf("Case #%d: ",t);
		cout << ans << endl;
	}
	return 0;
}

