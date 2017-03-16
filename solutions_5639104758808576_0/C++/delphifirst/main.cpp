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
		int s_max;
		cin >> s_max;
		string s;
		cin >> s;
		int result = 0;
		int au_count = 0;
		for (int i = 0; i <= s_max; ++i)
		{
			int num_k = s[i] - '0';
			result = max(result, i - au_count);
			au_count += num_k;
		}

		cout << result << endl;
	}
}