#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1000000;
int T, n;
queue<int >q;
int f[10000011];
int mark[11111111];
int rev(int x){
	int res = 0;
	while (x > 0){
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}
int main(){	
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	scanf("%d", &T);
	for (int test = 1; test <= T; test++){
		scanf("%d", &n);

		for (int i = 0; i <= n; i++){
			f[i] = 0;
			mark[i] = 0;
		}
		while (!q.empty()) q.pop();

		q.push(1);
		f[1] = 1;
		mark[1] = 1;
		while (!q.empty()){
			int x = q.front();
			int dist = f[x];
			q.pop();
			if (!mark[x + 1]) {
				f[x + 1] = dist + 1;
				mark[x + 1] = 1;
				q.push(x + 1);
			}

			x = rev(x);
			if (x > n) continue;
			if (!mark[x]){
				f[x] = dist + 1;
				mark[x] = 1;
				q.push(x);
			}

			if (mark[n]) break;
		}

		printf("Case #%d: %d\n", test, f[n]);
	}
	return 0;
}