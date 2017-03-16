#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::vector;

bool checkIfTwo(int i) {
	int count = 0;;
	while (i > 0) {
		if (i & 1 == 1) {
			++count;
		}

		i = i / 2;
	}

	return count == 1;
}

void solveCase() {
	int P, Q;
	scanf_s("%d/%d", &P, &Q);

	bool ok = checkIfTwo(Q);
	if (!ok) {
		cout << "impossible";
		return;
	}

	int i = Q / P;
	if (Q > P * i) {
		++i;
	}
	int m = 2;
	int c = 1;
	while (i > m) {
		m = m * 2;
		++c;
	}

	cout << c;
}

int main() {
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	int T;
	std::cin >> T;
	for (int i = 1; i < T + 1; ++i)
	{
		std::cout << "Case #" << i << ": ";
		solveCase();
		if (i < T)
			std::cout << std::endl;
	}
	return 0;
}