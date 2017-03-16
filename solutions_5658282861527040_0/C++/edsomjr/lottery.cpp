#include <iostream> 
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int test = 1; test <= T; test++)
	{
		int a, b, k;
		cin >> a >> b >> k;

		vector<int> results;

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				int value = i & j;

				results.push_back(value);
			}
		}

		sort(results.begin(), results.end());

		vector<int>::iterator it;
		int count = 0;

		for (it = results.begin(); it != results.end(); it++)
		{
			if (*it < k)
				count++;
			else
				break;
		}

		cout << "Case #" << test << ": " << count << endl;
	}

	return 0;
}

