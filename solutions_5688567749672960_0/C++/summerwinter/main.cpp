#include <iostream>
#include <stdint.h>
using namespace std;
uint64_t  reverse(uint64_t n)
{
	uint64_t result = 0;
	while (n > 0)
	{
		result = result * 10 + (n % 10);
		n /= 10;
	}
	return result;
}
int main()
{
	int T;
	uint64_t N;
	cin >> T;
	for (int k = 0; k < T; ++k)
	{
		cin >> N;

		cout << "Case #" << (k + 1) << ": ";
		
		uint64_t num = 1;
		while (N != 1)
		{
			if (N % 10 != 0 && reverse(N) < N)
			{
				N = reverse(N);
				++num;
			}
			else
			{
				--N;
				++num;
			}
		}

		cout << num << endl;
	}

	return 0;
}