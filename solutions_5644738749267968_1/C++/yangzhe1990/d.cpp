#include <iostream>
#include <algorithm>
#include <vector>

int w_score(int n, const std::vector<double> &n_weights, const std::vector<double> &k_weights) {
	int head = 0;
	int rear = n - 1;

	int ret = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (k_weights[rear] > n_weights[i])
			--rear;
		else {
			++head;
			ret += 1;
		}
	}
	return ret;
}

int d_score(int n, const std::vector<double> &n_weights, const std::vector<double> &k_weights) {
	int head = 0;
	int rear = n - 1;

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		if (k_weights[head] > n_weights[i])
			--rear;
		else {
			++ret;
			++head;
		}
	}
	return ret;
}

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		std::cin >> n;
		std::vector<double> n_weights(n), k_weights(n);
		for (int j = 0; j < n; ++j)
			std::cin >> n_weights[j];
		for (int j = 0; j < n; ++j)
			std::cin >> k_weights[j];
		std::sort(n_weights.data(), n_weights.data() + n);
		std::sort(k_weights.data(), k_weights.data() + n);

		std::cout << "Case #" << i + 1 << ": " << d_score(n, n_weights, k_weights) << ' ' << w_score(n, n_weights, k_weights) << '\n';
	}
}
