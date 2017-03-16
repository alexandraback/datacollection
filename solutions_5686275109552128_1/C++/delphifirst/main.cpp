#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int case_no = 1; case_no <= t; ++case_no)
	{
		cout << "Case #" << case_no << ": ";
		int d;
		cin >> d;
		vector<int> p(d);
		for (int i = 0; i < d; ++i)
			cin >> p[i];

		int result = 1000;

		for (int i = 1000; i >= 1; --i)
		{
			int special = 0;
			for (int size : p)
			{
				special += (size + i - 1) / i - 1;
			}
			result = min(result, i + special);
		}

		cout << result << endl;

	}
}