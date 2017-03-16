#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

const double eps = 1e-9;
const int inf = 1e9 + 23;

const int N = 1200;
int cnk[N][N];

int x, y, n;

void calc_cnk(){
	for (int i = 0; i < N; i++){
		cnk[i][0] = 1;
		for (int j = 1; j < N; j++)
			cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
	}
	return;
}

double calc_prob (int len, int h){
	if (h == len - 1){
		if (n >= len * 2 - 1)
			return 1;
		else
			return 0;
	}
	double ans = 0;
	double mult = 1;
	for (int i = 0; i < n; i++)
		mult /= 2;
	if (n < len){
		for (int i = 0; i <= h; i++)
			ans += cnk[n][i] * mult;
		return 1 - ans;
	}
	if (h + 1 + len - 1 <= n)
		return 1;
	double cur = 0;
	if (true){
		for (int i = n - (len - 1) + 1; i < len - 1; i++)
			cur += mult * cnk[n][i];
		ans += 0.5 - cur;
		if (h == len - 2)
			return ans;
		cur = 0;
		for (int i = n - (len - 1) + 1; i <= h + 1; i++)
			cur += mult * cnk[n][i];
		return ans + cur;
	}
	assert(false);
	return 0;
}

int main (void){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	calc_cnk();

	int t = 0;
	scanf("%d", &t);
	for (int it = 1; it <= t; it++){
		printf("Case #%d: ", it);

		scanf("%d %d %d", &n, &x, &y);
		if (x < 0) x = -x;
		int k = 1, all = 0;
		for (int i = 0; i < x + y; i += 2){
			all += 2 * k - 1;
			k += 2;
			if (all > n)
				break;
		}
		n -= all;
		if (n <= 0){
			printf("0\n");
			continue;
		}
		printf("%lf\n", calc_prob(k, y));
	}

	return 0;
}