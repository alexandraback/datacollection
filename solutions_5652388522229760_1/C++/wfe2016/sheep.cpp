#include <iostream>
#include <vector>
using namespace std;

vector<long long int> digit(long long int a)
{
	vector<long long int> digits;

	if (a == 0)
	{
		digits.push_back(0);
	}

	while (a != 0)
	{
		digits.push_back(a % 10);
		a /= 10;
	}

	return digits;
}

int main()
{
	long long int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		long long int N;
		cin >> N;
		bool checklist[10];
		for (int j = 0; j < 10; j++)
		{
			checklist[j] = 0;
		}

		int isitcomplete = 0;

		for (long long int j = 0; j < 10000000; j++)
		{
			if (isitcomplete != 1){

				vector<long long int> digits = digit(N*(j+1));

				for (long long int k = 0; k < digits.size(); k++)
				{
					checklist[digits[k]] = 1;

				}



				isitcomplete = 1;
				for (int k = 0; k < 10; k++)
				{
					if (checklist[k] != 1)
					{
						isitcomplete = 0;
					}
				}

				if (isitcomplete == 1)
				{
					cout << "Case #" << i+1 << ": " << N*(j+1) << endl;
				}
			}
		}

		if (isitcomplete == 0)
		{
			cout << "Case #" << i+1 << ": " << "INSOMIA" << endl;
		}
	}
}