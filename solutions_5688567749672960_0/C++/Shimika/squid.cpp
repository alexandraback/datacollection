#include <stdio.h>
#include <queue>
#include <functional>
using namespace std;

int n, a[1200005];
typedef pair<int, int> pp;
priority_queue<pp, vector<pp>, greater<pp> > q;

int rev(int a) {
	int b[8] = { 0, };
	int d = 6;

	for (int i = 1; i <= 9; i++) {
		if (a == 0) {
			d = i - 1;
			break;
		}

		b[i] = a % 10;
		a /= 10;
	}

	int sum = 0, k = 1;
	for (int i = d; i >= 1; i--) {
		sum += k * b[i];
		k *= 10;
	}

	return sum;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (int i = 1; i <= 1000000; i++) {
		a[i] = 10000001;
	}
	a[1] = 1;

	q.push(make_pair(1, 1));

	do {
		pair<int,int> n = q.top();
		q.pop();

		int k = rev(n.second);

		if (a[k] > a[n.second] + 1) {
			a[k] = a[n.second] + 1;
			q.push(make_pair(a[k], k));
		}

		if (a[n.second + 1] > a[n.second] + 1 && n.second < 1000000) {
			a[n.second + 1] = a[n.second] + 1;
			q.push(make_pair(a[n.second + 1], n.second + 1));
		}
	} while (q.size());

	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		int w;
		scanf("%d", &w);
		printf("Case #%d: %d\n", t, a[w]);
	}
}