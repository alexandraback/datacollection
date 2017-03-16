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
		string s;
		cin >> s;

		string ret = string(1, s[0]);

		for(int j = 1; j < s.length(); j++)
		{
			if(s[j] >= ret[0])
				ret = string(1, s[j]) + ret;
			else
				ret = ret + string(1, s[j]);
		}

		cout << "Case #" << i << ": " << ret << endl;
	}

	return 0;
}
