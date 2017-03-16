#include <iostream>
#include <string>
#include <deque>
using namespace std;

string optimal(string S)
{
	// cerr << "Called on " << S << endl;
	if (S.empty())
		return "";

	char maxC = 0;
	int maxPos = -1;
	int maxCount = 0;
	for (int i = 0; i < S.length(); ++i) {
		if (S[i] > maxC) {
			maxC = S[i];
			maxPos = i;
			maxCount = 1;
		} else if (S[i] == maxC)
			++maxCount;
	}

	string result = string(maxCount, maxC);
	result += optimal(S.substr(0, maxPos));
	for (int i = maxPos + 1; i < S.length(); ++i)
		if (S[i] != maxC)
			result += S[i];
	return result;
}

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		string S;
		cin >> S;

		cout << "Case #" << case_num << ": " << optimal(S) << endl;
	}
	return 0;
}
