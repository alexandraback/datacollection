#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

size_t N, M, K;

vector <size_t> ps(const vector <size_t>& p) {
	if (p.size() == 0)
		return vector <size_t> {1};

	vector <size_t> pp = p;
	size_t x = pp.back();
	pp.pop_back();
	auto ansp = ps(pp);
	vector <size_t> ans;
	for (size_t i = 0; i < ansp.size(); i++) {
		ans.push_back(ansp[i]);
		ans.push_back(x * ansp[i]);
	}

	sort(ans.begin(), ans.end());
	return ans;
}

/* vector <size_t> ps(const vector <size_t>& p) {
	auto temp = subsets(p);
	vector <size_t> ans(temp.size(), 1);
	for (size_t i = 0; i < temp.size(); i++) {
		for (size_t j = 0; j < temp[i].size(); j++)
			ans[i] *= temp[i][j];
	}
	sort(ans.begin(), ans.end());
	return ans;
} */

string dw() {
	vector <size_t> prod(K);
	for (size_t i = 0; i < K; i++) {
		cin >> prod[i];
	}

	vector <size_t> guess(N, 2);
	while (true) {
		auto v = ps(guess);
		bool ans = true;
		for (size_t i = 0; i < K; i++) {
			if (!binary_search(v.begin(), v.end(), prod[i])) {
				ans = false;
				break;
			}
		}

		if (ans) {
			string ans = "";
			for (size_t i = 0; i < N; i++)
				ans.push_back('0' + guess[i]);
			return ans;
		}

		for (size_t i = 0; i < N; i++)
			if (guess[i] < M) {
				guess[i]++;
				for (size_t j = 0; j < i; j++)
					guess[j] = 2;
				break;
			}
	}
}

int main() {
	size_t T, R;
	cin >> T >> R >> N >> M >> K;
	cout << "Case #1:" << endl;
	for (size_t r = 0; r < R; r++)
		cout << dw() << endl;
	return 0;
}

