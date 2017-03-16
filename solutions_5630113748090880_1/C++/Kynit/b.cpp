#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(void)
{
	int t;
	cin >> t;

	for(int i = 1; i <= t; i++)
	{
		int n;
		cin >> n;

		vector<int> count(2501);
		for(int j = 0; j < n * (2*n - 1); j++)
		{
			int nextInt;
			cin >> nextInt;
			count[nextInt] += 1;
		}

		cout << "Case #" << i << ": ";
		for(int j = 1; j < count.size(); j++)
		{
			if(count[j] % 2 != 0)
			{
				cout << j << " ";
			}
		}

		cout << endl;

	}

	return 0;
}
