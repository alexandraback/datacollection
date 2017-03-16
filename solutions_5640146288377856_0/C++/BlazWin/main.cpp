#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define ll long long

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int jj = 0; jj < t; jj++) {
		int n,m,w;
		scanf("%d%d%d", &n,&m,&w);
		ll ans = 0;
		if (n > 1) {
			ans += (n - 1) * (m / w); 
		}	
		ans += m / w;
		if (m % w == 0) {
			ans += w - 1;
		} else {
			ans += w;
		}
		printf("Case #%d: %d\n", jj + 1, ans);
	}
	return 0;
}
