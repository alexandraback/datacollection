#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int testCount;
	cin >> testCount;
	for (int testCase = 1; testCase <= testCount; ++testCase){
		int n, m, k;
		cin >> n >> m >> k;
		printf("Case #%d: ", testCase);
		if (k < 5) printf("%d\n", k);
		else {
			if (n > m) swap(n, m);
			int init = 5, res = 4;
			int a = 3, b = 3;
			if (n == 1) a = 2, b = 2, init = 4;
			int i = 0;
			while (init < k){
				if (i % 2 && a < n + 1){
					if (init + 1 == k){
						res++;
						break;
					}
					++a, init += b;
					res += 2;
				} else {
					if (init + 1 == k){
						res++;
						break;
					}
					if (b < m + 1) {
						++b, init += a;
						res += 2;
					} else {
						res += k - init;
						init = k;
					}
				}
				++i;
			}
			cout << res << endl;
		}
	}
	return 0;
}

