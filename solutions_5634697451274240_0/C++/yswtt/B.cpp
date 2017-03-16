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
		int res = 0;
		string s;
		cin >> s;
		if (s[s.length() - 1] == '-')
			res = 1;
		for (int i = 0; i + 1 < s.length(); ++i)
			if (s[i] != s[i+1])
				res++;
		cout << "Case #" << t << ": " << res << endl;
	}

    return 0;
}
