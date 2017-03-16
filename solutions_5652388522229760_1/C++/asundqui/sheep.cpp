#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		int N;
		cin >> N;

		long long value = 0;
		if (N > 0)
		{
			int digits_remaining = 10;
			vector<bool> found(10, false);
			for (long long i = 1; i <= 1000000; ++i)
			{
				value = (long long)N * i;
				long long x = value;
				while (x > 0)
				{
					int digit = x % 10;
					if (!found[digit])
					{
						found[digit] = true;
						if (--digits_remaining == 0)
							break;
					}
					x /= 10;
				}
				if (digits_remaining == 0)
					break;
			}
		}

		cout << "Case #" << case_num << ": ";
		if (value == 0)
			cout << "INSOMNIA";
		else
			cout << value;
		cout << endl;
	}
	return 0;
}
