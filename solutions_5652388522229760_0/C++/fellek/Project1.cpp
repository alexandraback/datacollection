
#include<iostream>
using namespace std;


bool allAppeared(bool* appeared) {

	for (int k = 0; k < 10; k++) {
		if (!appeared[k])return false;
	}
	return true;
}

void zeroAppeared(bool* appeared) {

	for (int k = 0; k < 10; k++) {
		appeared[k] = false;
	}
}

void evaluate(__int64 current, bool* appeared) {
	while (current > 0) {
		appeared[current % 10] = true;

		current = current / 10;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(true);
	int t;
	cin >> t;

	for (int k = 1; k <= t; k++) {
		__int64 n;
		cin >> n;
		if (n == 0) {
			cout << "Case #" << k << ": INSOMNIA" << endl;
			continue;
		}

		__int64 result;
		__int64 current = 0;
		int attempts = 0;


		bool* appeared = new bool[10];
		zeroAppeared(appeared);

		while (attempts < 10000000) {

			attempts++;
			current += n;

			evaluate(current, appeared);

			if (allAppeared(appeared)) {
				result = current;
				break;
			}

		}


		if (attempts == 10000000) {
			cout << "Case #" << k << ": INSOMNIA" << endl;
		}
		else {
			cout << "Case #" << k << ": " << result << endl;
		}
	}
	return 0;
}

