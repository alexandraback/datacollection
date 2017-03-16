#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int n, int cnt) {
	vector <int> arr(n - 2, 0);
	for (int i = 0; i < 4; i++)
		arr[n - i - 3] = 1;
	cout << "Case #1:" << endl;
	do {
		int p[2] = { 0, 0 };
		for (int i = 0; i < n - 2; i++)
			if (arr[i])
				p[i % 2]++;
		if (p[0] != p[1])
			continue;
		cout << 1;
		for (auto it : arr)
			cout << it;
		cout << "1 3 2 3 2 7 2 3 2 3" << endl;
		cnt--;
	} while (cnt && next_permutation(arr.begin(), arr.end()));
}

int main() {
	freopen("output.txt", "w", stdout);
	solve(32, 500);
}