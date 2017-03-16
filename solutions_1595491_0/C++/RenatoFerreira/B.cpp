#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector < int > standard(int total) {
	vector < int > ans;

	ans.push_back(total / 3);
	total -= total / 3;

	ans.push_back(total / 2);
	total -= total / 2;

	ans.push_back(total);

	sort(ans.begin(), ans.end());

	return ans;
}

void expand(vector < int > &points) {
	if (points.front() == points.back()) {
		points[0]--;
		points[2]++;
	}
	else if (points[0] == points[1]) {
		points[1]++;
		points[0]--;
	}
	else {
		points[2]++;
		points[1]--;
	}
}

int main() {
	int tests; scanf("%d", &tests);
	
	for (int t = 1; t <= tests; t++) {
		int n, surprising, min_points;
		scanf("%d %d %d", &n, &surprising, &min_points);

		int ans = 0;

		for (int i = 0; i < n; i++) {
			int total; scanf("%d", &total);

			vector < int > points = standard(total);
			if (points[2] >= min_points)
				ans++;
			else if (2 <= total && total <= 28 && surprising > 0) {
				expand(points);

				if (points[2] >= min_points) {
					ans++;
					surprising--;
				}
			}
		}

		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}
