#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>

using namespace std;

int *ds;

bool subarray(int n, int sum, int current, int current_n) {
	if (current == sum)
		return true;
	if (current > sum)
		return false;
	if (current_n == n)
		return false;
	bool first = subarray(n, sum, current + ds[current_n], current_n + 1);
	bool second = subarray(n, sum, current, current_n + 1);
	return (first || second);
}

int run() {
	int c, d, v;
	cin >> c >> d >> v;
	ds = new int[v];
	int a;
	int index = d;
	for (int i = 0; i < d; i++) {
		cin >> a;
		ds[i] = a;
	}
	int add = 0;
	for (int i = 1; i <= v; i++) {
		if (!subarray(index, i, 0, 0)) {
			add++;
			ds[index] = i;
			index++;
		}
	}
	delete [] ds;
	return add;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": " << run() << endl;
	}
	return 0;
}