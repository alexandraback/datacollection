#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		string s, res = "";
		cin >> s;
		res = s[0];
		for (int i = 1; i < s.length(); ++i)
			if (s[i] >= res[0])
				res = s[i] + res;
			else
				res = res + s[i];
		cout << "Case #" << t << ": " << res << endl;
	}

    return 0;
}
