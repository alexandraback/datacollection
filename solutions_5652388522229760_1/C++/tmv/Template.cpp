#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>      // For greater<int>()

using namespace std;

static void HandleCase(const int cse)
{
	int N;
	cin >> N;

	int seenBits = 0; // 0, 1, 2, ..., 9

	int val, val0;
	int factor;
	for (factor = 1; factor <= 100; ++factor)
	{
		val0 = val = N * factor;
		int digit;
		while (true)
		{
			digit = val % 10;
			seenBits |= (1 << digit);
			if (val < 10)
				break;
			val = val / 10;
		}

		if (seenBits == (1 << 10) - 1)
			break;
	}

	if (factor == 101)
		cout << "Case #" << cse << ": INSOMNIA" << endl;
	else
		cout << "Case #" << cse << ": " << val0 << endl;
}


int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
		HandleCase(i + 1);

	return 0;
}


