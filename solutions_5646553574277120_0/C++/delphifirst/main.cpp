#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
#include <vector>

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

		int result = 0;
		for (;; ++result)
		{
			vector<bool> dp(v + 1);
			dp[0] = true;
			for (int denom : cur_denom)
			{
				for (int i = v; i - denom >= 0; --i)
					if (dp[i - denom])
						dp[i] = true;
			}

			bool finish = true;

			for (int i = 0; i < dp.size(); ++i)
				if (!dp[i])
				{
					finish = false;
					cur_denom.push_back(i);
					break;
				}

			if (finish)
				break;
		}

		cout << result << endl;
	}
}
