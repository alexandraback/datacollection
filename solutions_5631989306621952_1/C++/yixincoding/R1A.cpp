#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int T; cin >> T;
	for (int TT = 1; TT < T+1; TT++)
	{
		string str;
		cin >> str;
		string res = "";
		for (int i = 0; i < str.length(); i++)
		{
			if (i == 0)
			{
				res += str[i];
				continue;
			}
			if (str[i] >= res[0])
			{
				res = str[i] + res;
			}
			else
			{
				res += str[i];
			}
		}
		cout << "Case #"<< TT << ": " << res << endl;
	}
	return 0;

}