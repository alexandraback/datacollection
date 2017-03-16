#include<bits/stdc++.h>

using namespace std;

#define dbg(x) (cout<<#x<<" = "<<(x)<<'\n')

typedef long long int lld;
typedef pair<int, int> PII;
const int INF = (1LL << 30) - 1;
const lld LINF = (1LL << 62) - 1;
const int NMAX = 10 + 5;

int numberOfTests;
int N;
int D[NMAX];
int H[NMAX];
int M[NMAX];
vector<PII> K;

int solve() {
	int i, j;

	K.clear();

	for (i = 1; i <= N; i++)
		for (j = 1; j <= H[i]; j++)
			K.push_back(make_pair(D[i], M[i] + j - 1));

	if (K.size() <= 1)
		return 0;

	sort(K.begin(), K.end());

	if (K.size() == 2) {
		int a, b;
		int x, y;

		a = K[0].first;
		x = K[0].second;
		b = K[1].first;
		y = K[1].second;

		double vx = 360.0 / x;
		double vy = 360.0 / y;

		if (x == y)
			return 0;

		if (a == b) {
			double t = (360.0 - a) / vy;
			double newa = a + t * vx;
			return (newa >= 720.0);
		}

		if (x < y) {
			double t = (a - b) / (vy - vx);
			double newa = a + t * vx;
			double newb = b + t * vy;

			if (newa > 360.0)
				return 0;

			t = (360.0 - newb) / vy;
			newa = newa + t * vx;
			return (newa >= 720.0);
		} else {
			swap(a, b);
			swap(x, y);
			swap(vx, vy);

			double t = (a - b) / (vy - vx);
			double newa = a + t * vx;
			double newb = b + t * vy;

			if (newa > 360.0)
				return 0;

			t = (360.0 - newb) / vy;
			newa = newa + t * vx;
			return (newa >= 720.0);
		}
	}

	return 10;
}

int main() {
	cin.sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	scanf("%d", &numberOfTests);

	for (int testcase = 1; testcase <= numberOfTests; testcase++) {
		scanf("%d", &N);

		for (int i = 1; i <= N; i++)
			scanf("%d%d%d", &D[i], &H[i], &M[i]);

		printf("Case #%d: %d\n", testcase, solve());
	}



	return 0;
}