#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
#include <vector>
#include <limits>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int case_count;
	cin >> case_count;
	for (int case_no = 1; case_no <= case_count; ++case_no)
	{
		cout << "Case #" << case_no << ": ";
		int c, d, v;
		cin >> c >> d >> v;
		vector<int> cur_denom(d);
		for (int i = 0; i < d; ++i)
			cin >> cur_denom[i];

		cur_denom.push_back(numeric_limits<int>::max());

		int result = 0;

		for (long long i = 1, j = 0; i <= v;)
		{
			if (i < cur_denom[j])
			{
				++result;
				i = i * (c + 1);
			}
			else
			{
				i += cur_denom[j] * c;
				++j;
			}
		}

		cout << result << endl;
	}
}
