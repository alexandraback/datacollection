#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		uint32_t A, B, K;
		cin >> A >> B >> K;
		
		uint32_t numbers = 0;
		for (uint32_t a = 0; a < A; a++)
			for (uint32_t b = 0; b < B; b++)
				if ((a & b) < K)
					numbers++;

		cout << "Case #" << (i+1) << ": ";
		cout << numbers;
		cout << endl;
	}

	return 0;
}