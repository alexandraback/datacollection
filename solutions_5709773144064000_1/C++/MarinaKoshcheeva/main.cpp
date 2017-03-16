#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>

using namespace std;

long double c, f, x;

void solve(int test_id) {
	cout << "Case #" << test_id << ": ";
	cin >> c >> f >> x;
	long double cur_time = 0;
	long double best_time = 1e100;
	for (int i = 0; ; ++i) {
		long double time_to_end = cur_time + x / (2.0 + i * f);
		long double time_to_farm = c / (2.0 + i * f);
		best_time = min(best_time, time_to_end);
		cur_time += time_to_farm;
		if (cur_time > best_time)
			break;
	}
	printf("%.7lf\n", best_time);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int test_id = 1; test_id <= t; ++test_id)
		solve(test_id);
	return 0;
}
