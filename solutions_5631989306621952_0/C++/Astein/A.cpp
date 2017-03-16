#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int cn = 1; cn <= T; ++cn)
	{
		string S;
		cin >> S;

		string ret = string(1, S[0]);
		for (int i = 1; i < S.size(); ++i)
		{
			string left = S[i] + ret;
			string right = ret + S[i];
			if (left > right)
				ret = left;
			else
				ret = right;
		}
		printf("Case #%d: %s\n", cn, ret.c_str());
	}
}