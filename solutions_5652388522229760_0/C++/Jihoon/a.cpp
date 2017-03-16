#include <iostream>

using namespace std;

unsigned solved = 0x3ff;

void markBitMap(unsigned & bitmap, unsigned n)
{
	unsigned cur_n = n;

	while (cur_n)
	{
		bitmap = bitmap | ( 1 << (cur_n % 10));

		cur_n = cur_n / 10;
	}
}

unsigned solve(unsigned N)
{
	unsigned bitmap = 0;

	int max_count = 100;

	for (int i = 1; i <= max_count; ++i)
	{
		markBitMap(bitmap, N * i);
		if (bitmap == solved)
		{
			return N * i;
		}
	}

	return 0;
}

int main()
{
	unsigned numInputs = 0;

	cin >> numInputs;

	for (size_t i=0; i< numInputs; ++i)
	{
		unsigned N = 0;

		cin >> N;

		cout << "Case #" << i + 1 << ": ";
		if (N == 0)
			cout << "INSOMNIA" << endl;
		else
			cout << solve(N) << endl;
	}
	return 0;
}

