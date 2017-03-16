#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	string valid[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	string table[10] = {"ZERO", "SIX", "TWO", "SEVEN", "FIVE", "EIGHT", "THREE", "FOUR", "NINE", "ONE"};
	int idx[10] = {0, 6, 2, 7, 5, 8, 3, 4, 9, 1};
	int T;
	cin >> T;
	for (int t=1; t<=T; ++t)
	{
		string S;
		cin >> S;
		int len = S.length();
		string ans;
		for (int i=0; i<10; ++i)
		{
			string dig = table[i];
			bool init = true;
			while (init)
			{
				string tmpS = S;
				for (auto c : dig)
				{
					int pos = tmpS.find(c);
					if (pos == string::npos)
					{
						init = false;
						break;
					}
					else
					{
						tmpS.erase(pos, 1);
					}
				}
				if (init)
				{
					ans.push_back('0' + idx[i]);
					for (auto c : dig)
					{
						int pos = S.find(c);
						S.erase(pos, 1);
					}
				}
			}

		}

		sort(ans.begin(), ans.end());
		int validation = 0;
		for (auto c : ans)
		{
			validation += valid[(int)(c - '0')].length();
		}
		if (len == validation)
		{
			cout << "Case #" << t << ": " << ans << endl;
		}
		else
		{
			cout << "wtf " << t << endl;
		}
	}

	return 0;
}
