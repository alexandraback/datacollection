#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int determine_layer(int t) {
	int l = 1, n = 1;
	while (n < t) {
		l++;
		n += (l - 1) * 2 + 1;
	}
	return l;
}

int determine_layer_count(int t, int& n) {
	int l = 1;
	n = 1;
	while (n < t) {
		l++;
		n += (l - 1) * 4 + 1;
	}
	if (n == t) {
		n += (l - 1) * 4 + 1;
		return l;
	}
	return l - 1;
}

int count_on_layer(int l) {
	int r = 0;
	for (int i = 0; i < l; i++)
		r += i * 4 + 1;
	return r;
}

long long w_cnt[3000][3000];

long long count_of_ways(int i, int j) {
	if (i < 0 || j < 0)
		return 0;
	if (w_cnt[i][j] != 0)
		return w_cnt[i][j];
	if (i == 0 || j == 0)
		return w_cnt[i][j] = 1;
	return w_cnt[i][j] = count_of_ways(i - 1, j) + count_of_ways(i, j - 1);
}

void test(int num) {
	cout << "Case #" << num << ": ";
	int n, x, y;
	cin >> n >> x >> y;
	int l = (abs(x) + y) / 2 + 1;
	int max_c;
	int lays = determine_layer_count(n, max_c);
	if (lays >= l) {
		cout << "1.0\n";
		return;
	}
	if (lays != l - 1) {
		cout << "0.0\n";
		return;
	}

	int cntl = (l - 1) * 2;
	int cnts = cntl * 2;
	int least = n - count_on_layer(l - 1);
	int sum_p = 0, p = 0;
	//vector<int> tkk(cntl + 1);
	for (int i = 0; i <= cntl; i++) {
		if (i <= least && least - i >= 0 && least - i <= cntl) {
			int q = count_of_ways(i, least - i);
			sum_p += q;
			if (i > y)
				p += q;
		}
	}
	cout << double(p) / double(sum_p) << endl;
}
int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++)
		test(i+1);

	//cout << count_of_ways(1000, 1000);
}
