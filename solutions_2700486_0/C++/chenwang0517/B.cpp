#include <cstdio>
#include <cmath>
using namespace std;

double opt[4010][4010];
int cases, n, x, y;

int main(){
	scanf("%d", &cases);
	for (int tot = 0; tot < cases; ++ tot){
		scanf("%d%d%d", &n, &x, &y);
		int cur = 1;
		int cnt = 0;
		while (n >= cur){
			n -= cur;
			cnt++;
			cur += 4;
		}
		int k = (abs(x) + y) / 2;
		double ans = 0;
		if (k < cnt) ans = 1;
		if (k == cnt){
			y++;
			if (n < y) ans = 0;
			else{
				if (y <= n - k * 2) ans = 1;
				else{
					for (int i = 0; i <= n; ++i)
						for (int j = 0; j <= i; ++j)
							opt[i][j] = 0;
					opt[0][0] = 1;
					for (int i = 0; i < n; ++i){
						for (int j = 0; j <= i; ++j){
							int left = j;
							int right = i - j;
							if (left + 1 > k * 2){
								opt[i + 1][j] += opt[i][j];
							}
							else if (right + 1 > k * 2){
								opt[i + 1][j + 1] += opt[i][j];
							}
							else{
								opt[i + 1][j] += opt[i][j] * 0.5;
								opt[i + 1][j + 1] += opt[i][j] * 0.5;
							}
						}
					}
					for (int i = y; i <= k * 2; ++i) ans += opt[n][i];
				}
			}
		}
		printf("Case #%d: %.8lf\n", tot + 1, ans);
	}
}