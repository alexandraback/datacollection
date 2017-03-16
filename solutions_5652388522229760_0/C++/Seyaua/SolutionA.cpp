#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstdio>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

using mask = bitset<10>;

mask getUsedDigits(int n) {
	mask result;
	while (n > 0) {
		result[n % 10] = true;
		n /= 10;
	}
	return result;
}

int countingSheep(int n) {
	if (n == 0) {
		return -1;
	}
	mask ans;

	int m = n;

	while (true) {
		ans |= getUsedDigits(m);
		if (ans.count() == 10) {
			return m;
		}
		m += n;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		int result = countingSheep(x);
		if (result == -1) {
			cout << "Case #" << i + 1 << ": " << "INSOMNIA" << endl;
		} else {
			cout << "Case #" << i + 1 << ": " << result << endl;
		}
	}

	return 0;
}