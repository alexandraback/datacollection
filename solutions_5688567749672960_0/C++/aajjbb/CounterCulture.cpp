#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int MAXN = 1000005;

int T, N;
int dst[MAXN];

int rev(int x) {
	int ans = 0;

	while (x > 0) {
		ans = ans * 10 + (x % 10);
		x /= 10;
	}
	return ans;
}

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		memset(dst, 63, sizeof(dst));

		dst[1] = 1;

		queue<int> q;
		q.push(1);
		
		for ( ; !q.empty(); ) {
			int now = q.front();
			q.pop();

			if (now == N) {
				break;
			}

			int n1 = now + 1;
			int n2 = rev(now);

			if (n1 >= 1 && n1 <= N && dst[n1] > dst[now] + 1) {
				dst[n1] = dst[now] + 1;
				q.push(n1);				
			}
			if (n2 >= 1 && n2 <= N && dst[n2] > dst[now] + 1) {
				dst[n2] = dst[now] + 1;
				q.push(n2);				
			}
		}
		cout << "Case #" << t << ": " << dst[N] << endl;
	}
    return 0;
}
