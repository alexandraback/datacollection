// Round 1A

#include <iostream>
#include <vector>
#include <string>

using namespace std;

static void HandleCase(const int cse)
{
	string S;
	cin >> S;

	string outStr;

	for (int i = 0; i < S.length(); ++i)
	{
		if (outStr.empty())
			outStr += S[i];
		else
		{
			string left = S[i] + outStr;
			string right = outStr + S[i];
			if (left < right)
				outStr = right;
			else
				outStr = left;
		}
	}

	cout << "Case #" << cse << ": " << outStr << endl;
}


int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
		HandleCase(i + 1);

	return 0;
}


