#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		int n;
		scanf("%d", &n);
		vector<int> data(n);
		for (int i=0; i<n; i++)
			scanf("%d", &data[i]);

		int sum = 0, maximum = 0;
		for (int i=0; i<n; i++) sum += data[i];

		vector<double> required(n);
		vector<pair<int, int>> order;
		double all = sum;
		for (int i=0; i<n; i++)
			order.push_back(make_pair(data[i], i));
		sort(order.begin(), order.end());

		int level = order.front().first;
		for (int i=1; i<n && all > 0; i++) {
			double diff = order[i].first - level;
			for (int j=0; j<i; j++)
				required[order[j].second] += min(diff, all / i);
			all -= diff * i;
			level += diff;
		}
		if (all > 0)
			for (int i=0; i<n; i++)
				required[i] += all/n;

		printf("Case #%d: ", t);
		for (int i=0; i<n; i++)
			printf("%lf ", required[i] / sum * 100);

		printf("\n");
	}
	return 0;
}