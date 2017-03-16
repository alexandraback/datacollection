#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2000;
int arr[MAXN];
int len;

int getSteps(int x) {
	int sum = 0;

	for (int i = 0; i < len; i++) {
		sum += (arr[i] - 1) / x;
	}

	return sum;
}

int getResult() {
	int result = 99999;
	for (int i = 1; i <= 1000; i++) {
		result = min(result, i + getSteps(i));
	}

	return result;
}

int main() {
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int nCases;
	cin >> nCases;

	for (int cnt = 1; cnt <= nCases; cnt++) {
		cin >> len;
		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}

		cout << "Case #" << cnt << ": " << getResult() << endl;
	}

	return 0;
}
