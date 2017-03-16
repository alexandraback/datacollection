#include <iostream>
#include <map>
#include <bitset>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int nTestCase = 1; nTestCase <= T; nTestCase++)
	{
		int N;
		cin >> N;

		int S[20];
		for (int i = 0; i < 20; i++)
			cin >> S[i];

		map<int, bitset<20> > found;
		bitset<20> maskA, maskB;

		for (int mask = 1; mask < 1048576; mask++)
		{
			bitset<20> present(mask);
			int sum = 0;

			for (int i = 0; i < 20; i++)
				if (present[i])
					sum += S[i];
			if (found[sum].any())
			{
				maskA = found[sum];
				maskB = present;
				break;
			}
			
			found[sum] = present;
		}

		cout << "Case #" << nTestCase << ": " << endl;
		if (maskA.any())
		{
			for (int i = 0; i < 20; i++)
				if (maskA[i])
					cout << S[i] << ' ';
			cout << endl;
			for (int i = 0; i < 20; i++)
				if (maskB[i])
					cout << S[i] << ' ';
			cout << endl;
		}
		else
			cout << "Impossible" << endl;
	}

	return 0;
}
