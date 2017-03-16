#include <stdio.h>
#include <algorithm>
#include <deque>

int cheat(std::deque<double> a, std::deque<double> b) {
	int p = 0;
	while (!a.empty()) {
		if (a.front() > b.front()) {
			a.pop_front();
			b.pop_front();
			p++;
		} else {
			a.pop_front();
			b.pop_back();
		}
	}
	return p;
}

int nocheat(std::deque<double> a, std::deque<double> b) {
	int p = 0;
	while (!a.empty()) {
		while (!b.empty() && b.front() < a.front()) b.pop_front();
		if (b.empty()) {
			p++;
		} else {
			b.pop_front();
		}
		a.pop_front();
	}
	return p;
}

void solve() {
	int N;
	std::deque<double> a, b;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		double v;
		scanf("%lf", &v);
		a.push_back(v);
	}
	for (int i = 0; i < N; i++) {
		double v;
		scanf("%lf", &v);
		b.push_back(v);
	}
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	printf("%d %d\n", cheat(a, b), nocheat(a, b));
}

int main() {
	int T;
	scanf("%d", &T);
	for (int c = 1; c <= T; c++) {
		printf("Case #%d: ", c);
		solve();
	}
}