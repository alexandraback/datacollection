#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> motes;
void deal(int caseNum) {
	int a, n;
	int now;
	int size;
	int min;
	int add;
	int p;
	scanf("%d%d", &a, &n);
	motes.clear();
	for (int i = 0; i < n; i++) {
		scanf("%d", &now);
		motes.push_back(now);
	}
	std::sort(motes.begin(), motes.end());
	size = motes.size();
	p = 0;
	min = 1000;
	add = 0;
	while (p < size) {
		while (p < size && a > motes[p]) {
			//printf("eat a %d motes[p] %d\n", a, motes[p]);
			a += motes[p];
			p++;
		}
		if (add + size - p < min) {
			min = add + size - p;
		}
		if (a == 1) break;
		while (p < size && a <= motes[p]) {
			//printf("add a %d motes[p] %d\n", a, motes[p]);
			a += a - 1;
			add++;
		}
	}
	printf("Case #%d: %d\n", caseNum + 1, min);
}
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		deal(i);
	}
	return 0;
}
