#include <iostream>

using namespace std;

int main() {

	int t;
	int result[100];
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int smax, stand = 0, need = 0;
		int shy[1001];
		char shylevel[1002];
		cin >> smax;

		getchar();
		for (int j = 0; j < smax + 1; ++j)
		{
			cin >> shylevel[j];
			shy[j] = shylevel[j] - '0';
		}
		shylevel[smax + 1] = '\0';

		for (int j = 0; j < smax + 1; ++j)
		{
			// cout << shy[j] << endl;
			if (stand >= j) // the shylevel will stand
			{
				stand += shy[j]; // the shylevel will not stand
			}
			else
			{
				need += j - stand;
				stand = j + shy[j];
			}
		}

		result[i] = need;
	}

	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i + 1 << ": " << result[i] << endl;
	}

	return 0;
}