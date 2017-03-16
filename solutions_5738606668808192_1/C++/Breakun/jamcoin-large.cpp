#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, N, J;
	cin >> T >> N >> J;
	assert(T == 1 && N == 32 && J == 500);

	cout << "Case #1:" << endl;
	for (int b0 = 2; J && b0 < N - 1; b0 += 2)
		for (int b1 = b0 + 2; J && b1 < N - 1; b1 += 2)
			for (int b2 = b1 + 2; J && b2 < N - 1; b2 += 2)
				for (int b3 = b2 + 2; J && b3 < N - 1; b3 += 2)
					for (int b4 = b3 + 2; J && b4 < N - 1; b4 += 2)
						for (int b5 = b4 + 2; J && b5 < N - 1; b5 += 2) {
							bool field[32] = {false};
							field[0] = field[31] = true;
							field[b0] = true;
							field[b1] = true;
							field[b2] = true;
							field[b3] = true;
							field[b4] = true;
							field[b5] = true;

							for (int i = N - 1; i >= 0; i--)
								cout << field[i] ? '1' : '0';
							cout << " 3 2 3 2 5 2 3 2 3" << endl;

							J--;
						}

	assert(J == 0);
	return 0;
}
